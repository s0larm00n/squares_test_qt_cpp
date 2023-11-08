#include "qttest/squares/SquareController.h"

namespace qttest {

    SquareController::SquareController(QGraphicsScene *graphicsScene, double posX, double posY, double size)
        : graphicsItem{posX, posY, size, size}, scene{graphicsScene} {
        graphicsItem.setBrush(getRandomColor());
        scene->addItem(&graphicsItem);
    }

    SquareController::~SquareController() {
        scene->removeItem(&graphicsItem);
    }

    bool SquareController::containsPoint(double x, double y) {
        return graphicsItem.rect().contains(QPointF{x, y});
    }

    void SquareController::moveBy(double deltaX, double deltaY) {
        graphicsItem.setRect(
                graphicsItem.rect().x() + deltaX,
                graphicsItem.rect().y() + deltaY,
                graphicsItem.rect().width(),
                graphicsItem.rect().height()
        );
        // TODO this produced random render and actual coordinates desynchronization - why?
        //graphicsItem.moveBy(deltaX, deltaY);
    }

    void SquareController::ensureBorders(double windowWidth, double windowHeight) {
        if (graphicsItem.rect().x() < 0) {
            graphicsItem.setRect(0, graphicsItem.rect().y(), graphicsItem.rect().width(), graphicsItem.rect().height());
        }
        if (graphicsItem.rect().x() + graphicsItem.rect().width() > windowWidth) {
            graphicsItem.setRect(
                    windowWidth - graphicsItem.rect().width(),
                    graphicsItem.rect().y(),
                    graphicsItem.rect().width(),
                    graphicsItem.rect().height()
            );
        }
        if (graphicsItem.rect().y() < 0) {
            graphicsItem.setRect(graphicsItem.rect().x(), 0, graphicsItem.rect().width(), graphicsItem.rect().height());
        }
        if (graphicsItem.rect().y() + graphicsItem.rect().height() > windowHeight) {
            graphicsItem.setRect(
                    graphicsItem.rect().x(),
                    windowHeight - graphicsItem.rect().height(),
                    graphicsItem.rect().width(),
                    graphicsItem.rect().height()
            );
        }
    }

    void SquareController::switchHighlight(bool value) {
        if (value) {
            QPen whitePen(Qt::white);
            whitePen.setWidth(5);
            graphicsItem.setPen(whitePen);
        } else {
            QPen transparentPen(Qt::transparent);
            graphicsItem.setPen(transparentPen);
        }
    }

    void SquareController::setZIndex(int index) {
        graphicsItem.setZValue(index);
    }

    bool SquareController::canMoveFurther(double deltaX, double deltaY, double windowWidth, double windowHeight) {
        return graphicsItem.rect().x() + deltaX >= 0 && graphicsItem.rect().y() + deltaY >= 0 &&
               graphicsItem.rect().x() + graphicsItem.rect().width() + deltaX <= windowWidth &&
               graphicsItem.rect().y() + graphicsItem.rect().height() + deltaY <= windowHeight;
    }

}// namespace qttest
