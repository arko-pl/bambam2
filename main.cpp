#include "maindialog.hpp"
#include <QApplication>
#include <memory>

#include "game.hpp"
#include "settings/settingscontroller.hpp"

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
    // TODO: move it to the game and create keygrabber factory
    std::unique_ptr<IKeyboardGrabber> keyboardGrabber = createKeyboardGrabber();

    std::unique_ptr<Game> game = nullptr;

    QObject::connect(&firstDialog, &MainDialog::quitPressed,
                     &app, QApplication::quit);
    QObject::connect(&firstDialog, &MainDialog::settingsPressed,
                     [] {
        SettingsController settingsController;
        settingsController.openSettingsDialog();
    });
    QObject::connect(&firstDialog, &MainDialog::newGamePressed,
                     [&firstDialog, &game, &app, &keyboardGrabber] {
        firstDialog.close();
        game = nullptr;
        game = std::make_unique<Game>(&app, std::move(keyboardGrabber));
        QObject::connect(game.get(), &Game::quit,
                         [&firstDialog] { firstDialog.show(); });
        game->startGame();
    });

    firstDialog.show(); //FullScreen();

    auto result = app.exec();

    if (keyboardGrabber != nullptr) {
        keyboardGrabber->releaseKeyboard();
    }

    return result;
}
