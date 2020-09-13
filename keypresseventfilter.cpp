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
#include "keypresseventfilter.hpp"

#include <QEvent>
#include <QKeyEvent>

#include <QtDebug>

KeyPressEventFilter::KeyPressEventFilter(QObject* parent) : QObject(parent) {
}

KeyPressEventFilter::~KeyPressEventFilter() = default;

bool KeyPressEventFilter::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        // ignore autorepeat
        if (!keyEvent->isAutoRepeat()) {
            emit keyPressed(keyEvent->text());
        }
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
