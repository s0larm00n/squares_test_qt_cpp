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
                break;
            }
            case QEvent::GraphicsSceneMouseMove: {
                if (focusedSquare != nullptr) {
                    qreal deltaX = event->scenePos().x() - event->lastScenePos().x();
                    qreal deltaY = event->scenePos().y() - event->lastScenePos().y();
                    if (focusedSquare->canMoveFurther(deltaX, deltaY, width(), height())) {
                        focusedSquare->moveBy(deltaX, deltaY);
                    }
                }
                break;
            }
            case QEvent::GraphicsSceneMouseRelease: {
                focusedSquare = nullptr;
                break;
            }
            default: {
                // Do nothing
            }
        }
    }

}// namespace qttest
