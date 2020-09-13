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
#ifndef DIRPARSER_HPP
#define DIRPARSER_HPP

#include "iparser.hpp"
#include "pimpl.hpp"

class QString;
class XmlReader;

class DirParserImpl;

/**
 * @brief Directory Parser Class.
 *
 */
class DirParser : public IParser
{
public:
    /**
     * @brief The constructor.
     *
     * @param subparser Pointer to the subparser.
     */
    explicit DirParser(IParser* subparser);
    /**
     * @brief The destructor.
     *
     */
    ~DirParser();

    /**
     * @brief Get the information if @p path is parseable.
     *
     * The @p path is parseable if it is a directory.
     *
     * @param path Path to check.
     * @return bool True if @p path is directory, false otherwise.
     */
    bool isParseable(const QString& path) const override;
    /**
     * @brief Parse the directory.
     *
     * Traverse through whole directory and call subparser on all elements.
     *
     * @param path Directory to parse.
     * @return bool True if parsing operation was successfull, false otherwise.
     */
    bool parse(const QString& path) const override;

private:
    DirParser(const DirParser&) = delete;
    DirParser& operator=(const DirParser&) = delete;

    PImpl<DirParserImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // DIRPARSER_HPP
