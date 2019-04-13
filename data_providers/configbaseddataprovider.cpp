#include "configbaseddataprovider.hpp"

#include <QMultiHash>
#include <random>

#include "dataprovider_common.hpp"
#include "dirparser.hpp"
#include "xmlfileparser.hpp"
#include "xmlreader.hpp"
#include "igameelementdata.hpp"
#include "iretrievestrategy.hpp"
#include "strategies/strategyselector.hpp"
#include "typedefs.hpp"

/**
 * @brief Configuration Based Data Provider Implementation Class.
 *
 */
class ConfigBasedDataProviderImpl {
public:
    ConfigBasedDataProviderImpl() :
        m_reader(m_elementsMap),
        m_fileParser(&m_reader),
        m_dirParser(&m_fileParser),
        m_strategySelector(m_elementsMap) {}
    friend class ConfigBasedDataProvider;
private:
    GameElementMap m_elementsMap; /**< Mapping with starting character as key
     and IGameElementData pointer as value. */
    XmlReader m_reader; /**< XML file reader. */
    XmlFileParser m_fileParser; /**< XML file parser. */
    DirParser m_dirParser; /**< Directory parser. */
    StrategySelector m_strategySelector; /**< Retrieve strategy selector. */
};

ConfigBasedDataProvider::ConfigBasedDataProvider() {
    pImpl = std::make_unique<ConfigBasedDataProviderImpl>();

    // FIXME: get directories to parse from configuration
    pImpl->m_dirParser.parse("data/animals");
}

ConfigBasedDataProvider::~ConfigBasedDataProvider() {
    for (auto element : pImpl->m_elementsMap) {
        delete element;
    }
}

IGameElementData* ConfigBasedDataProvider::getDataElement(const QString& key) {
    return pImpl->m_strategySelector.getStrategy(key)->getElement(key);
}

QString ConfigBasedDataProvider::getProviderName() const {
    return DataProvider::ConfigBasedProvider;
}
