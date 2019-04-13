#ifndef RANDOMRETRIEVESTRATEGY_HPP
#define RANDOMRETRIEVESTRATEGY_HPP

#include "iretrievestrategy.hpp"
#include "pimpl.hpp"
#include "typedefs.hpp"

class RandomRetrieveStrategyImpl;

/**
 * @brief Random Value Based Retrieve Strategy.
 *
 * Class responsible for extracting element from GameElementMap randomly.
 */
class RandomRetrieveStrategy : public IRetrieveStrategy
{
public:
    /**
     * @brief The constructor.
     *
     * @param elements mapping with starting character as key and
     * IGameElementData pointer as value.
     */
    // FIXME: review this
    RandomRetrieveStrategy(const GameElementMap&);
    /**
     * @brief The destructor.
     *
     */
    ~RandomRetrieveStrategy();

    // IRetrieveStrategy interface
    /**
     * @brief Get IGameElementData pointer.
     *
     * Returns the randomly selected IGameElementData from elements map.
     *
     * @param unused.
     * @return IGameElementData
     */
    IGameElementData* getElement(const QString&) const override;
private:
    RandomRetrieveStrategy(const RandomRetrieveStrategy&) = delete;
    RandomRetrieveStrategy& operator=(const RandomRetrieveStrategy&) = delete;

    PImpl<RandomRetrieveStrategyImpl> pImpl; /**< Pointer to the
                                                implementation. */
};

#endif // RANDOMRETRIEVESTRATEGY_HPP
