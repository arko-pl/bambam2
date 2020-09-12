/*
 * Copyright (C) 2018  Michał Walenciak <Kicer86@gmail.com>
 * Copyright (C) 2020  Arkadiusz Bubała <arek2407066@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOVE_WIDGET_HPP
#define MOVE_WIDGET_HPP

#include <memory>
#include <unordered_map>
#include <QListView>
#include <QWidget>

class QAbstractItemModel;
class QAbstractItemView;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;

struct IMovePolicy
{
    virtual ~IMovePolicy() = default;

    struct SourceData
    {
        QAbstractItemModel* model;
        QItemSelection selection;
    };

    virtual bool isMoveAllowed(const SourceData& from,
                                 const QAbstractItemModel* to) const = 0;
};

class MoveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MoveWidget(QWidget* parent = nullptr);
    MoveWidget(const MoveWidget &) = delete;
    MoveWidget& operator=(const MoveWidget &) = delete;

    void addDonor(const QString& name, QAbstractItemModel* src);
    void addRecipient(const QString& name, QAbstractItemModel* dst);

    void set(IMovePolicy *);

    enum class SourceType { Donor, Recipient };

    ~MoveWidget() = default;
signals:
    void contentChanged();
protected:
    bool eventFilter(QObject *, QEvent *);

private:
    using View = QListView;
    using SourceMapping = std::unordered_map<View*, SourceType>;

    enum class Direction { FromDonorToRecipient,
                           FromRecipientToDonor };

    View* createView(QAbstractItemModel *);
    void addSource(const QString& name, QAbstractItemModel* model,
                   SourceType type);
    void applySelection(SourceMapping::const_iterator &) const;
    void selectView(View*);
    void move(Direction);
    void updateButtons();

    SourceMapping m_sources;
    QPushButton *m_buttonFromDonorToRecipient;
    QPushButton *m_buttonFromRecipientToDonor;
    View *m_selectedDonor;
    View *m_selectedRecipient;
    QVBoxLayout *m_donorLayout;
    QVBoxLayout *m_recipientLayout;
    QVBoxLayout *m_buttonLayout;
    QHBoxLayout *m_mainLayout;
    IMovePolicy *m_movePolicy;
};

#endif // MOVE_WIDGET_HPP
