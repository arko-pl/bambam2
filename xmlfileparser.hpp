#ifndef XMLFILEPARSER_HPP
#define XMLFILEPARSER_HPP

#include "iparser.hpp"
#include "pimpl.hpp"

class QString;
class XmlReader;

class XmlFileParserImpl;

/**
 * @brief XML file Parser Class.
 *
 */
class XmlFileParser : public IParser
{
public:
    /**
     * @brief The constructor.
     *
     * @param reader Pointer to XML Reader.
     */
    XmlFileParser(XmlReader* reader);
    /**
     * @brief The destructor.
     *
     */
    ~XmlFileParser();
    /**
     * @brief Get the information if @p path is parseable.
     *
     * The @p path is parseable if it is an XML file.
     *
     * @param path Path to check.
     * @return bool True if @p path is an XML file, false otherwise.
     */
    bool isParseable(const QString& path) const override;
    /**
     * @brief Parse the XML file.
     *
     * Opens the XML file and calls reader's read() method.
     *
     * @param path Path to the XML file to parse.
     * @return bool True if the parse succeeds, false otherwise.
     */
    bool parse(const QString& path) const override;
private:
    XmlFileParser(const XmlFileParser&) = delete;
    XmlFileParser& operator=(const XmlFileParser&) = delete;

    PImpl<XmlFileParserImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // XMLFILEPARSER_HPP
