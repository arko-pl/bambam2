#include "charbasedretrievestrategy.hpp"

#include <QMultiHash>
#include <QString>

#include "randomizer.hpp"

class CharBasedRetrieveStrategyImpl {
public:
    CharBasedRetrieveStrategyImpl(const GameElementMap& elements) :
        m_elements(elements),
        m_randomizer() { }
    friend class CharBasedRetrieveStrategy;
private:
    const GameElementMap& m_elements;
    Randomizer m_randomizer;
};

CharBasedRetrieveStrategy::CharBasedRetrieveStrategy(
        const GameElementMap& elements) {
    pImpl = std::make_unique<CharBasedRetrieveStrategyImpl>(elements);
}

CharBasedRetrieveStrategy::~CharBasedRetrieveStrategy() = default;


IGameElementData* CharBasedRetrieveStrategy::getElement(
        const QString& key) const {
    Q_ASSERT(!key.isEmpty());

    QChar k = key.at(0);
    const auto& values = pImpl->m_elements.values(k);
    auto count = values.count();
    if (count == 0) {
        return nullptr;
    } else if (count == 1) {
        return values.at(0);
    } else {
        auto index = pImpl->m_randomizer.getRandomInt(0, count - 1);
        return values.at(index);
    }
}
