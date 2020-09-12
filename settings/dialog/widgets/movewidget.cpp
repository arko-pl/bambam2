#include "movewidget.hpp"

#include <functional>

#include <QLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>


MoveWidget::MoveWidget(QWidget *parent) :
    QWidget(parent),
    m_sources(),
    m_buttonFromDonorToRecipient(nullptr),
    m_buttonFromRecipientToDonor(nullptr),
    m_selectedDonor(nullptr),
    m_selectedRecipient(nullptr),
    m_donorLayout(nullptr),
    m_recipientLayout(nullptr),
    m_buttonLayout(nullptr),
    m_mainLayout(nullptr),
    m_movePolicy(nullptr)
{
    m_donorLayout = new QVBoxLayout;
    m_buttonLayout = new QVBoxLayout;
    m_recipientLayout = new QVBoxLayout;
    m_mainLayout = new QHBoxLayout;

    m_buttonFromDonorToRecipient = new QPushButton(tr("->"));
    m_buttonFromRecipientToDonor = new QPushButton(tr("<-"));
    m_buttonFromDonorToRecipient->setEnabled(false);
    m_buttonFromRecipientToDonor->setEnabled(false);

    m_buttonLayout->addStretch();
    m_buttonLayout->addWidget(m_buttonFromDonorToRecipient);
    m_buttonLayout->addWidget(m_buttonFromRecipientToDonor);
    m_buttonLayout->addStretch();

    connect(m_buttonFromDonorToRecipient,
            &QPushButton::pressed,
            std::bind(&MoveWidget::move, this,
                      Direction::FromDonorToRecipient));

    connect(m_buttonFromRecipientToDonor,
            &QPushButton::pressed,
            std::bind(&MoveWidget::move, this,
                      Direction::FromRecipientToDonor));

    m_mainLayout->addLayout(m_donorLayout);
    m_mainLayout->addLayout(m_buttonLayout);
    m_mainLayout->addLayout(m_recipientLayout);

    setLayout(m_mainLayout);
}

void MoveWidget::addDonor(const QString& name, QAbstractItemModel* src)
{
    addSource(name, src, SourceType::Donor);
}

void MoveWidget::addRecipient(const QString& name, QAbstractItemModel* dst)
{
    addSource(name, dst, SourceType::Recipient);
}

void MoveWidget::addSource(const QString& name,
                           QAbstractItemModel* model,
                           SourceType type)
{
    QLayout *layout;
    View* selectedView;
    View *view = this->createView(model);
    QLabel *label = new QLabel(name);

    if (type == SourceType::Donor) {
        layout = m_donorLayout;
        selectedView = m_selectedDonor;
    } else {
        layout = m_recipientLayout;
        selectedView = m_selectedRecipient;
    }

    layout->addWidget(label);
    layout->addWidget(view);

    bool inserted = m_sources.insert(std::make_pair(view, type)).second;

    Q_ASSERT(inserted == true);

    if (selectedView == nullptr)
        selectView(view);
}

void MoveWidget::set(IMovePolicy* policy)
{
    m_movePolicy = policy;
}

MoveWidget::View* MoveWidget::createView(QAbstractItemModel* model)
{
    View* view = new View;
    view->setModel(model);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    view->viewport()->installEventFilter(this);

    connect(view->selectionModel(),
            &QItemSelectionModel::selectionChanged,
            this,
            &MoveWidget::updateButtons);

    return view;
}

void MoveWidget::applySelection(SourceMapping::const_iterator& iterator) const
{
    QAbstractItemView* view = iterator->first;
    SourceType type = iterator->second;

    view->setFrameStyle(QFrame::Box);
    view->setLineWidth(2);
    for (auto &item : m_sources) {
        if (item.second == type && item.first != view) {
            QAbstractItemView* other = item.first;
            other->setFrameStyle(QFrame::StyledPanel);
            other->setLineWidth(1);
        }
    }
}

void MoveWidget::selectView(View* source)
{
    SourceMapping::const_iterator iterator = m_sources.find(source);
    Q_ASSERT(iterator != m_sources.cend());

    applySelection(iterator);

    if (iterator->second == SourceType::Donor)
        m_selectedDonor = source;
    else
        m_selectedRecipient = source;
}

void MoveWidget::move(Direction dir)
{
    QAbstractItemView *src;
    QAbstractItemView *dst;
    std::vector<QPersistentModelIndex> rows_to_delete;

    if (dir == Direction::FromDonorToRecipient) {
        src = m_selectedDonor;
        dst = m_selectedRecipient;
    } else {
        dst = m_selectedDonor;
        src = m_selectedRecipient;
    }

    QItemSelectionModel *selectionModel = src->selectionModel();
    QAbstractItemModel *source = src->model();
    QAbstractItemModel *destination = dst->model();

    for (const auto& elem : selectionModel->selectedIndexes())
    {
        if (!elem.isValid())
            continue;

        Q_ASSERT(elem.column() == 0);

        auto item_data = source->itemData(elem);

        rows_to_delete.emplace_back(elem);

        const int destination_rows = destination->rowCount();
        bool i = destination->insertRow(destination_rows);

        if (destination->columnCount() == 0)
            i = destination->insertColumn(0);

        const QModelIndex destination_idx =
                destination->index(destination_rows, 0);
        destination->setItemData(destination_idx, item_data);
    }

    for (const auto& elem : rows_to_delete) {
        source->removeRow(elem.row());
    }

    updateButtons();
    emit contentChanged();
}

bool MoveWidget::eventFilter(QObject *obj,
                                 QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QObject* view = obj->parent();

        for (auto& mapping : m_sources) {
            if (mapping.first == view) {
                selectView(mapping.first);
                updateButtons();
                return QObject::eventFilter(obj, event);
            }
        }
    }
    return QObject::eventFilter(obj, event);
}

void MoveWidget::updateButtons()
{
    const View* donor = m_selectedDonor;
    const View* recipient = m_selectedRecipient;

    bool is_recipient_allowed;
    bool is_donor_allowed;
    bool recipient_has_selection;
    bool donor_has_selection;

    if (donor) {
        const auto selection = donor->selectionModel()->selection();
        if (m_movePolicy != nullptr) {
            IMovePolicy::SourceData data = { donor->model(), selection };

            is_recipient_allowed =
                    m_movePolicy->isMoveAllowed(data, recipient->model());
        } else {
            is_recipient_allowed = true;
        }
        donor_has_selection = !selection.isEmpty();
    } else {
        is_recipient_allowed = donor_has_selection = false;
    }

    if (recipient) {
        const auto selection = recipient->selectionModel()->selection();
        if (m_movePolicy != nullptr) {
            IMovePolicy::SourceData data = { recipient->model(), selection };
            is_donor_allowed =
                    m_movePolicy->isMoveAllowed(data,
                                                donor->model());
        } else {
            is_donor_allowed = true;
        }

        recipient_has_selection = !selection.isEmpty();
    } else {
        is_donor_allowed = recipient_has_selection = false;
    }

    m_buttonFromRecipientToDonor->setEnabled(is_donor_allowed &&
                                                recipient_has_selection);
    m_buttonFromDonorToRecipient->setEnabled(is_recipient_allowed &&
                                                donor_has_selection);
}
