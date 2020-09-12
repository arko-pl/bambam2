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
#ifndef SETTINGSWRITER_HPP
#define SETTINGSWRITER_HPP

#include "isettingswriter.hpp"

class GameSettings;
class QSettings;

/**
 * @brief The SettingsWriter class
 * This class is responsible for writing settings from model
 * to the settings file.
 */

class SettingsWriter : public ISettingsWriter
{
public:
    explicit SettingsWriter(const GameSettings&);
    /**
     * @brief Save settings to file
     */
    void saveSettings() const override;

private:
    /**
     * @brief Write data provider options
     * @param settings Pointer to QSettings instance
     */
    void writeDataProvidersOptions(QSettings& settings) const;
    /**
     * @brief Write scaling policy options
     * @param settings Pointer to QSettings instance
     */
    void writeScalingPolicyOptions(QSettings& settings) const;
    /**
     * @brief Write general options
     * @param settings Pointer to QSettings instance
     */
    void writeGeneralOptions(QSettings& settings) const;

    const GameSettings& m_settings; /**< Reference to GameSettings class */
};

#endif // SETTINGSWRITER_HPP
