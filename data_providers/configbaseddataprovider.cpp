/*
 * Copyright (C) 2020  Arkadiusz Bubała <arek2407066@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "configbaseddataprovider.hpp"

#include <QMultiHash>
#include <random>

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
