#include "scalingpolicy_common.hpp"
#include "fittosizepolicy.hpp"
#include "noscalepolicy.hpp"

#include <QString>

const QString ScalingPolicy::FitToSize = QStringLiteral("FitToSize");
const QString ScalingPolicy::NoScale = QStringLiteral("NoScale");

ScalingPolicy::Policy ScalingPolicy::fromString(const QString& name) {
    if (name == FitToSize) {
        return Policy::FitToSize;
    } else if (name == NoScale) {
        return Policy::NoScale;
    }
    // TODO: warning policy doesn't exist
    return Policy::NoScale;
}



const QString& ScalingPolicy::getDefault() {
    return FitToSize;
}
