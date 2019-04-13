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
    IScalingPolicy* makePolicy(const ScalingPolicy::Policy policy,
                               const QByteArray& data) const;

private:
    ScalingPolicyFactory(const ScalingPolicyFactory&) = delete;
    ScalingPolicyFactory& operator=(const ScalingPolicyFactory&) = delete;
};

#endif // SCALINGPOLICYFACTORY_HPP
