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

    QGraphicsRectItem *SquareController::getGraphicsItem() {
        return &graphicsItem;
    }

    bool SquareController::containsPoint(double x, double y) {
        return graphicsItem.contains(QPointF{x, y});
    }

    void SquareController::moveBy(double deltaX, double deltaY) {
        graphicsItem.moveBy(deltaX, deltaY);
    }

    void SquareController::ensureBorders(double windowWidth, double windowHeight) {
        double itemWidth = graphicsItem.rect().width();
        double itemHeight = graphicsItem.rect().height();
        if (graphicsItem.rect().x() < 0) {
            graphicsItem.setRect(0, graphicsItem.rect().y(), graphicsItem.rect().width(), graphicsItem.rect().height());
        }
        if (graphicsItem.rect().x() + itemWidth > windowWidth) {
            graphicsItem.setRect(
                    windowWidth - itemWidth,
                    graphicsItem.rect().y(),
                    graphicsItem.rect().width(),
                    graphicsItem.rect().height()
            );
        }
        if (graphicsItem.rect().y() < 0) {
            graphicsItem.setRect(graphicsItem.rect().x(), 0, graphicsItem.rect().width(), graphicsItem.rect().height());
        }
        if (graphicsItem.rect().y() + itemHeight > windowHeight) {
            graphicsItem.setRect(
                    graphicsItem.rect().x(),
                    windowHeight - itemHeight,
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

}// namespace qttest
