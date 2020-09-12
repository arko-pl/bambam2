#include "generalsettingswidget.hpp"
#include <QGroupBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QStandardItemModel>
#include <QHash>

#include "movewidget.hpp"
#include "settings/gamesettings.hpp"

class GeneralSettingsWidgetImpl {
public:
    friend class GeneralSettingsWidget;
    explicit GeneralSettingsWidgetImpl() :
        m_generalSettingsGroup(nullptr),
        m_languageLabel(nullptr),
        m_languageComboBox(nullptr),
        m_dataProvidersSelection(nullptr),
        m_scalingPolicyLabel(nullptr),
        m_scalingPolicyComboBox(nullptr),
        m_selectedProviders(nullptr),
        m_availableProviders(nullptr)
    {}
private:
    QGroupBox* m_generalSettingsGroup;
    QLabel* m_languageLabel;
    QComboBox* m_languageComboBox;
    MoveWidget* m_dataProvidersSelection;
    QLabel* m_scalingPolicyLabel;
    QComboBox* m_scalingPolicyComboBox;

    QStandardItemModel* m_selectedProviders;
    QStandardItemModel* m_availableProviders;
};

GeneralSettingsWidget::GeneralSettingsWidget(QWidget *parent) : QWidget(parent)
{
    pImpl = std::make_unique<GeneralSettingsWidgetImpl>();

    QVBoxLayout* mainLayout = new QVBoxLayout;
    QVBoxLayout* groupLayout = new QVBoxLayout;
    QHBoxLayout* languageLayout = new QHBoxLayout;
    QHBoxLayout* scalingPolicyLayout = new QHBoxLayout;

    pImpl->m_generalSettingsGroup = new QGroupBox(tr("General settings"));

    pImpl->m_languageLabel = new QLabel(tr("Language:"));
    pImpl->m_languageComboBox = new QComboBox;
    pImpl->m_scalingPolicyLabel = new QLabel(tr("Scaling policy:"));
    pImpl->m_scalingPolicyComboBox = new QComboBox;
    pImpl->m_dataProvidersSelection = new MoveWidget;

    fillLanguages();
    fillScalingPolicies();
    fillDataProviders();

    languageLayout->addWidget(pImpl->m_languageLabel);
    languageLayout->addWidget(pImpl->m_languageComboBox);
    scalingPolicyLayout->addWidget(pImpl->m_scalingPolicyLabel);
    scalingPolicyLayout->addWidget(pImpl->m_scalingPolicyComboBox);
    groupLayout->addLayout(languageLayout);
    groupLayout->addLayout(scalingPolicyLayout);
    groupLayout->addWidget(pImpl->m_dataProvidersSelection);

    pImpl->m_generalSettingsGroup->setLayout(groupLayout);
    mainLayout->addWidget(pImpl->m_generalSettingsGroup);
    this->setLayout(mainLayout);
    update();
}

GeneralSettingsWidget::~GeneralSettingsWidget() = default;

void GeneralSettingsWidget::update()
{
    const auto& settings = GameSettings::getInstance();
    const auto language  =
            settings.getGeneralOption(Settings::General::LANGUAGE);
    int index = pImpl->m_languageComboBox->findData(language);
    Q_ASSERT(index != -1);
    pImpl->m_languageComboBox->setCurrentIndex(index);
    const auto scalingPolicy = settings.getGeneralOption(
                Settings::General::SELECTED_SCALING_POLICY);
    index = pImpl->m_scalingPolicyComboBox->findData(scalingPolicy);
    Q_ASSERT(index != -1);
    pImpl->m_scalingPolicyComboBox->setCurrentIndex(index);

    const auto selectedProviders =
            qvariant_cast<QList<Settings::DataProviders::Type>>(
                settings.getGeneralOption(
                    Settings::General::SELECTED_PROVIDERS));
    for (const auto& provider : selectedProviders) {
        QStandardItem* item = getItemFromAvailable(provider);
        Q_ASSERT(item != nullptr);
        if (Q_LIKELY(item != nullptr)) {
            pImpl->m_selectedProviders->appendRow(item);
        }
    }
}

Settings::General::Language GeneralSettingsWidget::getLanguage() const
{
    return qvariant_cast<Settings::General::Language>(
                pImpl->m_languageComboBox->currentData());
}

Settings::ScalingPolicy::Type GeneralSettingsWidget::getScalingPolicy() const
{
    return qvariant_cast<Settings::ScalingPolicy::Type>(
                pImpl->m_scalingPolicyComboBox->currentData());
}

QList<Settings::DataProviders::Type>
GeneralSettingsWidget::getDataProviders() const
{
    QList<Settings::DataProviders::Type> result;
    for (int row = 0; row < pImpl->m_selectedProviders->rowCount(); ++row)  {
        auto* item = pImpl->m_selectedProviders->item(row, 0);
        if (Q_LIKELY(item != nullptr)) {
            result << qvariant_cast<Settings::DataProviders::Type>(
                          item->data());
        }
    }
    return result;
}

void GeneralSettingsWidget::fillLanguages()
{
    pImpl->m_languageComboBox->addItem(
                tr("English"),
                QVariant::fromValue(Settings::General::Language::English));
    pImpl->m_languageComboBox->addItem(
                tr("Polish"),
                QVariant::fromValue(Settings::General::Language::Polish));
}

void GeneralSettingsWidget::fillScalingPolicies()
{
    pImpl->m_scalingPolicyComboBox->addItem(
                tr("No scaling"),
                QVariant::fromValue(Settings::ScalingPolicy::Type::NoScaling));
    pImpl->m_scalingPolicyComboBox->addItem(
                tr("Fit to size"),
                QVariant::fromValue(Settings::ScalingPolicy::Type::FitToSize));
}

void GeneralSettingsWidget::fillDataProviders()
{
    pImpl->m_availableProviders = new QStandardItemModel;
    pImpl->m_selectedProviders = new QStandardItemModel;

    insertProvider(tr("External data"),
                   Settings::DataProviders::Type::ConfigBased);
    insertProvider(tr("Text"),
                   Settings::DataProviders::Type::Text);

    pImpl->m_dataProvidersSelection->addDonor(tr("Available providers"),
                                              pImpl->m_availableProviders);
    pImpl->m_dataProvidersSelection->addRecipient(tr("Selected providers"),
                                                  pImpl->m_selectedProviders);
}

void GeneralSettingsWidget::insertProvider(const QString& name,
                                           Settings::DataProviders::Type type)
{
    QStandardItem* provider = new QStandardItem;
    provider->setText(name);
    provider->setData(QVariant::fromValue(type));
    pImpl->m_availableProviders->appendRow(provider);
}

QStandardItem* GeneralSettingsWidget::getItemFromAvailable(
        Settings::DataProviders::Type provider)
{
    for (int row = 0; row < pImpl->m_availableProviders->rowCount(); ++row)  {
        auto* item = pImpl->m_availableProviders->item(row, 0);
        if (Q_LIKELY(item != nullptr)) {
            if (qvariant_cast<Settings::DataProviders::Type>(item->data()) ==
                    provider) {
                auto* item = pImpl->m_availableProviders->takeItem(row);
                pImpl->m_availableProviders->removeRow(row);
                return item;
            }
        }
    }
    return nullptr;
}
