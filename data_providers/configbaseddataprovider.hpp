#ifndef CONFIGBASEDDATAPROVIDER_HPP
#define CONFIGBASEDDATAPROVIDER_HPP

#include "idataprovider.hpp"
#include "pimpl.hpp"

class ConfigBasedDataProviderImpl;

/**
 * @brief Configuration Based Data Provider
 *
 * Class responsible for providing game data read from XML configuration files.
 */
class ConfigBasedDataProvider : public IDataProvider
{
public:
    /**
     * @brief The constructor.
     *
     */
    ConfigBasedDataProvider();
    /**
     * @brief The destructor.
     *
     */
    ~ConfigBasedDataProvider();

    // IDataProvider interface
public:
    /**
     * @brief Get IGameElementData for @p key.
     *
     * @param key String key representation.
     * @return IGameElementData.
     */
    IGameElementData* getDataElement(const QString& key) override;
    /**
     * @brief Get data provider name.
     *
     * @return QString Data provider name.
     */
    QString getProviderName() const override;
private:
    ConfigBasedDataProvider(const ConfigBasedDataProvider&) = delete;
    ConfigBasedDataProvider& operator=(const ConfigBasedDataProvider&) = delete;

    PImpl<ConfigBasedDataProviderImpl> pImpl; /**< Pointer to the
                                                   implementation. */
};

#endif // CONFIGBASEDDATAPROVIDER_HPP
