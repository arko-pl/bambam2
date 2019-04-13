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
