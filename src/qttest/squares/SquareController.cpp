#include "qttest/squares/SquareController.h"

namespace qttest {

    SquareController::SquareController(
            QGraphicsScene *graphicsScene,
            double posX,
            double posY,
            double width,
            double height
    )
        : graphicsItem{posX, posY, width, height}, scene{graphicsScene} {
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
        if (graphicsItem.x() < 0) {
            graphicsItem.setX(0);
        }
        if (graphicsItem.x() + itemWidth > windowWidth) {
            graphicsItem.setX(windowWidth - itemWidth);
        }
        if (graphicsItem.y() < 0) {
            graphicsItem.setY(0);
        }
        if (graphicsItem.y() + itemHeight > windowHeight) {
            graphicsItem.setY(windowHeight - itemHeight);
        }
    }

}// namespace qttest
