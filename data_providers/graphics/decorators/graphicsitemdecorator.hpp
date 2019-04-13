#ifndef GRAPHICSITEMDECORATOR_HPP
#define GRAPHICSITEMDECORATOR_HPP

#include "imagedecorator.hpp"
#include "pimpl.hpp"

class GraphicsItemDecoratorImpl;

/**
 * @brief Graphics Item Decorator
 *
 * Decorates image with a border and description.
 */
class GraphicsItemDecorator : public ImageDecorator
{
public:
    /**
     * @brief The constructor
     *
     * @param Pointer to decorated IImageProvider
     * @param description Image description displayed in frame.
     */
    explicit GraphicsItemDecorator(IImageProvider*, const QString& description);

    // IDataProvider interface
    /**
     * @brief Create QGraphicsItem.
     *
     * Crate frame with image and description inside. Image is created
     * by IImageProvider passed in the constructor.
     *
     * @return QGraphicsItem
     */
    QGraphicsItem* makeItem() override;
private:
    GraphicsItemDecorator(const GraphicsItemDecorator&) = delete;
    GraphicsItemDecorator& operator=(const GraphicsItemDecorator&) = delete;

    PImpl<GraphicsItemDecoratorImpl> pImpl; /**< Pointer to implementation. */
};


#endif // GRAPHICSITEMDECORATOR_HPP
