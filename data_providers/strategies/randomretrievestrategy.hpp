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
#ifndef RANDOMRETRIEVESTRATEGY_HPP
#define RANDOMRETRIEVESTRATEGY_HPP

#include "iretrievestrategy.hpp"
#include "pimpl.hpp"
#include "typedefs.hpp"

class RandomRetrieveStrategyImpl;

/**
 * @brief Random Value Based Retrieve Strategy.
 *
 * Class responsible for extracting element from GameElementMap randomly.
 */
class RandomRetrieveStrategy : public IRetrieveStrategy
{
public:
    /**
     * @brief The constructor.
     *
     * @param elements mapping with starting character as key and
     * IGameElementData pointer as value.
     */
    // FIXME: review this
    RandomRetrieveStrategy(const GameElementMap&);
    /**
     * @brief The destructor.
     *
     */
    ~RandomRetrieveStrategy();

    // IRetrieveStrategy interface
    /**
     * @brief Get IGameElementData pointer.
     *
     * Returns the randomly selected IGameElementData from elements map.
     *
     * @param unused.
     * @return IGameElementData
     */
    IGameElementData* getElement(const QString&) const override;
private:
    RandomRetrieveStrategy(const RandomRetrieveStrategy&) = delete;
    RandomRetrieveStrategy& operator=(const RandomRetrieveStrategy&) = delete;

    PImpl<RandomRetrieveStrategyImpl> pImpl; /**< Pointer to the
                                                implementation. */
};

#endif // RANDOMRETRIEVESTRATEGY_HPP
