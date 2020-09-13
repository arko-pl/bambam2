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
#ifndef GRAPHICSITEMFACTORY_HPP
#define GRAPHICSITEMFACTORY_HPP

#include "pimpl.hpp"

class QGraphicsItem;
class IGameElementData;
class IImageProvider;

class GraphicsItemFactoryImpl;

/**
 * @brief Graphics Item Factory.
 *
 * Class responsible for creating QGraphicsItems based on IGameElementData.
 */
class GraphicsItemFactory
{
public:
    /**
     * @brief The constructor.
     *
     */
    GraphicsItemFactory();
    /**
     * @brief The destructor.
     *
     */
    ~GraphicsItemFactory();
    /**
     * @brief Create QGraphicsItem.
     *
     * Calls makeItem() method from IImageProvider based on IGameElementData.
     * If game data contains image path, the image is loaded and decorated.
     * Otherwise if game data contains name field, the name is diplayed by
     * the text provider. If the data is empty, default shape provider is used.
     *
     * @param IGameElementData Game Element Data.
     * @return QGraphicsItem.
     */
    QGraphicsItem* makeItem(const IGameElementData*);
private:
    GraphicsItemFactory(const GraphicsItemFactory&) = delete;
    GraphicsItemFactory& operator=(const GraphicsItemFactory&) = delete;

    PImpl<GraphicsItemFactoryImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // GRAPHICSITEMFACTORY_HPP
