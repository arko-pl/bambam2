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
#ifndef IDATAPROVIDERSETTINGS_HPP
#define IDATAPROVIDERSETTINGS_HPP

namespace Settings {
namespace DataProviders {
namespace ConfigBased {
enum class RetrievalPolicy;
}
}
}

/**
 * @brief The Data Provider Settings interface
 */

class IDataProviderSettings {
public:
    ~IDataProviderSettings() = default;

    /**
     * @brief Get retrieval policy for external data provider
     * @return Retrieval policy
     */
    virtual Settings::DataProviders::ConfigBased::RetrievalPolicy
    getRetrievalPolicy() const = 0;

};

#endif // IDATAPROVIDERSETTINGS_HPP
