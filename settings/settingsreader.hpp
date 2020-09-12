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
#ifndef SETTINGSREADER_HPP
#define SETTINGSREADER_HPP

#include "isettingsreader.hpp"

class GameSettings;
class QSettings;

/**
 * @brief The SettingsReader class
 * This class is responsible for reading settings from file
 * and filling the GameSettings model.
 */
class SettingsReader : public ISettingsReader
{
public:
    explicit SettingsReader(GameSettings&);

    /**
     * @brief Read settings from file and fill the GameSettings model.
     * @return true if read is successfull, false otherwise
     */
    bool readSettings() override;
private:
    /**
     * @brief Read data provider options
     * @param settings Pointer to QSettings instance
     */
    void readDataProvidersOptions(QSettings& settings);
    /**
     * @brief Read scaling policy options
     * @param settings Pointer to QSettings instance
     */
    void readScalingPolicyOptions(QSettings& settings);
    /**
     * @brief Read general options
     * @param settings Pointer to QSettings instance
     */
    void readGeneralOptions(QSettings& settings);

    SettingsReader(const SettingsReader&) = delete;
    SettingsReader& operator=(const SettingsReader&) = delete;

    GameSettings& m_settings; /**< Reference to GameSettings class */
};

#endif // SETTINGSREADER_HPP
