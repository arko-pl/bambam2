#include "noscalepolicy.hpp"
#include "scalingpolicy_common.hpp"
#include <QString>

NoScalePolicy::NoScalePolicy() {
}

NoScalePolicy::~NoScalePolicy() = default;

qreal NoScalePolicy::getScale(const QSizeF&) const {
    return 1.0;
}

const QString& NoScalePolicy::policyName() const {
    return ScalingPolicy::NoScale;
}

const QByteArray& NoScalePolicy::policyData(QByteArray& buffer) const {
    return buffer;
}
