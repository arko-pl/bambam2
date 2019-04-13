#ifndef SCALEDECORATOR_HPP
#define SCALEDECORATOR_HPP

#include "imagedecorator.hpp"
#include <QtGlobal>

class QSizeF;
class IScalingPolicy;

/**
 * @brief Scale Decorator.
 *
 * Decorator used for scaling inner image.
 */
class ScaleDecorator : public ImageDecorator
{
public:
    /**
     * @brief The constructor.
     *
     * @param provider Pointer to inner IImageProvider.
     * @param policy Scaling policy.
     */
    explicit ScaleDecorator(IImageProvider* provider, IScalingPolicy* policy);
    /**
     * @brief The destructor.
     *
     */
    ~ScaleDecorator();

    // IDataProvider interface
    /**
     * @brief Scale QGraphicsItem according to selected scaling policy.
     *
     * Scale QGraphicsItem according to selected scaling policy.
     *
     * @return QGraphicsItem pointer to scaled image.
     */
    QGraphicsItem* makeItem() override;
private:
    ScaleDecorator(const ScaleDecorator&) = delete;
    ScaleDecorator& operator=(const ScaleDecorator&) = delete;

    IScalingPolicy* m_policy;  /**< Scaling policy. */
};


#endif // SCALEDECORATOR_HPP
