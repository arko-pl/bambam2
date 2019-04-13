#include "textitemprovider.hpp"

#include <QFont>
#include <QGraphicsTextItem>

#include "randomizer.hpp"

TextItemProvider::TextItemProvider(const QString& text,
                                   const Randomizer& randomizer)
    : m_text(text),
      m_randomizer(randomizer) {
}

TextItemProvider::~TextItemProvider() = default;

#include <QtDebug>

QGraphicsItem* TextItemProvider::makeItem()
{
    Q_ASSERT(!m_text.isEmpty());

    if (!m_text.at(0).isPrint()) {
        return nullptr;
    }

    auto item = new QGraphicsTextItem(m_text);

    // TODO: configurable fonts
    QFont font("Helvetica", 36);
    font.setBold(true);

    item->setFont(font);

    item->setDefaultTextColor(m_randomizer.getRandomColor());

    return item;
}
