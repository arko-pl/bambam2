#ifndef SCALINGPOLICIES_HPP
#define SCALINGPOLICIES_HPP

#include "settings/settings_common.hpp"

class QString;

namespace ScalingPolicy {
enum class Policy {
    FitToSize,
    NoScale,
};

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
