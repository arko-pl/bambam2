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
#ifndef FITTOSIZEPOLICY_HPP
#define FITTOSIZEPOLICY_HPP

#include "iscalingpolicy.hpp"

// TODO: pimpl idiom
#include <QSizeF>

/**
 * @brief Fit to size scaling policy.
 *
 * Scaling policy that calculates scale factor value to fit the image
 * in configured boundaries.
 */
class FitToSizePolicy : public IScalingPolicy
{
public:
    /**
     * @brief The constructor.
     *
     * @param size Image boundaries specified by size.
     */
    explicit FitToSizePolicy(const QSize& size);
    /**
     * @brief The destructor.
     *
     */
    ~FitToSizePolicy();

    // IScalingPolicy interface
    /**
     * @brief Get scale factor value.
     *
     * Calculate the scale factor value for @p originalSize.
     *
     * @param originalSize Original size of image.
     * @return qreal Scale value.
     */
    qreal getScale(const QSizeF& originalSize) const override;
private:
    FitToSizePolicy(const FitToSizePolicy&) = delete;
    FitToSizePolicy& operator=(const FitToSizePolicy&) = delete;

    QSize m_boundaries; /**< Image boundaries. */
};

#endif // FITTOSIZEPOLICY_HPP
