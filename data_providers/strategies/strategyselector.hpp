#ifndef STRATEGYSELECTOR_HPP
#define STRATEGYSELECTOR_HPP

#include "pimpl.hpp"
#include "typedefs.hpp"

class StrategySelectorImpl;
class IRetrieveStrategy;
class QString;

/**
 * @brief Strategy Selector
 *
 * Class responsible for selecting strategy that has sense for the key pressed.
 */
class StrategySelector
{
public:
    /**
     * @brief The constructor.
     *
     * @param elements mapping with starting character as key and
     * IGameElementData pointer as value.
     */
    explicit StrategySelector(const GameElementMap&);
    /**
     * @brief The destructor.
     *
     */
    ~StrategySelector();

    /**
     * @brief Get strategy for a given @p key.
     *
     * Returns strategy that has sense for the key pressed.
     *
     * @param key String key representation.
     * @return IRetrieveStrategy Selected strategy.
     */
    IRetrieveStrategy* getStrategy(const QString& key);
private:
    StrategySelector(const StrategySelector&) = delete;
    StrategySelector& operator=(const StrategySelector&) = delete;

    PImpl<StrategySelectorImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // STRATEGYSELECTOR_HPP
