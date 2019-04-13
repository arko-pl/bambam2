#include "dataprovider_common.hpp"

#include <QString>

const QString DataProvider::ConfigBasedProvider = QStringLiteral("ConfigBased");
const QString DataProvider::TextProvider = QStringLiteral("Text");

DataProvider::Provider DataProvider::fromString(const QString& name) {
    if (name == ConfigBasedProvider) {
        return Provider::ConfigBased;
    } else if (name == TextProvider) {
        return Provider::Text;
    }
    // TODO: error provider doesn't exist
    return Provider::Unknown;
}
