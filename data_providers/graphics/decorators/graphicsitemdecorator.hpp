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
#ifndef GRAPHICSITEMDECORATOR_HPP
#define GRAPHICSITEMDECORATOR_HPP

#include "imagedecorator.hpp"
#include "pimpl.hpp"

class GraphicsItemDecoratorImpl;

/**
 * @brief Graphics Item Decorator
 *
 * Decorates image with a border and description.
 */
class GraphicsItemDecorator : public ImageDecorator
{
public:
    /**
     * @brief The constructor
     *
     * @param Pointer to decorated IImageProvider
     * @param description Image description displayed in frame.
     */
    explicit GraphicsItemDecorator(IImageProvider*, const QString& description);

    // IDataProvider interface
    /**
     * @brief Create QGraphicsItem.
     *
     * Crate frame with image and description inside. Image is created
     * by IImageProvider passed in the constructor.
     *
     * @return QGraphicsItem
     */
    QGraphicsItem* makeItem() override;
private:
    GraphicsItemDecorator(const GraphicsItemDecorator&) = delete;
    GraphicsItemDecorator& operator=(const GraphicsItemDecorator&) = delete;

    PImpl<GraphicsItemDecoratorImpl> pImpl; /**< Pointer to implementation. */
};


#endif // GRAPHICSITEMDECORATOR_HPP
