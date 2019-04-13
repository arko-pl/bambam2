#include "imagedecorator.hpp"

ImageDecorator::ImageDecorator(IImageProvider* provider) :
    m_innerProvider(provider) {
}

ImageDecorator::~ImageDecorator() {
    delete m_innerProvider;
}

QGraphicsItem* ImageDecorator::makeItem() {
    return m_innerProvider->makeItem();
}
