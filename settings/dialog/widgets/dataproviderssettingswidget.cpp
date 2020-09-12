/*
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
#include "dataproviderssettingswidget.hpp"

#include <QComboBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QVariant>
#include <QVBoxLayout>

#include "settings/gamesettings.hpp"

class DataProvidersSettingsWidgetImpl {
public:
    friend class DataProvidersSettingsWidget;
    explicit DataProvidersSettingsWidgetImpl() :
        m_settingsGroup(nullptr),
        m_externalProviderGroup(nullptr),
        m_retrievalPolicyLabel(nullptr),
        m_retrievalPolicySelection(nullptr)
    {}
private:
    QGroupBox* m_settingsGroup;
    QGroupBox* m_externalProviderGroup;
    QLabel* m_retrievalPolicyLabel;
    QComboBox* m_retrievalPolicySelection;
};

DataProvidersSettingsWidget::DataProvidersSettingsWidget(QWidget *parent) :
    QWidget(parent)
{
    pImpl = std::make_unique<DataProvidersSettingsWidgetImpl>();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QVBoxLayout* settingsGroupLayout = new QVBoxLayout;
    QHBoxLayout* policyLayout = new QHBoxLayout;

    pImpl->m_settingsGroup = new QGroupBox(tr("Data Providers Settings"));
    pImpl->m_externalProviderGroup = new QGroupBox(
                tr("External Data Provider Settings"));
    pImpl->m_retrievalPolicyLabel = new QLabel("Retrieval policy");
    pImpl->m_retrievalPolicySelection = new QComboBox;
    setUpComboBox(*pImpl->m_retrievalPolicySelection);

    policyLayout->addWidget(pImpl->m_retrievalPolicyLabel);
    policyLayout->addWidget(pImpl->m_retrievalPolicySelection);
    policyLayout->addStretch();

    pImpl->m_externalProviderGroup->setLayout(policyLayout);
    settingsGroupLayout->addWidget(pImpl->m_externalProviderGroup);
    pImpl->m_settingsGroup->setLayout(settingsGroupLayout);
    mainLayout->addWidget(pImpl->m_settingsGroup);

    update();

    setLayout(mainLayout);
}

DataProvidersSettingsWidget::~DataProvidersSettingsWidget() = default;

void DataProvidersSettingsWidget::update()
{
    using namespace Settings::DataProviders;
    const auto& settings = GameSettings::getInstance();
    const auto retrievalPolicy = settings.getDataProvidersOption(
                ConfigBased::SUBGROUP, ConfigBased::RETRIEVAL_POLICY);
    int index = pImpl->m_retrievalPolicySelection->findData(retrievalPolicy);
    Q_ASSERT(index != -1);
    pImpl->m_retrievalPolicySelection->setCurrentIndex(index);
}

Settings::DataProviders::ConfigBased::RetrievalPolicy
DataProvidersSettingsWidget::getRetrievalPolicy() const
{
    return qvariant_cast<Settings::DataProviders::ConfigBased::RetrievalPolicy>(
                pImpl->m_retrievalPolicySelection->currentData());
}

void DataProvidersSettingsWidget::setUpComboBox(QComboBox& comboBox)
{
    using namespace Settings::DataProviders::ConfigBased;

    comboBox.addItem(tr("Random"),
                     QVariant::fromValue(RetrievalPolicy::Random));
    comboBox.addItem(tr("Character based"),
                     QVariant::fromValue(RetrievalPolicy::CharBased));

}
