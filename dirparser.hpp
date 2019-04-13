#ifndef DIRPARSER_HPP
#define DIRPARSER_HPP

#include "iparser.hpp"
#include "pimpl.hpp"

class QString;
class XmlReader;

class DirParserImpl;

/**
 * @brief Directory Parser Class.
 *
 */
class DirParser : public IParser
{
public:
    /**
     * @brief The constructor.
     *
     * @param subparser Pointer to the subparser.
     */
    explicit DirParser(IParser* subparser);
    /**
     * @brief The destructor.
     *
     */
    ~DirParser();

    /**
     * @brief Get the information if @p path is parseable.
     *
     * The @p path is parseable if it is a directory.
     *
     * @param path Path to check.
     * @return bool True if @p path is directory, false otherwise.
     */
    bool isParseable(const QString& path) const override;
    /**
     * @brief Parse the directory.
     *
     * Traverse through whole directory and call subparser on all elements.
     *
     * @param path Directory to parse.
     * @return bool True if parsing operation was successfull, false otherwise.
     */
    bool parse(const QString& path) const override;

private:
    DirParser(const DirParser&) = delete;
    DirParser& operator=(const DirParser&) = delete;

    PImpl<DirParserImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // DIRPARSER_HPP
