#include "graphicsitemdecorator.hpp"

#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <QFont>

/**
 * @brief Graphics Item Decorator Implementation.
 *
 */
class GraphicsItemDecoratorImpl {
public:
    /**
     * @brief The constructor.
     *
     * @param description Image description.
     */
    GraphicsItemDecoratorImpl(const QString& description) :
        m_description(description) {}
    friend class GraphicsItemDecorator;
private:
    const QString& m_description; /**< Image description. */
};

GraphicsItemDecorator::GraphicsItemDecorator(IImageProvider* provider,
                                             const QString& description) :
    ImageDecorator(provider)
{
    pImpl = std::make_unique<GraphicsItemDecoratorImpl>(description);
}

QGraphicsItem* GraphicsItemDecorator::makeItem() {
    auto item = ImageDecorator::makeItem();
    if (item != nullptr && !pImpl->m_description.isEmpty()) {
        // TODO: decompose this function
        QGraphicsTextItem* descr = new QGraphicsTextItem(
                    pImpl->m_description.toUpper());
        QFont font("Helvetica", 20);
        font.setBold(true);
        descr->setFont(font);
        descr->setDefaultTextColor(QColor(0,0,0));

        const auto itemScale = item->scale();
        const QSizeF rectSize = (item->boundingRect().size() * itemScale) +
                QSizeF(0, descr->boundingRect().height());
        QGraphicsRectItem* border =
                new QGraphicsRectItem(QRectF(item->boundingRect().topLeft(),
                                             rectSize) + QMargins(2,2,2,2));
        border->setBrush(QBrush(Qt::NoBrush));
        border->setPen(QPen(Qt::blue));
        item->setParentItem(border);

        descr->setParentItem(border);
        auto itemWidth = item->boundingRect().width() * itemScale;
        descr->setPos(itemWidth/2 - descr->boundingRect().width()/2,
                      item->boundingRect().height()*item->scale());
        item = border;
    }
    return item;
}
