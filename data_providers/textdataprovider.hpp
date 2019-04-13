#ifndef TEXTDATAPROVIDER_HPP
#define TEXTDATAPROVIDER_HPP

#include "idataprovider.hpp"
#include "pimpl.hpp"

class TextDataProviderImpl;

/**
 * @brief Text Data Provider.
 *
 * Provides simple data structure with text as a name.
 */
class TextDataProvider : public IDataProvider
{
public:
    /**
     * @brief The constructor.
     *
     */
    TextDataProvider();

    // IDataProvider interface
    /**
     * @brief Get IGameElementData for a given @p key.
     *
     * Sets game data element name to @p key and returns pointer to this data.
     *
     * @param key String key representation.
     * @return IGameElementData.
     */
    IGameElementData* getDataElement(const QString &key) override;
    /**
     * @brief Get data provider name.
     *
     * @return QString Data provider name.
     */
    QString getProviderName() const override;
private:
    TextDataProvider(const TextDataProvider&) = delete;
    TextDataProvider& operator=(const TextDataProvider&) = delete;

    PImpl<TextDataProviderImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // TEXTDATAPROVIDER_HPP
