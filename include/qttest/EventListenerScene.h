#ifndef SQUARES_TEST_QT_CPP_EVENTLISTENERSCENE_H
#define SQUARES_TEST_QT_CPP_EVENTLISTENERSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMainWindow>

namespace qttest {

    class EventListenerScene : public QGraphicsScene {
        Q_OBJECT

    public:
        explicit EventListenerScene(QMainWindow *mainWindow);

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    signals:
        void pointerEvent(QGraphicsSceneMouseEvent *event);
    };

}// namespace qttest

#endif//SQUARES_TEST_QT_CPP_EVENTLISTENERSCENE_H
