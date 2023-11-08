#ifndef SQUARES_TEST_QT_CPP_SQUAREMANAGER_H
#define SQUARES_TEST_QT_CPP_SQUAREMANAGER_H

#include <vector>
#include <algorithm>
#include "qttest/squares/SquareController.h"

namespace qttest {

    class SquareManager {
    private:
        std::vector<SquareController *> squares{};
        QGraphicsScene *scene;
        int detectCollisionWith(double x, double y);
    public:
        explicit SquareManager(QGraphicsScene *graphicsScene);
        const SquareController *getTopSquare();
        const SquareController *getSquareByLocation(double x, double y);
        const SquareController *addSquare(double posX, double posY, double width, double height);
        ~SquareManager();
    };

}// namespace qttest

#endif//SQUARES_TEST_QT_CPP_SQUAREMANAGER_H
