#ifndef PROVIDERSELECTOR_HPP
#define PROVIDERSELECTOR_HPP

#include "pimpl.hpp"
#include "idataprovider.hpp"

class QString;
class IGameElementData;
class ProviderSelectorImpl;

// FIXME: provider selector should return provider that can handle specific
// keypress, itroduce architecture that will support that
/**
 * @brief Data Provider Selector.
 *
 */
class ProviderSelector : public IDataProvider
{
public:
    /**
     * @brief The constructor.
     *
     */
    ProviderSelector();
    /**
     * @brief The destructor.
     *
     */
    ~ProviderSelector();
    IGameElementData* getDataElement(const QString& key) override;
    QString getProviderName() const override;
private:
    ProviderSelector(const ProviderSelector&) = delete;
    ProviderSelector& operator=(const ProviderSelector&) = delete;
    /**
     * @brief Build data providers list.
     *
     * Allocate needed providers and add them to the list.
     */
    void buildProvidersList();

    PImpl<ProviderSelectorImpl> pImpl; /**< Pointer to the implementation. */

};

#endif // PROVIDERSELECTOR_HPP
