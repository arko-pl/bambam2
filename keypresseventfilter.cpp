#include "keypresseventfilter.hpp"

#include <QEvent>
#include <QKeyEvent>

#include <QtDebug>

KeyPressEventFilter::KeyPressEventFilter(QObject* parent) : QObject(parent) {
}

KeyPressEventFilter::~KeyPressEventFilter() = default;

bool KeyPressEventFilter::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        // ignore autorepeat
        if (!keyEvent->isAutoRepeat()) {
            emit keyPressed(keyEvent->text());
        }
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
