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
#include "x11keyboardgrabber.hpp"

#include <QtX11Extras/QX11Info>
#include <X11/Xlib.h>

X11KeyboardGrabber::X11KeyboardGrabber() {
}

X11KeyboardGrabber::~X11KeyboardGrabber() = default;

//#define DISABLE_GRABBER 1

bool X11KeyboardGrabber::grabKeyboard() {
    Display *display = QX11Info::display();

    if (display == nullptr) {
        return false;
    }
#ifndef DISABLE_GRABBER
    int result = XGrabKeyboard(display,
                               DefaultRootWindow(display),
                               True,
                               GrabModeAsync,
                               GrabModeAsync,
                               CurrentTime);

    XSync(display, False);

    return (result == GrabSuccess);
#else
    return true;
#endif
}

bool X11KeyboardGrabber::releaseKeyboard() {
    Display *display = QX11Info::display();

    if (display == nullptr) {
        return false;
    }

    XUngrabKeyboard(display, CurrentTime);
    XSync(display, False);

    return true;
}
