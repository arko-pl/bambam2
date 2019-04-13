#ifndef IPARSER_HPP
#define IPARSER_HPP

class QString;

/**
 * @brief The parser interface.
 *
 */
class IParser {
public:
    /**
     * @brief The virtual destructor.
     *
     */
    virtual ~IParser() = default;

    /**
     * @brief Parse element at @p path.
     *
     * @param path.
     * @return bool True if parse operation succeeds, false otherwise.
     */
    virtual bool parse(const QString& path) const = 0;
    /**
     * @brief Is element at @p path parseable within this parser.
     *
     * @param path.
     * @return bool True if element is parseable, false otherwise.
     */
    virtual bool isParseable(const QString& path) const = 0;
};

#endif // IPARSER_HPP
