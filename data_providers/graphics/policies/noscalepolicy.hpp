#ifndef NOSCALEPOLICY_HPP
#define NOSCALEPOLICY_HPP

#include "iscalingpolicy.hpp"

/**
 * @brief No scale scaling policy.
 *
 * Scaling policy that returns always 1.0 as scale factor.
 */
class NoScalePolicy : public IScalingPolicy
{
public:
    /**
     * @brief The constructor.
     *
     */
    explicit NoScalePolicy();
    /**
     * @brief The destructor.
     *
     */
    ~NoScalePolicy();

    // IScalingPolicy interface
    /**
     * @brief Get scale factor value.
     *
     * Return always 1.0.
     *
     * @param unused
     * @return qreal Always 1.0.
     */
    qreal getScale(const QSizeF&) const override;
private:
    NoScalePolicy(const NoScalePolicy&) = delete;
    NoScalePolicy& operator=(const NoScalePolicy&) = delete;
};

#endif // NOSCALEPOLICY_HPP
