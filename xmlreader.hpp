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
#ifndef XMLREADER_HPP
#define XMLREADER_HPP

#include <QObject>
#include "pimpl.hpp"
#include "typedefs.hpp"

class QIODevice;
class QXmlStreamReader;
class XmlReaderImpl;

// TODO: Document this class

class XmlReader
{
public:
    explicit XmlReader(GameElementMap&);
    ~XmlReader();

    bool read(QIODevice *device);
private:
    XmlReader(const XmlReader&) = delete;
    XmlReader& operator=(const XmlReader&) = delete;

    void processImage(IGameElementData*);
    void processSound(IGameElementData*);
    void processTranslation(IGameElementData*);

    PImpl<XmlReaderImpl> pImpl;
};

#endif // XMLREADER_HPP
