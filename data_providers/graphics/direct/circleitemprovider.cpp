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
#include "circleitemprovider.hpp"

#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QPen>
#include "randomizer.hpp"

CircleItemProvider::CircleItemProvider(const Randomizer& randomizer) :
    m_randomizer(randomizer) {
}

CircleItemProvider::~CircleItemProvider() = default;

QGraphicsItem* CircleItemProvider::makeItem() {
    // TODO: configurable size
    auto item = new QGraphicsEllipseItem(0,0, 64, 64);
    auto color = m_randomizer.getRandomColor();
    item->setPen(QPen(color));
    item->setBrush(QBrush(color));

    return item;
}
