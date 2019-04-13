#ifndef CHARBASEDRETRIEVESTRATEGY_HPP
#define CHARBASEDRETRIEVESTRATEGY_HPP

#include "iretrievestrategy.hpp"
#include "pimpl.hpp"
#include "typedefs.hpp"

class CharBasedRetrieveStrategyImpl;

/**
 * @brief Character Based Retrieve Strategy.
 *
 * Class responsible for extracting element from GameElementMap according
 * to the key pressed on the keyboard.
 */
class CharBasedRetrieveStrategy : public IRetrieveStrategy
{
public:
    /**
     * @brief The constructor.
     *
     * @param elements mapping with starting character as key and
     * IGameElementData pointer as value.
     */
    CharBasedRetrieveStrategy(const GameElementMap&);
    /**
     * @brief The destructor.
     *
     */
    ~CharBasedRetrieveStrategy();

    // IRetrieveStrategy interface
    /**
     * @brief Get IGameElementData pointer.
     *
     * Returns the IGameElementData from elements map in following manner:
     * Get values from GameElementMap that starts with the same character
     * as key pressed. If any exist return one pointer selected randomly.
     *
     * @param key String representation of pressed key.
     * @return IGameElementData
     */
    IGameElementData* getElement(const QString&) const override;
private:
    CharBasedRetrieveStrategy(const CharBasedRetrieveStrategy&) = delete;
    CharBasedRetrieveStrategy& operator=(
            const CharBasedRetrieveStrategy&) = delete;

    PImpl<CharBasedRetrieveStrategyImpl> pImpl; /**< Pointer to the
                                                implementation.*/
};

#endif // CHARBASEDRETRIEVESTRATEGY_HPP
