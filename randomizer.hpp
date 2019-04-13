#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <QObject>
#include <QColor>

#include "pimpl.hpp"

class RandomizerPrivate;

/**
 * @brief Randomizer class.
 *
 */
class Randomizer
{
public:
    /**
     * @brief The constructor.
     *
     */
    explicit Randomizer();
    /**
     * @brief The destructor.
     *
     */
    ~Randomizer();

    /**
     * @brief Get random integer in range [@p min, @p max].
     *
     * @param min Minimum value.
     * @param max Maximum value.
     * @return int Random integer.
     */
    int getRandomInt(int min, int max) const;
    /**
     * @brief Get random real value in range [@p min, @p max].
     *
     * @param min Minimum value.
     * @param max Maximum values.
     * @return double Random real.
     */
    double getRandomReal(double min, double max) const;
    /**
     * @brief Get random color.
     *
     * @return QColor Random color.
     */
    QColor getRandomColor() const;
private:
    Randomizer(const Randomizer&) = delete;
    Randomizer& operator=(const Randomizer&) = delete;

    PImpl<RandomizerPrivate> pImpl; /**< Pointer to the implementation. */
};

#endif // RANDOMIZER_HPP
