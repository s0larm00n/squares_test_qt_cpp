#include "qttest/MainWindow.h"

namespace qttest {

    MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
        QGraphicsView *view = new QGraphicsView(&scene);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setCentralWidget(view);
        updateSceneRect();
        connect(&scene, &EventListenerScene::pointerEvent, this, &MainWindow::handlePointerEvent);
        setStyleSheet("background-color: black;");
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    void MainWindow::resizeEvent(QResizeEvent *event) {
        QMainWindow::resizeEvent(event);
        updateSceneRect();
    }

    void MainWindow::updateSceneRect() {
        scene.setSceneRect(0, 0, width(), height());
        squareManager.ensureBorders(width(), height());
    }

    void MainWindow::handlePointerEvent(QGraphicsSceneMouseEvent *event) {
        switch (event->type()) {
            case QEvent::GraphicsSceneMousePress: {
                squareManager.onPointerDown(event->scenePos().x(), event->scenePos().y(), width(), height());
                break;
            }
            case QEvent::GraphicsSceneMouseMove: {
                qreal deltaX = event->scenePos().x() - event->lastScenePos().x();
                qreal deltaY = event->scenePos().y() - event->lastScenePos().y();
                squareManager.onPointerMove(deltaX, deltaY, width(), height());
                break;
            }
            case QEvent::GraphicsSceneMouseRelease: {
                squareManager.onPointerUp();
                break;
            }
            default: {
                // Do nothing
            }
        }
    }

}// namespace qttest
