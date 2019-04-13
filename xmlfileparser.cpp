#include "xmlfileparser.hpp"

#include <QFile>
#include <QString>

#include "xmlreader.hpp"

/**
 * @brief XML File Parser Implementation.
 *
 */
class XmlFileParserImpl {
public:
    XmlFileParserImpl(XmlReader* reader) :
        m_reader(reader) {}
    friend XmlFileParser;
private:
    XmlReader* m_reader; /**< Pointer to the reader class. */
};

XmlFileParser::XmlFileParser(XmlReader *reader) {
    pImpl = std::make_unique<XmlFileParserImpl>(reader);
}

XmlFileParser::~XmlFileParser() = default;

bool XmlFileParser::isParseable(const QString& path) const {
    return (path.endsWith("xml", Qt::CaseSensitive));
}

bool XmlFileParser::parse(const QString& path) const {
    bool result;
    QFile xmlFile(path);

    if ((result = xmlFile.open(QIODevice::ReadOnly))) {
        result = pImpl->m_reader->read(&xmlFile);
    }

    return result;
}
