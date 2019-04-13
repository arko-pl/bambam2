#include "randomretrievestrategy.hpp"

#include <QMultiHash>
#include <QString>

#include "igameelementdata.hpp"
#include "randomizer.hpp"

class RandomRetrieveStrategyImpl {
public:
    RandomRetrieveStrategyImpl(const GameElementMap& elements) :
        m_elements(elements),
        m_randomizer() { }
    friend class RandomRetrieveStrategy;
private:
    const GameElementMap& m_elements;

    Randomizer m_randomizer;
};

RandomRetrieveStrategy::RandomRetrieveStrategy(
        const GameElementMap& elements) {
    pImpl = std::make_unique<RandomRetrieveStrategyImpl>(elements);
}

RandomRetrieveStrategy::~RandomRetrieveStrategy() = default;

IGameElementData* RandomRetrieveStrategy::getElement(const QString&) const {
    const auto& values = pImpl->m_elements.values();
    auto index = pImpl->m_randomizer.getRandomInt(0, values.count() - 1);
    return values.at(index);
}
