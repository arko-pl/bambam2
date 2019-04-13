#include "circleitemprovider.hpp"

#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QPen>
#include "randomizer.hpp"

CircleItemProvider::CircleItemProvider(const Randomizer& randomizer) :
    m_randomizer(randomizer) {
}

CircleItemProvider::~CircleItemProvider() = default;

QGraphicsItem* CircleItemProvider::makeItem() {
    // TODO: configurable size
    auto item = new QGraphicsEllipseItem(0,0, 64, 64);
    auto color = m_randomizer.getRandomColor();
    item->setPen(QPen(color));
    item->setBrush(QBrush(color));

    return item;
}
