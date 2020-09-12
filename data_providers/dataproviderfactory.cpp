#include "dataproviderfactory.hpp"

#include <unordered_map>
#include <QVariant>
#include "configbaseddataprovider.hpp"
#include "textdataprovider.hpp"

#include "settings/gamesettings.hpp"
#include "settings/settings_common.hpp"
#include "idataprovider.hpp"


namespace DataProvider {
    constexpr Provider fromSettings(
        Settings::DataProviders::Type type) {
        switch(type) {
            case Settings::DataProviders::Type::ConfigBased:
                return Provider::ConfigBased;
            case Settings::DataProviders::Type::Text:
            default:
                return Provider::Text;
        }
    }
}

DataProviderFactory::DataProviderFactory() {

}

DataProviderFactory::~DataProviderFactory() = default;

QList<IDataProvider*>& DataProviderFactory::buildProvidersList(
        QList<IDataProvider*>& providersList) const {

    Q_ASSERT(providersList.empty());
    GameSettings& settings = GameSettings::getInstance();

    // FIXME: add option to game settings
    for (const auto& type :
         qvariant_cast<QList<Settings::DataProviders::Type>>(settings.getGeneralOption(Settings::General::SELECTED_PROVIDERS))) {
        auto provider = makeProvider(DataProvider::fromSettings(type));
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

