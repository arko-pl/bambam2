/*
 * Copyright (C) 2020  Arkadiusz Bubała <arek2407066@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
