#include "dirparser.hpp"

#include <QDirIterator>
#include <QString>
#include <QList>

/**
 * @brief Directory Parser Implementation Class.
 *
 */
class DirParserImpl {
public:
    DirParserImpl(IParser* subparser) :
        m_subparser(subparser) {}
    friend DirParser;
private:
    IParser* m_subparser; /**< Pointer to the subparser. */
};

DirParser::DirParser(IParser* subparser) {
    pImpl = std::make_unique<DirParserImpl>(subparser);
}

DirParser::~DirParser() = default;

bool DirParser::isParseable(const QString& path) const {
    QFileInfo info(path);
    return info.isDir();
}

bool DirParser::parse(const QString& path) const {
    bool result = true;
    QDirIterator it(path);
    while (it.hasNext()) {
        auto filePath = it.next();
        if (pImpl->m_subparser->isParseable(filePath)) {
            result &= pImpl->m_subparser->parse(filePath);
        }
    }
    return result;
}
