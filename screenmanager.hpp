#ifndef SCREENMANAGER_HPP
#define SCREENMANAGER_HPP

#include <QObject>
#include "pimpl.hpp"

class Randomizer;
class ScreenManagerPrivate;
class QGraphicsItem;
class QGraphicsView;

/**
 * @brief Screen Manager.
 *
 * This class is responsible for managing screens and everything
 * that is displayed on these screens.
 *
 */
class ScreenManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief The constructor.
     *
     * @param randomizer Pointer to the Randomizer instance.
     * @param parent Pointer to QObject parent class.
     */
    explicit ScreenManager(QObject* parent = nullptr);
    /**
     * @brief The destructor.
     *
     */
    ~ScreenManager();
    /**
     * @brief Close all views.
     *
     */
    void close();
    /**
     * @brief Add QGraphicsItem to screen.
     *
     * @param item QGraphicsItem to add.
     */
    void addItem(QGraphicsItem* item);
    /**
     * @brief Show all views.
     *
     * Shows all views in full screen mode. For multiple monitors each view is
     * placed on its screen.
     */
    void show();
private:
    ScreenManager(const ScreenManager&) = delete;
    ScreenManager& operator=(const ScreenManager&) = delete;
    /**
     * @brief Create views.
     *
     * Create view for each screen.
     * For multiple monitor configuration it resizes the scene for the maximum
     * resolution. Each view is paired with its screen, this mapping is stored
     * in m_screenToViewMap.
     *
     */
    void createViews();   
    /**
     * @brief Get scene boundaries that new element will fit to screen.
     *
     * @param sceneRect Scene rectangle.
     * @param itemRect Item rectangle.
     * @return QRectF Scene boundaries.
     */
    QRectF getSceneBoundariesForItem(const QRectF& sceneRect,
                                     const QRectF& itemRect) const;
    /**
     * @brief Get random position on @p sceneRect.
     *
     * @param sceneRect Scene rectangle.
     * @return QPointF Random position coordinates.
     */
    QPointF getRandomPosition(const QRectF& sceneRect) const;
    /**
     * @brief Get random view.
     *
     * @return QGraphicsView Random view.
     */
    QGraphicsView* getRandomView() const;

    PImpl<ScreenManagerPrivate> pImpl; /**< Pointer to the implementation. */
};

#endif // SCREENMANAGER_HPP
