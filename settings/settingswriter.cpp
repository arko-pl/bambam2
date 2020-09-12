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
#include "settingswriter.hpp"

#include <QSettings>
#include <QSize>

#include "gamesettings.hpp"
#include "settings_common.hpp"
#include "settingshelpers.hpp"

SettingsWriter::SettingsWriter(const GameSettings& settings) :
    m_settings(settings) {
}
// FIXME: map names to numerical IDs
void SettingsWriter::writeDataProvidersOptions(QSettings& settings) const {
    using namespace Settings;
    settings.beginGroup(DATA_PROVIDERS_OPTIONS);
    {
        using namespace DataProviders;
        const auto dataProvidersOptions =
                m_settings.getOption(Options::DataProviders).toHash();

        const auto it =
                dataProvidersOptions.find(ConfigBased::SUBGROUP);
        const QString retrievalPolicyOpt = ConfigBased::SUBGROUP + "/" +
                ConfigBased::RETRIEVAL_POLICY;

        // use the default value if real can't be obtained
        QString retrievalPolicy;
        if (Q_UNLIKELY(it != dataProvidersOptions.cend())) {
            /* BEGIN: Configuration based options */
            const auto configBasedOptions = it->toHash();
            const auto it = configBasedOptions.find(
                        ConfigBased::RETRIEVAL_POLICY);

            if (Q_UNLIKELY(it != configBasedOptions.cend())) {
                retrievalPolicy = SettingsHelpers::fromRetrievalPolicy(
                            qvariant_cast<ConfigBased::RetrievalPolicy>(*it));
            }
            /* END: Configuration based options */
        }
        if (Q_UNLIKELY(retrievalPolicy.isEmpty())) {
            SettingsHelpers::fromRetrievalPolicy(Default::RetrievalPolicy);
        }
        settings.setValue(retrievalPolicyOpt, retrievalPolicy);
    }
    settings.endGroup();
}

void SettingsWriter::writeScalingPolicyOptions(QSettings& settings) const {
    using namespace Settings;
    settings.beginGroup(SCALING_POLICY_OPTIONS);
    {
        using namespace ScalingPolicy;
        const auto scalingProvidersOptions =
                m_settings.getOption(Options::ScalingPolicy).toHash();
        const auto it =
            scalingProvidersOptions.find(FitToSize::SUBGROUP);

        // set size to default if it can't be obtained
        QSize size = Default::Size;

        if (Q_UNLIKELY(it != scalingProvidersOptions.cend())) {
            /* BEGIN: Fit to size policy options */
            const auto fitToSizeOptions = it->toHash();
            const auto it = fitToSizeOptions.find(FitToSize::SIZE);

            if (Q_UNLIKELY(it != fitToSizeOptions.cend())) {
                size = it->toSize();
            }
            /* END: Fit to size policy options */
        }

        settings.setValue(Settings::ScalingPolicy::FitToSize::SUBGROUP +
                          "/" + Settings::ScalingPolicy::FitToSize::SIZE,
                          size);
    }
    settings.endGroup();
}

void SettingsWriter::writeGeneralOptions(QSettings& settings) const {
    using namespace  Settings;

    settings.beginGroup(GENERAL_OPTIONS);
    const auto generalOptions =
            m_settings.getOption(Options::General).toHash();

    QString language;
    auto it = generalOptions.find(General::LANGUAGE);
    if (Q_UNLIKELY(it != generalOptions.cend())) {
        language = SettingsHelpers::fromLanguage(
                    qvariant_cast<General::Language>(*it));
    }
    if (Q_UNLIKELY(language.isEmpty())) {
        language = SettingsHelpers::fromLanguage(Default::Language);
    }
    settings.setValue(General::LANGUAGE, language);

    QList<DataProviders::Type> selectedProviders;
    /*= {DataProvider::ConfigBasedProvider,
                                     DataProvider::TextProvider};*/
    it = generalOptions.find(General::SELECTED_PROVIDERS);
    if (Q_UNLIKELY(it != generalOptions.cend())) {
        selectedProviders = qvariant_cast<QList<DataProviders::Type>>(*it);
    }
    if (Q_UNLIKELY(selectedProviders.isEmpty())) {
        selectedProviders = Default::DataProviders;
    }

    QStringList selectedProvidersStr;
    for (const auto& provider : selectedProviders) {
        selectedProvidersStr.push_back(
                    SettingsHelpers::fromDataProviderType(provider)
                    );
    }

    settings.setValue(Settings::General::SELECTED_PROVIDERS,
                      selectedProvidersStr);

    QString scalingPolicy;
    it = generalOptions.find(Settings::General::SELECTED_SCALING_POLICY);
    if (Q_UNLIKELY(it != generalOptions.cend())) {
        scalingPolicy = SettingsHelpers::fromScalingPolicyType(
                    qvariant_cast<ScalingPolicy::Type>(*it));
    }
    if (Q_UNLIKELY(scalingPolicy.isEmpty())) {
        scalingPolicy = SettingsHelpers::fromScalingPolicyType(
                    Default::ScalingPolicy);
    }
    settings.setValue(General::SELECTED_SCALING_POLICY,
                      scalingPolicy);
    settings.endGroup();
}

void SettingsWriter::saveSettings() const {
    QSettings settings(QSettings::UserScope, Settings::Default::Name,
                       Settings::Default::Name);

    writeDataProvidersOptions(settings);
    writeScalingPolicyOptions(settings);
    writeGeneralOptions(settings);
}
