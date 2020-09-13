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
#ifndef SCALEDECORATOR_HPP
#define SCALEDECORATOR_HPP

#include "imagedecorator.hpp"
#include <QtGlobal>

class QSizeF;
class IScalingPolicy;

/**
 * @brief Scale Decorator.
 *
 * Decorator used for scaling inner image.
 */
class ScaleDecorator : public ImageDecorator
{
public:
    /**
     * @brief The constructor.
     *
     * @param provider Pointer to inner IImageProvider.
     * @param policy Scaling policy.
     */
    explicit ScaleDecorator(IImageProvider* provider, IScalingPolicy* policy);
    /**
     * @brief The destructor.
     *
     */
    ~ScaleDecorator();

    // IDataProvider interface
    /**
     * @brief Scale QGraphicsItem according to selected scaling policy.
     *
     * Scale QGraphicsItem according to selected scaling policy.
     *
     * @return QGraphicsItem pointer to scaled image.
     */
    QGraphicsItem* makeItem() override;
private:
    ScaleDecorator(const ScaleDecorator&) = delete;
    ScaleDecorator& operator=(const ScaleDecorator&) = delete;

    IScalingPolicy* m_policy;  /**< Scaling policy. */
};


#endif // SCALEDECORATOR_HPP
