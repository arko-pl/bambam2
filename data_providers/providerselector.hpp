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
#ifndef PROVIDERSELECTOR_HPP
#define PROVIDERSELECTOR_HPP

#include "pimpl.hpp"
#include "idataprovider.hpp"

class QString;
class IGameElementData;
class ProviderSelectorImpl;

// FIXME: provider selector should return provider that can handle specific
// keypress, itroduce architecture that will support that
/**
 * @brief Data Provider Selector.
 *
 */
class ProviderSelector : public IDataProvider
{
public:
    /**
     * @brief The constructor.
     *
     */
    ProviderSelector();
    /**
     * @brief The destructor.
     *
     */
    ~ProviderSelector();
    IGameElementData* getDataElement(const QString& key) override;
private:
    ProviderSelector(const ProviderSelector&) = delete;
    ProviderSelector& operator=(const ProviderSelector&) = delete;
    /**
     * @brief Build data providers list.
     *
     * Allocate needed providers and add them to the list.
     */
    void buildProvidersList();

    PImpl<ProviderSelectorImpl> pImpl; /**< Pointer to the implementation. */

};

#endif // PROVIDERSELECTOR_HPP
