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
#ifndef XMLFILEPARSER_HPP
#define XMLFILEPARSER_HPP

#include "iparser.hpp"
#include "pimpl.hpp"

class QString;
class XmlReader;

class XmlFileParserImpl;

/**
 * @brief XML file Parser Class.
 *
 */
class XmlFileParser : public IParser
{
public:
    /**
     * @brief The constructor.
     *
     * @param reader Pointer to XML Reader.
     */
    XmlFileParser(XmlReader* reader);
    /**
     * @brief The destructor.
     *
     */
    ~XmlFileParser();
    /**
     * @brief Get the information if @p path is parseable.
     *
     * The @p path is parseable if it is an XML file.
     *
     * @param path Path to check.
     * @return bool True if @p path is an XML file, false otherwise.
     */
    bool isParseable(const QString& path) const override;
    /**
     * @brief Parse the XML file.
     *
     * Opens the XML file and calls reader's read() method.
     *
     * @param path Path to the XML file to parse.
     * @return bool True if the parse succeeds, false otherwise.
     */
    bool parse(const QString& path) const override;
private:
    XmlFileParser(const XmlFileParser&) = delete;
    XmlFileParser& operator=(const XmlFileParser&) = delete;

    PImpl<XmlFileParserImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // XMLFILEPARSER_HPP
