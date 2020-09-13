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
#ifndef X11KEYBOARDGRABBER_HPP
#define X11KEYBOARDGRABBER_HPP

#include "ikeyboardgrabber.hpp"

/**
 * @brief Keyboard grabber for X11
 *
 */
class X11KeyboardGrabber : public IKeyboardGrabber
{
public:
    /**
     * @brief The constructor.
     *
     */
    X11KeyboardGrabber();
    /**
     * @brief The destructor.
     *
     */
    ~X11KeyboardGrabber();

    // IKeyboardGrabber interface
public:
    /**
     * @brief Grab keyboard.
     *
     * @return bool True if operation succeeds, false otherwise.
     */
    bool grabKeyboard() override;
    /**
     * @brief Release keyboard.
     *
     * @return bool True, false only if QX11Info::display() is nullptr.
     */
    bool releaseKeyboard() override;
};

#endif // X11KEYBOARDGRABBER_HPP
