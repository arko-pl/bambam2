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
#ifndef IKEYBOARDGRABBER_HPP
#define IKEYBOARDGRABBER_HPP


/**
 * @brief Keyboard Grabber Interface
 *
 * Interface for keyboard grabbers used to grab all key press events in the
 * full screen mode.
 */
class IKeyboardGrabber {
public:
    /**
     * @brief Virtual destructor.
     *
     */
    virtual ~IKeyboardGrabber() {}
    /**
     * @brief Grab key press events.
     *
     * @return bool True if keyboard is successfully grabbed. False otherwise.
     */
    virtual bool grabKeyboard() = 0;
    /**
     * @brief Release key press events.
     *
     * @return bool True if keyboard is successfully released. False otherwise.
     */
    virtual bool releaseKeyboard() = 0;
};

#endif // IKEYBOARDGRABBER_HPP
