#ifndef KEYPRESSEVENTFILTER_HPP
#define KEYPRESSEVENTFILTER_HPP

#include <QObject>

/**
 * @brief Key Press Event Filter.
 *
 */
class KeyPressEventFilter : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief The constructor.
     *
     * @param parent Pointer to QObject parent.
     */
    explicit KeyPressEventFilter(QObject* parent = nullptr);
    /**
     * @brief The destructor.
     *
     */
    ~KeyPressEventFilter();

signals:
    /**
     * @brief Indicates that key was pressed.
     *
     * @param String representation of key.
     */
    void keyPressed(const QString&) const;

protected:
    /**
     * @brief Filter event.
     *
     * If the event is key press it emits keyPressed() signal with string
     * representation of pressed key.
     *
     * @param obj Event owner QObject.
     * @param event Event object.
     * @return bool True if event has been handled, otherwise returns result of
     * parent event filter.
     */
    bool eventFilter(QObject* obj, QEvent* event) override;

private:
    KeyPressEventFilter(const KeyPressEventFilter&) = delete;
    KeyPressEventFilter& operator=(const KeyPressEventFilter&) = delete;
};

#endif // KEYPRESSEVENTFILTER_HPP
