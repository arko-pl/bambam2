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
