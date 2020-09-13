/*
 * Copyright (C) 2020  Arkadiusz Bubała <arek2407066@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
    QFont font("Helvetica", 72);
    font.setBold(true);

    item->setFont(font);

    item->setDefaultTextColor(m_randomizer.getRandomColor());

    return item;
}
