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
#ifndef MIMEBASEDPROVIDER_HPP
#define MIMEBASEDPROVIDER_HPP

#include "iimageprovider.hpp"
#include <QString>

/**
 * @brief MIME Type based image provider class.
 *
 * This class is responsible for creating QGraphicsImage
 * from files with images. The file parser is selected by
 * its MIME Type.
 */
class MimeBasedProvider : public IImageProvider
{
public:
    /**
     * @brief The constructor.
     *
     * @param path Path to image file.
     */
    explicit MimeBasedProvider(const QString &path);
    /**
     * @brief The destructor.
     *
     */
    ~MimeBasedProvider();

    // IDataProvider interface
    /**
     * @brief Create QGraphicsItem.
     *
     * Creates QGraphicsImage instance using the reader selected by image type.
     *
     * @return QGraphicsItem
     */
    QGraphicsItem* makeItem() override;

private:
    MimeBasedProvider(const MimeBasedProvider&) = delete;
    MimeBasedProvider& operator=(const MimeBasedProvider&) = delete;

    // This class should only contain path, there is no need for
    // private implementation. Keep it simple and don't add
    // unnecessary overhead.
    QString m_path; /**< Image path. */
};


#endif // MIMEBASEDPROVIDER_HPP
