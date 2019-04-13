#include "fittosizepolicy.hpp"

#include <QSize>
#include <QSizeF>
#include <QString>
#include <QDataStream>

#include "scalingpolicy_common.hpp"

FitToSizePolicy::FitToSizePolicy(const QByteArray& policyData) {
    deserialize(policyData);
}

FitToSizePolicy::~FitToSizePolicy() = default;

qreal FitToSizePolicy::getScale(const QSizeF& originalSize) const {
    const QSizeF newSize = originalSize.scaled(
                m_boundaries, Qt::KeepAspectRatio);

    return (newSize.width()/originalSize.width());
}

const QString& FitToSizePolicy::policyName() const {
    return ScalingPolicy::FitToSize;
}

const QByteArray& FitToSizePolicy::policyData(QByteArray& policyData) const {
    return serialize(policyData);
}

const QByteArray& FitToSizePolicy::serialize(QByteArray& policyData) const {
    QDataStream ds(&policyData, QIODevice::WriteOnly);
    ds << m_boundaries;
    return policyData;
}

void FitToSizePolicy::deserialize(const QByteArray& policyData) {
    QDataStream ds(policyData);
    ds >> m_boundaries;
}
