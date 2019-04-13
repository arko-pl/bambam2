#ifndef CIRCLEITEMPROVIDER_HPP
#define CIRCLEITEMPROVIDER_HPP

#include "iimageprovider.hpp"

class Randomizer;

/**
 * @brief Circle Graphics Item Provider.
 *
 * Class responsible for creating color circles on the screen.
 */
class CircleItemProvider : public IImageProvider
{
public:
    /**
     * @brief The constructor.
     *
     * @param Randomizer color randomizer
     */
    explicit CircleItemProvider(const Randomizer&);
    /**
     * @brief The destructor.
     *
     */
    ~CircleItemProvider();

    // IDataProvider interface
    /**
     * @brief Create QGraphicsItem.
     *
     * Creates QGraphicsEllipseItem of random color.
     *
     * @return QGraphicsItem.
     */
    QGraphicsItem* makeItem() override;
private:
    CircleItemProvider(const CircleItemProvider&) = delete;
    CircleItemProvider& operator=(const CircleItemProvider&) = delete;

    // This class should only contain reference to randomizer, there is no need
    // for private implementation. Keep it simple and don't add unnecessary
    // overhead.
    const Randomizer& m_randomizer; /**< Color randomizer. */
};

#endif // CIRCLEITEMPROVIDER_HPP
