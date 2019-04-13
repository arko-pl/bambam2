#include "game.hpp"

#include <QApplication>
#include <QHash>
#include <QList>
#include <QScreen>
#include <QWindow>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QtDebug>

#include "igameelementdata.hpp"
#include "gamesettings.hpp"
#include "keypresseventfilter.hpp"
#include "screenmanager.hpp"
#include "data_providers/graphics/factories/graphicsitemfactory.hpp"
#include "data_providers/providerselector.hpp"


class GamePrivate {
public:
    friend class Game;
    explicit GamePrivate(QApplication *app) :
        m_screenManager(),
        m_app(app) {}
    ~GamePrivate() = default;

private:
    GamePrivate(const GamePrivate&) = delete;
    GamePrivate& operator==(const GamePrivate&) = delete;

    ScreenManager m_screenManager;

    ProviderSelector m_providerSelector;
    GraphicsItemFactory m_graphicsFactory;

    std::unique_ptr<KeyPressEventFilter> m_keyPressEventFilter;
    std::unique_ptr<QWidget> m_inputWidget;

    QApplication* m_app;
    QString m_keySequence;
};

Game::Game(QApplication *app, QObject *parent) : QObject(parent) {
    pImpl = std::make_unique<GamePrivate>(app);

    setupInputWidget();
}

Game::~Game() = default;

void Game::handleKeyPress(const QString& keyName) {
    const IGameElementData* element = pImpl->m_providerSelector.getDataElement(
                keyName);
    auto item = pImpl->m_graphicsFactory.makeItem(element);

    if (item != nullptr) {
        pImpl->m_screenManager.addItem(item);
    }
    pImpl->m_keySequence.append(keyName);

    auto validateSequence = [this](QString& seq) {
        if (seq == "quit") {
            this->quitGame();
        }
        if (!QString("quit").startsWith(seq)) {
            seq.clear();
        }
    };

    qDebug() << pImpl->m_keySequence;

    validateSequence(pImpl->m_keySequence);
}

void Game::startGame() {
    pImpl->m_screenManager.show();
    //pImpl->m_inputWidget->setFocus();
}

void Game::createViews() {

}

void Game::setupInputWidget() {
    pImpl->m_keyPressEventFilter = std::make_unique<KeyPressEventFilter>();

    pImpl->m_inputWidget = std::make_unique<QWidget>();
    pImpl->m_inputWidget->setGeometry(0,0,1,1);
    pImpl->m_inputWidget->grabKeyboard();

    pImpl->m_inputWidget->installEventFilter(pImpl->m_keyPressEventFilter.get());

    connect(pImpl->m_keyPressEventFilter.get(),
            &KeyPressEventFilter::keyPressed,
            this,
            &Game::handleKeyPress);
}

void Game::quitGame() {
    pImpl->m_screenManager.close();
}
