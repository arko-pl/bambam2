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
#include "mimebasedprovider.hpp"

#include <QtDebug>
#include <QMimeDatabase>
#include <QString>

#include <QtSvg/QGraphicsSvgItem>

MimeBasedProvider::MimeBasedProvider(const QString& path) : m_path(path) {
}

MimeBasedProvider::~MimeBasedProvider() = default;

QGraphicsItem* MimeBasedProvider::makeItem() {
    QMimeDatabase db;
    auto type = db.mimeTypeForFile(m_path);
    auto name = type.name();

    // NOTE: currently only SVG files are supported
    if (name == "image/svg+xml") {
        return new QGraphicsSvgItem(m_path);
    } else {
        return nullptr;
    }
}
