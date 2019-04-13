#ifndef DATAPROVIDERFACTORY_HPP
#define DATAPROVIDERFACTORY_HPP

template<typename T>
class QList;
class QString;

namespace DataProvider {
    enum class Provider;
}

class IDataProvider;

/**
 * @brief Data Provider Factory Class.
 *
 * Class responsible for creating IDataProvider instances.
 */
class DataProviderFactory
{
public:
    /**
     * @brief The constructor.
     *
     */
    explicit DataProviderFactory();
    /**
     * @brief The destructor.
     *
     */
    ~DataProviderFactory();
    // TODO: consider moving this outside this class and make makeProvider
    // public.
    /**
     * @brief Generate providers list enabled in configuration.
     *
     * @param providersList Providers list that will be filled.
     * @return QList<IDataProvider *> reference to @p providersList.
     */
    QList<IDataProvider*>& buildProvidersList(
            QList<IDataProvider*>& providersList) const;
private:
    DataProviderFactory(const DataProviderFactory&) = delete;
    DataProviderFactory& operator=(const DataProviderFactory&) = delete;
    /**
     * @brief Create data provider of @p type.
     *
     * @param type Type of data provider.
     * @return IDataProvider Pointer to created data provider.
     */
    IDataProvider* makeProvider(const DataProvider::Provider& type) const;
};

#endif // DATAPROVIDERFACTORY_HPP
