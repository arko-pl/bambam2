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
