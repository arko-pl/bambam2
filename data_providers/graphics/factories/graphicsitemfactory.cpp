#include "graphicsitemfactory.hpp"

#include "igameelementdata.hpp"
#include "iscalingpolicy.hpp"
#include "gamesettings.hpp"
#include "randomizer.hpp"
#include "data_providers/graphics/decorators/graphicsitemdecorator.hpp"
#include "data_providers/graphics/decorators/scaledecorator.hpp"
#include "data_providers/graphics/direct/circleitemprovider.hpp"
#include "data_providers/graphics/direct/mimebasedprovider.hpp"
#include "data_providers/graphics/direct/textitemprovider.hpp"


/**
 * @brief Graphics Item Factory Implementation.
 *
 */
class GraphicsItemFactoryImpl {
public:
    GraphicsItemFactoryImpl(IScalingPolicy* scalingPolicy) :
        m_randomizer(),
        m_defaultProvider(m_randomizer),
        m_scalingPolicy(scalingPolicy)
    {}
    friend class GraphicsItemFactory;
private:
    Randomizer m_randomizer; /**< Graphics randomizer. */
    CircleItemProvider m_defaultProvider; /**< Default provider. */
    IScalingPolicy* m_scalingPolicy; /**< Scaling policy. */
};

GraphicsItemFactory::GraphicsItemFactory() {
    IScalingPolicy* scalingPolicy =
            GameSettings::getInstance().getScalingPolicy();
    pImpl = std::make_unique<GraphicsItemFactoryImpl>(scalingPolicy);
}

GraphicsItemFactory::~GraphicsItemFactory() = default;

QGraphicsItem* GraphicsItemFactory::makeItem(const IGameElementData* element) {
    QGraphicsItem* item = nullptr;
    if (element == nullptr) {
        return pImpl->m_defaultProvider.makeItem();
    }
    if (!element->imagePath().isEmpty()) {
        IImageProvider* itemProvider =
                new GraphicsItemDecorator(
                    new ScaleDecorator(
                        new MimeBasedProvider(element->imagePath()),
                        pImpl->m_scalingPolicy),
                    element->translation(GameSettings::getInstance().
                                                       getLanguage()));
        item = itemProvider->makeItem();
        delete itemProvider;
    }
    if (item == nullptr && !element->name().isEmpty()) {
        TextItemProvider textProvider(element->name(), pImpl->m_randomizer);
        item = textProvider.makeItem();
    }
    if (item == nullptr) {
        item = pImpl->m_defaultProvider.makeItem();
    }
    return item;
}
