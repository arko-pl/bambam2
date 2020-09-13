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
#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <QObject>
#include <QColor>

#include "pimpl.hpp"

class RandomizerPrivate;

/**
 * @brief Randomizer class.
 *
 */
class Randomizer
{
public:
    /**
     * @brief The constructor.
     *
     */
    explicit Randomizer();
    /**
     * @brief The destructor.
     *
     */
    ~Randomizer();

    /**
     * @brief Get random integer in range [@p min, @p max].
     *
     * @param min Minimum value.
     * @param max Maximum value.
     * @return int Random integer.
     */
    int getRandomInt(int min, int max) const;
    /**
     * @brief Get random real value in range [@p min, @p max].
     *
     * @param min Minimum value.
     * @param max Maximum values.
     * @return double Random real.
     */
    double getRandomReal(double min, double max) const;
    /**
     * @brief Get random color.
     *
     * @return QColor Random color.
     */
    QColor getRandomColor() const;
private:
    Randomizer(const Randomizer&) = delete;
    Randomizer& operator=(const Randomizer&) = delete;

    PImpl<RandomizerPrivate> pImpl; /**< Pointer to the implementation. */
};

#endif // RANDOMIZER_HPP
