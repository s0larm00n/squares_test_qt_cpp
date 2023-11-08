#include "qttest/EventListenerScene.h"

namespace qttest {

    EventListenerScene::EventListenerScene(QMainWindow *mainWindow) : QGraphicsScene{mainWindow} {}

    void EventListenerScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
        emit pointerEvent(event);
        QGraphicsScene::mousePressEvent(event);
    }

    void EventListenerScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
        emit pointerEvent(event);
        QGraphicsScene::mouseMoveEvent(event);
    }

    void EventListenerScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
        emit pointerEvent(event);
        QGraphicsScene::mouseReleaseEvent(event);
    }

}// namespace qttest
