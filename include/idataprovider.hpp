#ifndef IDATAPROVIDER_HPP
#define IDATAPROVIDER_HPP

class IGameElementData;
class QString;

/**
 * @brief Data Provider Interface.
 *
 */
class IDataProvider {
public:
    /**
     * @brief The virtual destructor.
     *
     */
    virtual ~IDataProvider() {}

    /**
     * @brief Get IGameElementData pointer for a given key.
     *
     * @param key String key representation.
     * @return IGameElementData.
     */
    virtual IGameElementData* getDataElement(const QString& key) = 0;

    /**
     * @brief Get data provider name.
     *
     * @return QString Data provider name.
     */
    virtual QString getProviderName() const = 0;
};

#endif // IDATAPROVIDER_HPP
