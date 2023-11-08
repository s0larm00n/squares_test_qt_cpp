#ifndef SQUARES_TEST_QT_CPP_SQUARECONTROLLER_H
#define SQUARES_TEST_QT_CPP_SQUARECONTROLLER_H

#include "qttest/Util.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>

namespace qttest {

    class SquareController {
    private:
        QGraphicsRectItem graphicsItem;
        QGraphicsScene *scene;

    public:
        SquareController(QGraphicsScene *graphicsScene, double posX, double posY, double size);
        ~SquareController();
        bool containsPoint(double x, double y);
        void moveBy(double deltaX, double deltaY);
        bool canMoveFurther(double deltaX, double deltaY, double windowWidth, double windowHeight);
        void ensureBorders(double windowWidth, double windowHeight);
        void switchHighlight(bool value);
        void setZIndex(int index);
    };

}// namespace qttest

#endif//SQUARES_TEST_QT_CPP_SQUARECONTROLLER_H
