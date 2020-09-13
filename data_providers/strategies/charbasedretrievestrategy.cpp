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
#include "charbasedretrievestrategy.hpp"

#include <QMultiHash>
#include <QString>

#include "randomizer.hpp"

class CharBasedRetrieveStrategyImpl {
public:
    CharBasedRetrieveStrategyImpl(const GameElementMap& elements) :
        m_elements(elements),
        m_randomizer() { }
    friend class CharBasedRetrieveStrategy;
private:
    const GameElementMap& m_elements;
    Randomizer m_randomizer;
};

CharBasedRetrieveStrategy::CharBasedRetrieveStrategy(
        const GameElementMap& elements) {
    pImpl = std::make_unique<CharBasedRetrieveStrategyImpl>(elements);
}

CharBasedRetrieveStrategy::~CharBasedRetrieveStrategy() = default;


IGameElementData* CharBasedRetrieveStrategy::getElement(
        const QString& key) const {
    Q_ASSERT(!key.isEmpty());

    QChar k = key.at(0);
    const auto& values = pImpl->m_elements.values(k);
    auto count = values.count();
    if (count == 0) {
        return nullptr;
    } else if (count == 1) {
        return values.at(0);
    } else {
        auto index = pImpl->m_randomizer.getRandomInt(0, count - 1);
        return values.at(index);
    }
}
