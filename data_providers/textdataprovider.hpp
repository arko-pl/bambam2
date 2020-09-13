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
#ifndef TEXTDATAPROVIDER_HPP
#define TEXTDATAPROVIDER_HPP

#include "idataprovider.hpp"
#include "pimpl.hpp"

class TextDataProviderImpl;

/**
 * @brief Text Data Provider.
 *
 * Provides simple data structure with text as a name.
 */
class TextDataProvider : public IDataProvider
{
public:
    /**
     * @brief The constructor.
     *
     */
    TextDataProvider();

    // IDataProvider interface
    /**
     * @brief Get IGameElementData for a given @p key.
     *
     * Sets game data element name to @p key and returns pointer to this data.
     *
     * @param key String key representation.
     * @return IGameElementData.
     */
    IGameElementData* getDataElement(const QString &key) override;
private:
    TextDataProvider(const TextDataProvider&) = delete;
    TextDataProvider& operator=(const TextDataProvider&) = delete;

    PImpl<TextDataProviderImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // TEXTDATAPROVIDER_HPP
