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
#ifndef IGENERALSETTINGS_HPP
#define IGENERALSETTINGS_HPP

template<typename T>
class QList;

namespace Settings {
namespace General {
enum class Language;
}
namespace ScalingPolicy {
enum class Type;
}
namespace DataProviders {
enum class Type;
}
}

/**
 * @brief General Settings Interface
 */
class IGeneralSettings {
public:
    ~IGeneralSettings() = default;

    /**
     * @brief Get language for the game items
     * @return Lanuage
     */
    virtual Settings::General::Language getLanguage() const = 0;
    /**
     * @brief Get scaling policy for the game items
     * @return  Scaling policy
     */
    virtual Settings::ScalingPolicy::Type getScalingPolicy() const = 0;
    /**
     * @brief Get data providers for the game
     * @return Data providers
     */
    virtual QList<Settings::DataProviders::Type> getDataProviders() const = 0;
};

#endif // IGENERALSETTINGS_HPP
