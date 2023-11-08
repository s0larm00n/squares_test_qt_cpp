#include "qttest/MainWindow.h"

namespace qttest {

    MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
        setCentralWidget(new QGraphicsView(&scene));
        updateSceneRect();
        connect(&scene, &EventListenerScene::pointerEvent, this, &MainWindow::handlePointerEvent);
    }

    void MainWindow::resizeEvent(QResizeEvent *event) {
        QMainWindow::resizeEvent(event);
        updateSceneRect();
    }

    void MainWindow::updateSceneRect() {
        scene.setSceneRect(0, 0, width(), height());
    }

    void MainWindow::handlePointerEvent(QGraphicsSceneMouseEvent *event) {
        if (event->type() == QEvent::GraphicsSceneMousePress) {
            double newSquareSize = std::min(width(), height()) / 10.;
            SquareController *newSquare = squareManager.addSquare(
                    event->scenePos().x() - newSquareSize / 2.,
                    event->scenePos().y() - newSquareSize / 2.,
                    newSquareSize
            );
            newSquare->ensureBorders(width(), height());
        }
    }

}// namespace qttest
