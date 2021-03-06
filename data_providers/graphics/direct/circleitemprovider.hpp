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
#ifndef CIRCLEITEMPROVIDER_HPP
#define CIRCLEITEMPROVIDER_HPP

#include "iimageprovider.hpp"

class Randomizer;

/**
 * @brief Circle Graphics Item Provider.
 *
 * Class responsible for creating color circles on the screen.
 */
class CircleItemProvider : public IImageProvider
{
public:
    /**
     * @brief The constructor.
     *
     * @param Randomizer color randomizer
     */
    explicit CircleItemProvider(const Randomizer&);
    /**
     * @brief The destructor.
     *
     */
    ~CircleItemProvider();

    // IDataProvider interface
    /**
     * @brief Create QGraphicsItem.
     *
     * Creates QGraphicsEllipseItem of random color.
     *
     * @return QGraphicsItem.
     */
    QGraphicsItem* makeItem() override;
private:
    CircleItemProvider(const CircleItemProvider&) = delete;
    CircleItemProvider& operator=(const CircleItemProvider&) = delete;

    // This class should only contain reference to randomizer, there is no need
    // for private implementation. Keep it simple and don't add unnecessary
    // overhead.
    const Randomizer& m_randomizer; /**< Color randomizer. */
};

#endif // CIRCLEITEMPROVIDER_HPP
