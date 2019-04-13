#ifndef SCALINGPOLICIES_HPP
#define SCALINGPOLICIES_HPP

class QString;

namespace ScalingPolicy {

enum class Policy {
    FitToSize,
    NoScale,
};

extern const QString FitToSize;
extern const QString NoScale;

Policy fromString(const QString& name);
const QString& getDefault();

}

#endif // SCALINGPOLICIES_HPP
