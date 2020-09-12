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
#include "settingsreader.hpp"

#include <QHash>
#include <QSettings>
#include <QSize>
#include <QString>
#include <QVariant>

#include "gamesettings.hpp"
#include "iscalingpolicy.hpp"
#include "settings_common.hpp"
#include "settingshelpers.hpp"
#include "data_providers/graphics/policies/scalingpolicy_common.hpp"

SettingsReader::SettingsReader(GameSettings& settings) :
    m_settings(settings) {
}

void SettingsReader::readDataProvidersOptions(QSettings& settings) {
    using namespace Settings;
    QHash<QString, QVariant> dataProvidersOptions;
    settings.beginGroup(DATA_PROVIDERS_OPTIONS);
    {
        using namespace DataProviders;
        /* BEGIN: Configuration based subgroup */
        auto retrievalPolicy = SettingsHelpers::toRetrievalPolicy(
                    settings.value(ConfigBased::SUBGROUP + "/" +
                                   ConfigBased::RETRIEVAL_POLICY).toString());
        QHash<QString, QVariant> options =
            {{ ConfigBased::RETRIEVAL_POLICY,
               QVariant::fromValue(retrievalPolicy) }};
        dataProvidersOptions.insert(
                    DataProviders::ConfigBased::SUBGROUP,
                    options);
        /* END: Configuration based subgroup */
    }
    settings.endGroup();
    m_settings.m_settingsMap.insert(Options::DataProviders,
                                    dataProvidersOptions);
}

void SettingsReader::readScalingPolicyOptions(QSettings& settings)
{
    using namespace Settings;
    QHash<QString, QVariant> scalingPolicyOptions;
    settings.beginGroup(SCALING_POLICY_OPTIONS);
    {
        using namespace Settings::ScalingPolicy;
        /* BEGIN: Fit to size policy subgroup */
        QSize size(settings.value(FitToSize::SUBGROUP + "/" + FitToSize::SIZE,
                                  Default::Size).toSize());
        QHash<QString, QVariant> options =
            {{ Settings::ScalingPolicy::FitToSize::SIZE, size }};
        scalingPolicyOptions.insert(
                    Settings::ScalingPolicy::FitToSize::SUBGROUP,
                    options);
        /* BEGIN: End fit to size policy subgroup */
    }
    settings.endGroup();
    m_settings.m_settingsMap.insert(Options::ScalingPolicy,
                                    scalingPolicyOptions);
}

void SettingsReader::readGeneralOptions(QSettings& settings) {
    using namespace Settings;
    settings.beginGroup(GENERAL_OPTIONS);
    auto language = SettingsHelpers::toLanguage(
                settings.value(General::LANGUAGE).toString());

    const QStringList& providersList(
                settings.value(General::SELECTED_PROVIDERS).toStringList());
    QList<DataProviders::Type> providers;
    if (providersList.empty()) {
        providers = Default::DataProviders;
    } else {
        for (const auto& provider : providersList) {
            providers.push_back(SettingsHelpers::toDataProviderType(provider));
        }
    }

    auto scalingPolicy = SettingsHelpers::toScalingPolicyType(
                settings.value(General::SELECTED_SCALING_POLICY).toString());
    QHash<QString, QVariant> options = {
        { General::LANGUAGE, QVariant::fromValue(language) },
        { General::SELECTED_PROVIDERS, QVariant::fromValue(providers) },
        { General::SELECTED_SCALING_POLICY,
          QVariant::fromValue(scalingPolicy) },
    };
    m_settings.m_settingsMap.insert(Options::General, options);
    settings.endGroup();
}

bool SettingsReader::readSettings() {
    QSettings settings(QSettings::UserScope, Settings::Default::Name,
                       Settings::Default::Name);

    readDataProvidersOptions(settings);
    readScalingPolicyOptions(settings);
    readGeneralOptions(settings);

    return true;
}
