#include "scalingpolicyfactory.hpp"

#include <QString>
#include <QStringList>

#include "data_providers/graphics/policies/scalingpolicy_common.hpp"
#include "data_providers/graphics/policies/fittosizepolicy.hpp"
#include "data_providers/graphics/policies/noscalepolicy.hpp"

ScalingPolicyFactory::ScalingPolicyFactory() {
}

IScalingPolicy* ScalingPolicyFactory::makePolicy(
        const ScalingPolicy::Policy policy, const QByteArray& data) const {

    if (policy == ScalingPolicy::Policy::FitToSize) {
        return new FitToSizePolicy(data);
    } else if (policy == ScalingPolicy::Policy::NoScale) {
        return new NoScalePolicy();
    }
    Q_ASSERT_X(false, __FUNCTION__, "Not implemented scaling policy!");
    return nullptr;
}
