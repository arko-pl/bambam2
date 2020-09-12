#include "scalingpolicyfactory.hpp"

#include <QString>
#include <QStringList>
#include <QVariant>

#include "settings/gamesettings.hpp"
#include "settings/settings_common.hpp"
#include "data_providers/graphics/policies/scalingpolicy_common.hpp"
#include "data_providers/graphics/policies/fittosizepolicy.hpp"
#include "data_providers/graphics/policies/noscalepolicy.hpp"

ScalingPolicyFactory::ScalingPolicyFactory() {
}

IScalingPolicy* ScalingPolicyFactory::makePolicy(
        const ScalingPolicy::Policy policy) const {

    GameSettings& settings = GameSettings::getInstance();
    if (policy == ScalingPolicy::Policy::FitToSize) {
        // FIXME: policy name from settings different from those in file
        QSize size = settings.getScalingPolicyOption(
                    Settings::ScalingPolicy::FitToSize::SUBGROUP,
                    Settings::ScalingPolicy::FitToSize::SIZE).toSize();
        return new FitToSizePolicy(size);
    } else if (policy == ScalingPolicy::Policy::NoScale) {
        return new NoScalePolicy();
    }
    Q_ASSERT_X(false, __FUNCTION__, "Not implemented scaling policy!");
    return nullptr;
}
