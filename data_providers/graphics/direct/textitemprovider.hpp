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
