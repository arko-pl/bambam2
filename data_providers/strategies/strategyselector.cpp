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
#include "strategyselector.hpp"

#include "settings/gamesettings.hpp"
#include "settings/settings_common.hpp"
#include "charbasedretrievestrategy.hpp"
#include "iretrievestrategy.hpp"
#include "randomretrievestrategy.hpp"

#include <QString>
#include <QVariant>

class StrategySelectorImpl {
public:
    StrategySelectorImpl(const GameElementMap& elements) :
        m_randomStrategy(elements),
        m_charBasedStrategy(elements),
        m_selectedStrategy(&m_charBasedStrategy)
    {}
    friend class StrategySelector;
private:
    RandomRetrieveStrategy m_randomStrategy;
    CharBasedRetrieveStrategy m_charBasedStrategy;
    IRetrieveStrategy* m_selectedStrategy;
};

StrategySelector::StrategySelector(const GameElementMap& elements) {
    pImpl = std::make_unique<StrategySelectorImpl>(elements);
    const GameSettings& settings = GameSettings::getInstance();
    using namespace Settings::DataProviders;

    const auto retrievalPolicy =
            qvariant_cast<ConfigBased::RetrievalPolicy>(
                settings.getDataProvidersOption(
                    ConfigBased::SUBGROUP,
                    ConfigBased::RETRIEVAL_POLICY));
    // FIXME: Map this from settings
    if (retrievalPolicy == ConfigBased::RetrievalPolicy::Random) {
        pImpl->m_selectedStrategy = &pImpl->m_randomStrategy;
    } else {
        pImpl->m_selectedStrategy = &pImpl->m_charBasedStrategy;
    }
}

StrategySelector::~StrategySelector() = default;

IRetrieveStrategy *StrategySelector::getStrategy(const QString& key) {
    if ((pImpl->m_selectedStrategy == &pImpl->m_charBasedStrategy)
            && (key.isEmpty() || !key.at(0).isPrint())) {
        return &pImpl->m_randomStrategy;
    }
    return pImpl->m_selectedStrategy;
}
