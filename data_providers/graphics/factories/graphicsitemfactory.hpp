#ifndef GRAPHICSITEMFACTORY_HPP
#define GRAPHICSITEMFACTORY_HPP

#include "pimpl.hpp"

class QGraphicsItem;
class IGameElementData;
class IImageProvider;

class GraphicsItemFactoryImpl;

/**
 * @brief Graphics Item Factory.
 *
 * Class responsible for creating QGraphicsItems based on IGameElementData.
 */
class GraphicsItemFactory
{
public:
    /**
     * @brief The constructor.
     *
     */
    GraphicsItemFactory();
    /**
     * @brief The destructor.
     *
     */
    ~GraphicsItemFactory();
    /**
     * @brief Create QGraphicsItem.
     *
     * Calls makeItem() method from IImageProvider based on IGameElementData.
     * If game data contains image path, the image is loaded and decorated.
     * Otherwise if game data contains name field, the name is diplayed by
     * the text provider. If the data is empty, default shape provider is used.
     *
     * @param IGameElementData Game Element Data.
     * @return QGraphicsItem.
     */
    QGraphicsItem* makeItem(const IGameElementData*);
private:
    GraphicsItemFactory(const GraphicsItemFactory&) = delete;
    GraphicsItemFactory& operator=(const GraphicsItemFactory&) = delete;

    PImpl<GraphicsItemFactoryImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // GRAPHICSITEMFACTORY_HPP
