#include "strategyselector.hpp"

#include "gamesettings.hpp"
#include "charbasedretrievestrategy.hpp"
#include "iretrievestrategy.hpp"
#include "randomretrievestrategy.hpp"

#include <QString>

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

    // FIXME: strategies should have their names, poka-yoke violation
    if (settings.getRetrievalPolicy() == "random") {
        pImpl->m_selectedStrategy = &pImpl->m_randomStrategy;
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
