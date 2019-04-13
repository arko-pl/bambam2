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
    /**
     * @brief Get scaling policy name.
     *
     * Scaling policy name.
     *
     * @return const QString& Policy name.
     */
    virtual const QString& policyName() const = 0;
    /**
     * @brief Get scaling policy data.
     *
     * Scaling policy data.
     *
     * @param buffer Buffer for data.
     * @return const QByteArray& Reference for @p buffer.
     */
    virtual const QByteArray& policyData(QByteArray& buffer) const = 0;
};

#endif // ISCALINGPOLICY_HPP
