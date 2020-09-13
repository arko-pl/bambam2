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
#ifndef SCALINGPOLICYFACTORY_HPP
#define SCALINGPOLICYFACTORY_HPP

class IScalingPolicy;
namespace ScalingPolicy {
enum class Policy;
}
class QByteArray;

/**
 * @brief Scaling Policy Factory
 *
 * Class responsible for creating IScalingPolicy instance based on
 * configuration.
 */
class ScalingPolicyFactory
{
public:
    /**
     * @brief The constructor.
     *
     */
    explicit ScalingPolicyFactory();
    /**
     * @brief Create IScalingPolicy instance.
     *
     * @param name Policy Name.
     * @param data Serialized Policy Data.
     * @return IScalingPolicy instance.
     */
    IScalingPolicy* makePolicy(const ScalingPolicy::Policy policy) const;

private:
    ScalingPolicyFactory(const ScalingPolicyFactory&) = delete;
    ScalingPolicyFactory& operator=(const ScalingPolicyFactory&) = delete;
};

#endif // SCALINGPOLICYFACTORY_HPP
