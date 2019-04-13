#include "gameelementdata.hpp"

#include <QString>
#include <QMap>

/**
 * @brief Game Element Data Implementation.
 *
 */
class GameElementDataImpl {
public:
    friend class GameElementData;
    explicit GameElementDataImpl(const QString& name) :
        m_name(name),
        m_translations(),
        m_imagePath(),
        m_soundPath() {}
private:
    QString m_name; /**< Game Element name. */
    QMap<QString, QString> m_translations; /**< Translation map. */
    QString m_imagePath; /**< Path to the image file. */
    QString m_soundPath; /**< Path to the sound file. */
};

GameElementData::GameElementData() {
    makeImpl(QString());
}

GameElementData::GameElementData(const QString& name) {
    makeImpl(name);
}

GameElementData::~GameElementData() = default;

void GameElementData::setImagePath(const QString& path) {
    pImpl->m_imagePath = path;
}

void GameElementData::setSoundPath(const QString& path) {
    pImpl->m_soundPath = path;
}

void GameElementData::setTranslation(const QString& language, const QString& word) {
    pImpl->m_translations.insert(language, word);
}

void GameElementData::setName(const QString& name) {
    pImpl->m_name = name;
}

const QString&GameElementData::name() const {
    return pImpl->m_name;
}

const QString& GameElementData::imagePath() const {
    return pImpl->m_imagePath;
}

const QString& GameElementData::soundPath() const {
    return pImpl->m_soundPath;
}

const QString& GameElementData::translation(const QString& language) const {
    const auto it = pImpl->m_translations.find(language);
    if (it != pImpl->m_translations.cend()) {
        return it.value();
    }
    return pImpl->m_name;
}

void GameElementData::makeImpl(const QString& name) {
    pImpl = std::make_unique<GameElementDataImpl>(name);
}

