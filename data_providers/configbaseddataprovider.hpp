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
#ifndef CONFIGBASEDDATAPROVIDER_HPP
#define CONFIGBASEDDATAPROVIDER_HPP

#include "idataprovider.hpp"
#include "pimpl.hpp"

class ConfigBasedDataProviderImpl;

/**
 * @brief Configuration Based Data Provider
 *
 * Class responsible for providing game data read from XML configuration files.
 */
class ConfigBasedDataProvider : public IDataProvider
{
public:
    /**
     * @brief The constructor.
     *
     */
    ConfigBasedDataProvider();
    /**
     * @brief The destructor.
     *
     */
    ~ConfigBasedDataProvider();

    // IDataProvider interface
public:
    /**
     * @brief Get IGameElementData for @p key.
     *
     * @param key String key representation.
     * @return IGameElementData.
     */
    IGameElementData* getDataElement(const QString& key) override;
private:
    ConfigBasedDataProvider(const ConfigBasedDataProvider&) = delete;
    ConfigBasedDataProvider& operator=(const ConfigBasedDataProvider&) = delete;

    PImpl<ConfigBasedDataProviderImpl> pImpl; /**< Pointer to the
                                                   implementation. */
};

#endif // CONFIGBASEDDATAPROVIDER_HPP
