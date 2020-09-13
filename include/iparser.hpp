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
#ifndef IPARSER_HPP
#define IPARSER_HPP

class QString;

/**
 * @brief The parser interface.
 *
 */
class IParser {
public:
    /**
     * @brief The virtual destructor.
     *
     */
    virtual ~IParser() = default;

    /**
     * @brief Parse element at @p path.
     *
     * @param path.
     * @return bool True if parse operation succeeds, false otherwise.
     */
    virtual bool parse(const QString& path) const = 0;
    /**
     * @brief Is element at @p path parseable within this parser.
     *
     * @param path.
     * @return bool True if element is parseable, false otherwise.
     */
    virtual bool isParseable(const QString& path) const = 0;
};

#endif // IPARSER_HPP
