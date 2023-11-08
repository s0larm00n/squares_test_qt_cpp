#ifndef SQUARES_TEST_QT_CPP_SQUAREMANAGER_H
#define SQUARES_TEST_QT_CPP_SQUAREMANAGER_H

#include "qttest/squares/SquareController.h"
#include <algorithm>
#include <vector>

namespace qttest {

    class SquareManager {
    private:
        std::vector<SquareController *> squares{};
        QGraphicsScene *scene;
        int detectCollisionWith(double x, double y);
        void refreshZIndexes();

    public:
        explicit SquareManager(QGraphicsScene *graphicsScene);
        SquareController *getTopSquare();
        SquareController *getSquareByLocation(double x, double y);
        SquareController *addSquare(double posX, double posY, double size);
        void ensureBorders(double windowWidth, double windowHeight);
        ~SquareManager();
    };

}// namespace qttest

#endif//SQUARES_TEST_QT_CPP_SQUAREMANAGER_H
