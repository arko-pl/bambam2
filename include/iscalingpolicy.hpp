#ifndef ISCALINGPOLICY_HPP
#define ISCALINGPOLICY_HPP

#include <QtGlobal>

class QSizeF;

/**
 * @brief Scaling policy interface.
 *
 */
class IScalingPolicy {
public:
    /**
     * @brief Virtual destructor.
     *
     */
    virtual ~IScalingPolicy() {}
    /**
     * @brief Get scale value.
     *
     * Get scale for image that will be displayed on the screen.
     *
     * @param originalSize Original image size.
     * @return qreal scale value.
     */
    virtual qreal getScale(const QSizeF& originalSize) const = 0;
};

#endif // ISCALINGPOLICY_HPP
