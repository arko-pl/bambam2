#include "xmlreader.hpp"

#include <QXmlStreamReader>
#ifdef QT_DEBUG
#include <QtDebug>
#endif

#include "gameelementdata.hpp"
#include "settings/gamesettings.hpp"
#include "settings/settings_common.hpp"
#include "translationmanager.hpp"

class XmlReaderImpl {
public:
    explicit XmlReaderImpl(GameElementMap& elements) : m_elements(elements) {}
    friend class XmlReader;

private:
    GameElementMap& m_elements;
    QXmlStreamReader m_xml;
};

XmlReader::XmlReader(GameElementMap& elements) {
    pImpl = std::make_unique<XmlReaderImpl>(elements);
}

XmlReader::~XmlReader() = default;

bool XmlReader::read(QIODevice *device) {
    const GameSettings& settings = GameSettings::getInstance();
    auto& xml = pImpl->m_xml;
    xml.setDevice(device);
    const auto language = Translations::fromSettings(
                qvariant_cast<Settings::General::Language>(
                    settings.getGeneralOption(Settings::General::LANGUAGE)));

    GameElementData* ge = new GameElementData();
    while (!xml.atEnd()) {
        if (xml.readNext() != QXmlStreamReader::EndDocument &&
                xml.isStartElement()) {
            auto name = xml.name();
            if (name == "name") {
                xml.readNext();
                ge->setName(xml.text().toString());
            } else if (name == "image") {
                processImage(ge);
            } else if (name == "sound") {
                processSound(ge);
            } else if (name == "translation") {
                processTranslation(ge);
            } else {
                // pass through
            }
        }
    }

    if (!ge->name().isEmpty() && !ge->imagePath().isEmpty() &&
            !xml.hasError()) {
        auto translation = ge->translation(language);
        if (!translation.isEmpty()) {
            pImpl->m_elements.insert(translation.at(0), ge);
        } else {
#ifdef QT_DEBUG
            qDebug() << "No translation found for language code:"
                     << static_cast<int>(language);
#endif
        }
    } else {
#ifdef QT_DEBUG
        qDebug() << "Adding GameElement failed!";
#endif
        delete ge;
    }

#ifdef QT_DEBUG
    if (xml.hasError()) {
        qDebug() << "Error Type:    " << xml.error();
        qDebug() << "Error String:  " << xml.errorString();
        qDebug() << "Line Number:   " << xml.lineNumber();
        qDebug() << "Column Number: " << xml.columnNumber();
        qDebug() << "Char. Offset:  " << xml.characterOffset();
    }
#endif
    return !xml.error();
}

void XmlReader::processImage(IGameElementData* element) {
    auto& xml = pImpl->m_xml;

    Q_ASSERT(xml.isStartElement() && xml.name() == "image");

    while (xml.readNextStartElement()) {
        if (xml.name() == "path") {
            element->setImagePath(xml.readElementText());
        }
    }

    if (element->imagePath().isEmpty()) {
        xml.raiseError("No path for image!");
    }
}

void XmlReader::processSound(IGameElementData* element) {
    auto& xml = pImpl->m_xml;

    Q_ASSERT(xml.isStartElement() && xml.name() == "sound");

    xml.readNext();
    auto text = xml.text();
    if (!text.isEmpty()) {
        element->setSoundPath(text.toString());
    }
}

void XmlReader::processTranslation(IGameElementData* element) {
    auto& xml = pImpl->m_xml;

    Q_ASSERT(xml.isStartElement() && xml.name() == "translation");

    while (xml.readNextStartElement()) {
        auto lang = xml.name().toString();
        auto text = xml.readElementText();
        element->setTranslation(lang, text);
    }
}
