#include "fittosizepolicy.hpp"

#include <QSize>
#include <QSizeF>
#include <QString>
#include <QDataStream>

#include "scalingpolicy_common.hpp"

FitToSizePolicy::FitToSizePolicy(const QSize& size) : m_boundaries(size) {
}

FitToSizePolicy::~FitToSizePolicy() = default;

qreal FitToSizePolicy::getScale(const QSizeF& originalSize) const {
    const QSizeF newSize = originalSize.scaled(
                m_boundaries, Qt::KeepAspectRatio);

    return (newSize.width()/originalSize.width());
}
