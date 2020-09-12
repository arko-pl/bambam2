#include "noscalepolicy.hpp"
#include "scalingpolicy_common.hpp"
#include <QString>

NoScalePolicy::NoScalePolicy() {
}

NoScalePolicy::~NoScalePolicy() = default;

qreal NoScalePolicy::getScale(const QSizeF&) const {
    return 1.0;
}
