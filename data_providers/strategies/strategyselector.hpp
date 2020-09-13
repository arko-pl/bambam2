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
#ifndef STRATEGYSELECTOR_HPP
#define STRATEGYSELECTOR_HPP

#include "pimpl.hpp"
#include "typedefs.hpp"

class StrategySelectorImpl;
class IRetrieveStrategy;
class QString;

/**
 * @brief Strategy Selector
 *
 * Class responsible for selecting strategy that has sense for the key pressed.
 */
class StrategySelector
{
public:
    /**
     * @brief The constructor.
     *
     * @param elements mapping with starting character as key and
     * IGameElementData pointer as value.
     */
    explicit StrategySelector(const GameElementMap&);
    /**
     * @brief The destructor.
     *
     */
    ~StrategySelector();

    /**
     * @brief Get strategy for a given @p key.
     *
     * Returns strategy that has sense for the key pressed.
     *
     * @param key String key representation.
     * @return IRetrieveStrategy Selected strategy.
     */
    IRetrieveStrategy* getStrategy(const QString& key);
private:
    StrategySelector(const StrategySelector&) = delete;
    StrategySelector& operator=(const StrategySelector&) = delete;

    PImpl<StrategySelectorImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // STRATEGYSELECTOR_HPP
