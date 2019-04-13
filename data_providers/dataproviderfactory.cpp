#include "dataproviderfactory.hpp"
#include "configbaseddataprovider.hpp"
#include "textdataprovider.hpp"

#include "gamesettings.hpp"
#include "idataprovider.hpp"
#include "dataprovider_common.hpp"

DataProviderFactory::DataProviderFactory() {

}

DataProviderFactory::~DataProviderFactory() = default;

QList<IDataProvider*>& DataProviderFactory::buildProvidersList(
        QList<IDataProvider*>& providersList) const {

    Q_ASSERT(providersList.empty());
    GameSettings& settings = GameSettings::getInstance();

    for (const auto& type : settings.getDataProviders()) {
        auto provider = makeProvider(type);
        if (provider != nullptr) {
            providersList.push_back(provider);
        }
    }
    return providersList;
}

IDataProvider*DataProviderFactory::makeProvider(
        const DataProvider::Provider& type) const {
    IDataProvider* provider = nullptr;
    if (type == DataProvider::Provider::Text) {
        provider = new TextDataProvider;
    } else if (type == DataProvider::Provider::ConfigBased) {
        provider = new ConfigBasedDataProvider;
    }
    return provider;
}

