#include "qttest/squares/SquareManager.h"

namespace qttest {

    SquareManager::SquareManager(QGraphicsScene *graphicsScene) : scene{graphicsScene} {}

    SquareController *SquareManager::getTopSquare() {
        if (squares.empty()) {
            return nullptr;
        }
        return squares[squares.size() - 1];
    }

    int SquareManager::detectCollisionWith(double x, double y) {
        for (int i = squares.size() - 1; i >= 0; i--) {
            SquareController *square = squares[i];
            if (square->containsPoint(x, y)) {
                return i;
            }
        }
        return -1;
    }

    SquareController *SquareManager::getSquareByLocation(double x, double y) {
        int collisionIndex = detectCollisionWith(x, y);

        if (collisionIndex < 0) {
            return nullptr;
        }

        if (getTopSquare() != nullptr) {
            getTopSquare()->switchHighlight(false);
        }
        auto rotationIterator = squares.begin() + collisionIndex;
        std::rotate(rotationIterator, rotationIterator + 1, squares.end());
        refreshZIndexes();
        if (getTopSquare() != nullptr) {
            getTopSquare()->switchHighlight(true);
        }
        return getTopSquare();
    }

    SquareManager::~SquareManager() {
        for (SquareController *square: squares) {
            delete square;
        }
    }

    SquareController *SquareManager::addSquare(double posX, double posY, double size) {
        SquareController *newSquare = new SquareController{scene, posX, posY, size};
        newSquare->setZIndex(squares.size());
        if (getTopSquare() != nullptr) {
            getTopSquare()->switchHighlight(false);
        }
        squares.push_back(newSquare);
        getTopSquare()->switchHighlight(true);
        return newSquare;
    }

    void SquareManager::ensureBorders(double windowWidth, double windowHeight) {
        for (SquareController *square: squares) {
            square->ensureBorders(windowWidth, windowHeight);
        }
    }

    void SquareManager::refreshZIndexes() {
        for (int i = 0; i < squares.size(); i++) {
            SquareController *square = squares[i];
            square->setZIndex(i);
        }
    }

}// namespace qttest
