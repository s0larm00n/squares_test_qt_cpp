#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qttest/EventListenerScene.h"
#include "qttest/Util.h"
#include "qttest/squares/SquareManager.h"
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMouseEvent>

namespace qttest {

    class MainWindow : public QMainWindow {
    private:
        Q_OBJECT
        EventListenerScene scene{this};
        SquareManager squareManager{&scene};
        SquareController *focusedSquare = nullptr;

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow() override = default;

    protected:
        void resizeEvent(QResizeEvent *event) override;

    private slots:
        void handlePointerEvent(QGraphicsSceneMouseEvent *event);

    private:
        void updateSceneRect();
    };

}// namespace qttest

#endif// MAINWINDOW_H
