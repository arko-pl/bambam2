#ifndef IIMAGEPROVIDER_HPP
#define IIMAGEPROVIDER_HPP

class QGraphicsItem;
class QString;

/**
 * @brief Image Provider Interface.
 *
 */
class IImageProvider {
public:
    /**
     * @brief The virtual destructor.
     *
     */
    virtual ~IImageProvider() {}

    /**
     * @brief Create the QGraphicsItem.
     *
     * @return QGraphicsItem
     */
    virtual QGraphicsItem *makeItem() = 0;
};

#endif // IIMAGEPROVIDER_HPP
