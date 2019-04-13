#include "maindialog.hpp"
#include <QApplication>

#include <memory>

#include "game.hpp"
#include "ikeyboardgrabber.hpp"

#ifdef Q_OS_LINUX
#include "x11keyboardgrabber.hpp"
#endif

std::unique_ptr<IKeyboardGrabber> createKeyboardGrabber() {
#ifdef Q_OS_LINUX
    return std::make_unique<X11KeyboardGrabber>();
#else
    return nullptr;
#endif
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainDialog firstDialog;
    std::unique_ptr<IKeyboardGrabber> keyboardGrabber = createKeyboardGrabber();

    if (keyboardGrabber != nullptr) {
        keyboardGrabber->grabKeyboard();
    }
    Game game(&app);

    QObject::connect(&firstDialog, &MainDialog::quitPressed,
                     &app, QApplication::quit);
    QObject::connect(&firstDialog, &MainDialog::newGamePressed,
                     [&firstDialog, &game] {
        firstDialog.close();
        game.startGame();
    });

    firstDialog.show(); //FullScreen();

    auto result = app.exec();

    if (keyboardGrabber != nullptr) {
        keyboardGrabber->releaseKeyboard();
    }

    return result;
}
