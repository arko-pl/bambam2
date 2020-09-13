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
#include "providerselector.hpp"

#include <QList>

#include "dataproviderfactory.hpp"

/**
 * @brief Provider Selector Implementation Class.
 *
 */
class ProviderSelectorImpl {
public:
    friend class ProviderSelector;
    ProviderSelectorImpl() : m_providers(), m_providersFactory() {}
private:
    QList<IDataProvider*> m_providers; /**< List with pointers to data
                                            providers. */
    DataProviderFactory m_providersFactory; /**< Providers factory. */
};

ProviderSelector::ProviderSelector() {
    pImpl = std::make_unique<ProviderSelectorImpl>();

    buildProvidersList();
    Q_ASSERT(!pImpl->m_providers.isEmpty());
}

ProviderSelector::~ProviderSelector() {
    for (auto provider : pImpl->m_providers) {
        delete provider;
    }
}

IGameElementData* ProviderSelector::getDataElement(const QString& key) {
    IDataProvider* primaryProvider = pImpl->m_providers.at(0);
    IGameElementData* element = primaryProvider->getDataElement(
                key);
    if (element != nullptr) {
        return element;
    }

    for (const auto provider : pImpl->m_providers) {
        if (provider != primaryProvider) {
            if ((element = provider->getDataElement(key)) != nullptr) {
                return element;
            }
        }
    }

    return element;
}

void ProviderSelector::buildProvidersList() {
    pImpl->m_providersFactory.buildProvidersList(pImpl->m_providers);
}
