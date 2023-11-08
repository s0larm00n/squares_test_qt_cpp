#include "qttest/squares/SquareManager.h"

namespace qttest {

    SquareManager::SquareManager(QGraphicsScene *graphicsScene) : scene{graphicsScene} {}

    const SquareController *SquareManager::getTopSquare() {
        if (squares.empty()) {
            return nullptr;
        }
        return squares[squares.size() - 1];
    }

    int SquareManager::detectCollisionWith(double x, double y) {
        for (int i = 0; i < squares.size(); ++i) {
            SquareController *square = squares[i];
            if (square->containsPoint(x, y)) {
                return i;
            }
        }
        return -1;
    }

    const SquareController *SquareManager::getSquareByLocation(double x, double y) {
        int collisionIndex = detectCollisionWith(x, y);

        if (collisionIndex < 0) {
            return nullptr;
        }

        auto rotationIterator = squares.begin() + collisionIndex;
        std::rotate(rotationIterator, rotationIterator + 1, squares.end());
        return getTopSquare();
    }

    SquareManager::~SquareManager() {
        for (SquareController *square: squares) {
            delete square;
        }
    }

    const SquareController *SquareManager::addSquare(double posX, double posY, double width, double height) {
        SquareController *newSquare = new SquareController{scene, posX, posY, width, height};
        squares.push_back(newSquare);
        return newSquare;
    }

}// namespace qttest
