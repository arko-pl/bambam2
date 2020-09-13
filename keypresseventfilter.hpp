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
