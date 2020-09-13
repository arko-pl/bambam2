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
#include "randomretrievestrategy.hpp"

#include <QMultiHash>
#include <QString>

#include "igameelementdata.hpp"
#include "randomizer.hpp"

class RandomRetrieveStrategyImpl {
public:
    RandomRetrieveStrategyImpl(const GameElementMap& elements) :
        m_elements(elements),
        m_randomizer() { }
    friend class RandomRetrieveStrategy;
private:
    const GameElementMap& m_elements;

    Randomizer m_randomizer;
};

RandomRetrieveStrategy::RandomRetrieveStrategy(
        const GameElementMap& elements) {
    pImpl = std::make_unique<RandomRetrieveStrategyImpl>(elements);
}

RandomRetrieveStrategy::~RandomRetrieveStrategy() = default;

IGameElementData* RandomRetrieveStrategy::getElement(const QString&) const {
    const auto& values = pImpl->m_elements.values();
    auto index = pImpl->m_randomizer.getRandomInt(0, values.count() - 1);
    return values.at(index);
}
