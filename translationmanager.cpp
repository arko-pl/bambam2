#include "translationmanager.hpp"

Translations::Language Translations::fromString(const QString& language) {
    if (language ==  "pl") {
        return Language::Polish;
    } else {
        return Language::English;
    }
}
