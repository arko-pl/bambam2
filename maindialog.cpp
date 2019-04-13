#include "maindialog.hpp"
#include <QPushButton>
#include <QVBoxLayout>

MainDialog::MainDialog(QWidget* parent) :
    QDialog(parent) {

    QVBoxLayout *mainLayout = new QVBoxLayout;

    buttonNewGame = new QPushButton(tr("New Game"));
    buttonSettings = new QPushButton(tr("Settings"));
    buttonQuit = new QPushButton(tr("Quit"));

    connect(buttonNewGame, &QPushButton::pressed,
            this, &MainDialog::newGamePressed);
    connect(buttonSettings, &QPushButton::pressed,
            this, &MainDialog::settingsPressed);
    connect(buttonQuit, &QPushButton::pressed,
            this, &MainDialog::quitPressed);

    mainLayout->addWidget(buttonNewGame);
    mainLayout->addWidget(buttonSettings);
    mainLayout->addWidget(buttonQuit);

    this->setLayout(mainLayout);
}

MainDialog::~MainDialog() {

}
