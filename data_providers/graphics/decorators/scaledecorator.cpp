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
#include "scaledecorator.hpp"
#include <QGraphicsItem>

#include "settings/gamesettings.hpp"
#include "iscalingpolicy.hpp"

ScaleDecorator::ScaleDecorator(IImageProvider* provider,
                               IScalingPolicy* policy) :
    ImageDecorator(provider),
    m_policy(policy) {
}

ScaleDecorator::~ScaleDecorator() = default;

QGraphicsItem* ScaleDecorator::makeItem() {
    auto item = ImageDecorator::makeItem();
    if (item != nullptr) {
        const auto itemSize = m_policy->getScale(item->boundingRect().size());
        item->setScale(itemSize);
    }
    return item;
}
