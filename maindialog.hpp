#ifndef MAINDIALOG_HPP
#define MAINDIALOG_HPP

#include <QDialog>

/**
 * @brief Main Dialog Class.
 *
 * This is main dialog displayed on start up.
 */
class MainDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief The constructor.
     *
     */
    MainDialog(QWidget* parent = nullptr);
    /**
     * @brief The destructor.
     *
     */
    ~MainDialog();
signals:
    /**
     * @brief Indicates that "New Game" button has been pressed.
     *
     */
    void newGamePressed() const;
    /**
     * @brief Indicatest that "Quit" button has been pressed.
     *
     */
    void quitPressed() const;
    /**
     * @brief Indicates that "Settings" button has been pressed.
     *
     */
    void settingsPressed() const;
private:
    QPushButton *buttonNewGame; /**< "New Game" button. */
    QPushButton *buttonQuit; /**< "Quit" button. */
    QPushButton *buttonSettings; /**< "Settings" button. */
};

#endif // MAINDIALOG_HPP
