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
#include "randomizer.hpp"

#include <random>

/**
 * @brief Randomizer Implementation Class.
 *
 */
class RandomizerPrivate {
public:
    explicit RandomizerPrivate() :
        m_randomEngine(m_randomDevice())
    {}

    std::random_device m_randomDevice; /**< Random device. */
    mutable std::mt19937 m_randomEngine; /**< Random engine. */
};

Randomizer::Randomizer() {
    pImpl = std::make_unique<RandomizerPrivate>();
}

Randomizer::~Randomizer() = default;

int Randomizer::getRandomInt(int min, int max) const {
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(pImpl->m_randomEngine);
}

qreal Randomizer::getRandomReal(qreal min, qreal max) const {
    std::uniform_real_distribution<qreal> distribution(min, max);

    return distribution(pImpl->m_randomEngine);
}

QColor Randomizer::getRandomColor() const {
    // The distribution and Saturation/Value table has been chosen
    // to give the best balance between saturated colors, black and gray.
    int svTable[] = {  64,  0, 225, 255, 255, 255, 225, 128, 255, 64,
                      255, 255, 255, 255, 255, 255, 0, 255, 255, 0, };
    std::poisson_distribution<int> sv_distribution(5);
    int h = getRandomInt(0, 359);
    int s = svTable[sv_distribution(pImpl->m_randomEngine)];
    int v = (s == 0) ? getRandomInt(0, 128) :
                svTable[sv_distribution(pImpl->m_randomEngine)];

    return QColor::fromHsv(h, s, v);
}
