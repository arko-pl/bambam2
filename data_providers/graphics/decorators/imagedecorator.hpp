#ifndef IMAGEDECORATOR_HPP
#define IMAGEDECORATOR_HPP

#include "iimageprovider.hpp"

/**
 * @brief Image decorator.
 *
 * Decorator class for inner IImageProvider instance.
  */
class ImageDecorator : public IImageProvider
{
public:
    /**
     * @brief The constructor.
     *
     * @param provider inner IImageProvider.
     */
    explicit ImageDecorator(IImageProvider* provider);

    /**
     * @brief The destructor.
     *
     */
    ~ImageDecorator();
    // IDataProvider interface
    /**
     * @brief Create QGraphicsItem.
     *
     * Call makeItem() function of decorated class.
     *
     * @return QGraphicsItem
     */
    QGraphicsItem* makeItem() override;
private:
    ImageDecorator(const ImageDecorator&) = delete;
    ImageDecorator& operator=(const ImageDecorator&) = delete;

    // This class should hold only inner IImageProvider so there is no
    // need for private implementation class
    IImageProvider *m_innerProvider; /**< Pointer to decorated class. */
};

#endif // IMAGEDECORATOR_HPP
