#ifndef TEXTITEMPROVIDER_HPP
#define TEXTITEMPROVIDER_HPP

#include "iimageprovider.hpp"

#include <QString>

class Randomizer;
/**
 * @brief Text Graphics Item Provider.
 *
 * Class responsible for creating string elements on screen.
 */
class TextItemProvider : public IImageProvider
{
public:
    /**
     * @brief The constructor.
     *
     * @param QString with text to display.
     * @param Randomizer randomizer for generating random colors.
     */
    explicit TextItemProvider(const QString&, const Randomizer&);
    /**
     * @brief The destructor.
     *
     */
    ~TextItemProvider();

    // IDataProvider interface
    /**
     * @brief Create QGraphicsItem.
     *
     * Creates QGraphicsTextItem with string provided in constructor.
     *
     * @return QGraphicsItem QGraphicsTextItem.
     */
    QGraphicsItem* makeItem() override;
private:
    TextItemProvider(const TextItemProvider&) = delete;
    TextItemProvider& operator=(const TextItemProvider&) = delete;

    // This class should only contain text to display, there is no need for
    // private implementation. Keep it simple and don't add unnecessary
    // overhead.
    QString m_text; /**< Text to display. */
    const Randomizer& m_randomizer; /**< Randomizer instance. */
};

#endif // TEXTITEMPROVIDER_HPP
