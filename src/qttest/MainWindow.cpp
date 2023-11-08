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
        squareManager.ensureBorders(width(), height());
    }

    void MainWindow::handlePointerEvent(QGraphicsSceneMouseEvent *event) {
        switch (event->type()) {
            case QEvent::GraphicsSceneMousePress: {
                focusedSquare = squareManager.getSquareByLocation(event->scenePos().x(), event->scenePos().y());
                if (focusedSquare == nullptr) {
                    double newSquareSize = std::min(width(), height()) / 10.;
                    focusedSquare = squareManager.addSquare(
                            event->scenePos().x() - newSquareSize / 2.,
                            event->scenePos().y() - newSquareSize / 2.,
                            newSquareSize
                    );
                    focusedSquare->ensureBorders(width(), height());
                }
                focusedSquare->switchHighlight(true);
                break;
            }
            case QEvent::GraphicsSceneMouseMove: {
                break;
            }
            case QEvent::GraphicsSceneMouseRelease: {
                if (focusedSquare != nullptr) {
                    focusedSquare->switchHighlight(false);
                }
                focusedSquare = nullptr;
                break;
            }
            default: {
                // Do nothing
            }
        }
    }

}// namespace qttest
