#ifndef IRETRIEVESTRATEGY_HPP
#define IRETRIEVESTRATEGY_HPP

class QString;
class IGameElementData;

/**
 * @brief Retrieve Strategy Interface.
 *
 */
class IRetrieveStrategy {
public:
    /**
     * @brief The virtual destructor.
     *
     */
    virtual ~IRetrieveStrategy() = default;

    /**
     * @brief Get the IGameElementData pointer for a given @p key.
     *
     * @param key String key representation.
     * @return IGameElementData.
     */
    virtual IGameElementData* getElement(const QString& key) const = 0;
};

#endif // IRETRIEVESTRATEGY_HPP
