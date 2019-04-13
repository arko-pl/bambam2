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
