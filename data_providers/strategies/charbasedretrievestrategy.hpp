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
#ifndef CHARBASEDRETRIEVESTRATEGY_HPP
#define CHARBASEDRETRIEVESTRATEGY_HPP

#include "iretrievestrategy.hpp"
#include "pimpl.hpp"
#include "typedefs.hpp"

class CharBasedRetrieveStrategyImpl;

/**
 * @brief Character Based Retrieve Strategy.
 *
 * Class responsible for extracting element from GameElementMap according
 * to the key pressed on the keyboard.
 */
class CharBasedRetrieveStrategy : public IRetrieveStrategy
{
public:
    /**
     * @brief The constructor.
     *
     * @param elements mapping with starting character as key and
     * IGameElementData pointer as value.
     */
    CharBasedRetrieveStrategy(const GameElementMap&);
    /**
     * @brief The destructor.
     *
     */
    ~CharBasedRetrieveStrategy();

    // IRetrieveStrategy interface
    /**
     * @brief Get IGameElementData pointer.
     *
     * Returns the IGameElementData from elements map in following manner:
     * Get values from GameElementMap that starts with the same character
     * as key pressed. If any exist return one pointer selected randomly.
     *
     * @param key String representation of pressed key.
     * @return IGameElementData
     */
    IGameElementData* getElement(const QString&) const override;
private:
    CharBasedRetrieveStrategy(const CharBasedRetrieveStrategy&) = delete;
    CharBasedRetrieveStrategy& operator=(
            const CharBasedRetrieveStrategy&) = delete;

    PImpl<CharBasedRetrieveStrategyImpl> pImpl; /**< Pointer to the
                                                implementation.*/
};

#endif // CHARBASEDRETRIEVESTRATEGY_HPP
