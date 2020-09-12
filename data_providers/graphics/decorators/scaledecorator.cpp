#include "scaledecorator.hpp"
#include <QGraphicsItem>

#include "settings/gamesettings.hpp"
#include "iscalingpolicy.hpp"

ScaleDecorator::ScaleDecorator(IImageProvider* provider,
                               IScalingPolicy* policy) :
    ImageDecorator(provider),
    m_policy(policy) {
}

ScaleDecorator::~ScaleDecorator() = default;

QGraphicsItem* ScaleDecorator::makeItem() {
    auto item = ImageDecorator::makeItem();
    if (item != nullptr) {
        const auto itemSize = m_policy->getScale(item->boundingRect().size());
        item->setScale(itemSize);
    }
    return item;
}
