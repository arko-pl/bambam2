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
#include "settingscontroller.hpp"

#include "settings/gamesettings.hpp"
#include "settings/settings_common.hpp"
#include "settings/settingswriter.hpp"
#include "settings/dialog/idataprovidersettings.hpp"
#include "settings/dialog/igeneralsettings.hpp"
#include "settings/dialog/iscalingpolicysettings.hpp"
#include "settings/dialog/settingsdialog.hpp"

#include <QVariant>

SettingsController::SettingsController()
{

}

void SettingsController::openSettingsDialog() const
{
    SettingsDialog settingsDialog;
    auto ret = settingsDialog.exec();
    if (ret == QDialog::Accepted) {
        const IGeneralSettings* generalSettings =
                settingsDialog.getGeneralSettings();
        auto& settings = GameSettings::getInstance();
        if (Q_LIKELY(generalSettings != nullptr)) {
            settings.setGeneralOption(Settings::General::LANGUAGE,
                                      QVariant::fromValue(
                                          generalSettings->getLanguage()));
            settings.setGeneralOption(Settings::General::SELECTED_SCALING_POLICY,
                                      QVariant::fromValue(
                                          generalSettings->getScalingPolicy()));
            settings.setGeneralOption(Settings::General::SELECTED_PROVIDERS,
                                      QVariant::fromValue(
                                          generalSettings->getDataProviders()));
        }
        const IScalingPolicySettings* scalingPolicySettings =
                settingsDialog.getScalingPolicySettings();
        if (Q_LIKELY(scalingPolicySettings != nullptr)) {
            settings.setScalingPolicyOption(
                        Settings::ScalingPolicy::FitToSize::SUBGROUP,
                        Settings::ScalingPolicy::FitToSize::SIZE,
                        scalingPolicySettings->getFixedSize());
        }
        const IDataProviderSettings* dataProviderSettings =
                settingsDialog.getDataProviderSettings();
        if (Q_LIKELY(dataProviderSettings != nullptr)) {
            settings.setDataProvidersOption(
                        Settings::DataProviders::ConfigBased::SUBGROUP,
                        Settings::DataProviders::ConfigBased::RETRIEVAL_POLICY,
                        QVariant::fromValue(
                            dataProviderSettings->getRetrievalPolicy()));
        }
        SettingsWriter writer(settings);
        writer.saveSettings();
    }
}
