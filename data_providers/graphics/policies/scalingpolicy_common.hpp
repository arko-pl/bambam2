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
#ifndef SCALINGPOLICIES_HPP
#define SCALINGPOLICIES_HPP

#include "settings/settings_common.hpp"

class QString;

namespace ScalingPolicy {
/**
 * @brief Scaling Policies enumeration
 */
enum class Policy {
    FitToSize,
    NoScale,
};

/**
 * @brief Translate scaling policy type from settings to ScalingPolicy::Policy
 * @param type Scaling Policy type in settings
 * @return Policy used in game data
 */
constexpr ScalingPolicy::Policy fromSettings(Settings::ScalingPolicy::Type type)
{
    switch(type) {
        case Settings::ScalingPolicy::Type::NoScaling:
            return Policy::NoScale;
        case Settings::ScalingPolicy::Type::FitToSize:
        default:
            return Policy::FitToSize;
    }
}
}

#endif // SCALINGPOLICIES_HPP
