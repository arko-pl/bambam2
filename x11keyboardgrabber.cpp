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
