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
#include "xmlfileparser.hpp"

#include <QFile>
#include <QString>

#include "xmlreader.hpp"

/**
 * @brief XML File Parser Implementation.
 *
 */
class XmlFileParserImpl {
public:
    XmlFileParserImpl(XmlReader* reader) :
        m_reader(reader) {}
    friend XmlFileParser;
private:
    XmlReader* m_reader; /**< Pointer to the reader class. */
};

XmlFileParser::XmlFileParser(XmlReader *reader) {
    pImpl = std::make_unique<XmlFileParserImpl>(reader);
}

XmlFileParser::~XmlFileParser() = default;

bool XmlFileParser::isParseable(const QString& path) const {
    return (path.endsWith("xml", Qt::CaseSensitive));
}

bool XmlFileParser::parse(const QString& path) const {
    bool result;
    QFile xmlFile(path);

    if ((result = xmlFile.open(QIODevice::ReadOnly))) {
        result = pImpl->m_reader->read(&xmlFile);
    }

    return result;
}
