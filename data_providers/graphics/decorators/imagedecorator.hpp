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
#ifndef IMAGEDECORATOR_HPP
#define IMAGEDECORATOR_HPP

#include "iimageprovider.hpp"

/**
 * @brief Image decorator.
 *
 * Decorator class for inner IImageProvider instance.
  */
class ImageDecorator : public IImageProvider
{
public:
    /**
     * @brief The constructor.
     *
     * @param provider inner IImageProvider.
     */
    explicit ImageDecorator(IImageProvider* provider);

    /**
     * @brief The destructor.
     *
     */
    ~ImageDecorator();
    // IDataProvider interface
    /**
     * @brief Create QGraphicsItem.
     *
     * Call makeItem() function of decorated class.
     *
     * @return QGraphicsItem
     */
    QGraphicsItem* makeItem() override;
private:
    ImageDecorator(const ImageDecorator&) = delete;
    ImageDecorator& operator=(const ImageDecorator&) = delete;

    // This class should hold only inner IImageProvider so there is no
    // need for private implementation class
    IImageProvider *m_innerProvider; /**< Pointer to decorated class. */
};

#endif // IMAGEDECORATOR_HPP
