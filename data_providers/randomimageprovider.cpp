#include "svgitemprovider.hpp"

#include <QDirIterator>
#include <QtSvg/QGraphicsSvgItem>

#include <QtDebug>
#include <random>

class SVGItemProviderPrivate {
    friend class SVGItemProvider;

    mutable std::default_random_engine m_randomEngine;
    QStringList m_files;
};

SVGItemProvider::SVGItemProvider()
{
    pImpl = std::make_unique<SVGItemProviderPrivate>();
    QDirIterator it("data/animals");
    while (it.hasNext()) {
        auto path = it.filePath();
        qDebug() << path;
        if (path.endsWith("svg", Qt::CaseInsensitive)) {
            pImpl->m_files << path;
        }
        it.next();
    }
}

QGraphicsItem *SVGItemProvider::getDataElement(const QString& key) {
    auto distribution =
            std::uniform_int_distribution<int>(0,
                                               pImpl->m_files.count()-1);
    auto index = distribution(pImpl->m_randomEngine);
    return new QGraphicsSvgItem(pImpl->m_files.at(index));
}

QString SVGItemProvider::getProviderName() const {
    return QStringLiteral("SVG");
}
