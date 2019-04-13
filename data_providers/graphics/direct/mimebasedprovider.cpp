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
