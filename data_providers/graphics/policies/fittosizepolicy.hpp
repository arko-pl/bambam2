#ifndef FITTOSIZEPOLICY_HPP
#define FITTOSIZEPOLICY_HPP

#include "iscalingpolicy.hpp"

// TODO: pimpl idiom
#include <QSizeF>

/**
 * @brief Fit to size scaling policy.
 *
 * Scaling policy that calculates scale factor value to fit the image
 * in configured boundaries.
 */
class FitToSizePolicy : public IScalingPolicy
{
public:
    /**
     * @brief The constructor.
     *
     * @param policyData Serialized policy data.
     */
    explicit FitToSizePolicy(const QByteArray& policyData);
    /**
     * @brief The destructor.
     *
     */
    ~FitToSizePolicy();

    // IScalingPolicy interface
    /**
     * @brief Get scale factor value.
     *
     * Calculate the scale factor value for @p originalSize.
     *
     * @param originalSize Original size of image.
     * @return qreal Scale value.
     */
    qreal getScale(const QSizeF& originalSize) const override;
    /**
     * @brief Get policy name.
     *
     * @return const QString Policy name.
     */
    const QString& policyName() const override;
    /**
     * @brief Get policy configuration data.
     *
     * @param buffer Buffer for serialized data.
     * @return const QByteArray Reference to @p buffer.
     */
    const QByteArray& policyData(QByteArray& buffer) const override;
private:
    FitToSizePolicy(const FitToSizePolicy&) = delete;
    FitToSizePolicy& operator=(const FitToSizePolicy&) = delete;
    /**
     * @brief Serialize policy configuration data.
     *
     * @param buffer Buffer for serialized data.
     * @return const QByteArray Reference to @p buffer.
     */
    const QByteArray& serialize(QByteArray& buffer) const;
    /**
     * @brief Deserialize policy configuration data.
     *
     * Deserialize boundaries provided as QByteArray.
     *
     * @param policyData Serialized policy data.
     */
    void deserialize(const QByteArray& policyData);
    QSize m_boundaries; /**< Image boundaries. */
};

#endif // FITTOSIZEPOLICY_HPP
