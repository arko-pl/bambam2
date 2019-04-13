#ifndef XMLREADER_HPP
#define XMLREADER_HPP

#include <QObject>
#include "pimpl.hpp"
#include "typedefs.hpp"

class QIODevice;
class QXmlStreamReader;
class XmlReaderImpl;

class XmlReader
{
public:
    explicit XmlReader(GameElementMap&);
    ~XmlReader();

    bool read(QIODevice *device);
private:
    XmlReader(const XmlReader&) = delete;
    XmlReader& operator=(const XmlReader&) = delete;

    void processImage(IGameElementData*);
    void processSound(IGameElementData*);
    void processTranslation(IGameElementData*);

    PImpl<XmlReaderImpl> pImpl;
};

#endif // XMLREADER_HPP
