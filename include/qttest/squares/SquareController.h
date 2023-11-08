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
        QGraphicsRectItem *getGraphicsItem();
        bool containsPoint(double x, double y);
        void moveBy(double deltaX, double deltaY);
        void ensureBorders(double windowWidth, double windowHeight);
    };

}// namespace qttest

#endif//SQUARES_TEST_QT_CPP_SQUARECONTROLLER_H
