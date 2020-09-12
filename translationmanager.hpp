#ifndef TRANSLATIONMANAGER_HPP
#define TRANSLATIONMANAGER_HPP

#include "settings/settings_common.hpp"

class QString;

namespace Translations {
enum class Language {
    English,
    Polish
};

constexpr Language fromSettings(Settings::General::Language language) {
    switch (language) {
        case Settings::General::Language::Polish:
            return Language::Polish;
        case Settings::General::Language::English:
        default:
            return Language::English;
    }
}

Language fromString(const QString& language);
}
#endif // TRANSLATIONMANAGER_HPP
