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
#include "dirparser.hpp"

#include <QDirIterator>
#include <QString>
#include <QList>

/**
 * @brief Directory Parser Implementation Class.
 *
 */
class DirParserImpl {
public:
    DirParserImpl(IParser* subparser) :
        m_subparser(subparser) {}
    friend DirParser;
private:
    IParser* m_subparser; /**< Pointer to the subparser. */
};

DirParser::DirParser(IParser* subparser) {
    pImpl = std::make_unique<DirParserImpl>(subparser);
}

DirParser::~DirParser() = default;

bool DirParser::isParseable(const QString& path) const {
    QFileInfo info(path);
    return info.isDir();
}

bool DirParser::parse(const QString& path) const {
    bool result = true;
    QDirIterator it(path);
    while (it.hasNext()) {
        auto filePath = it.next();
        if (pImpl->m_subparser->isParseable(filePath)) {
            result &= pImpl->m_subparser->parse(filePath);
        }
    }
    return result;
}
