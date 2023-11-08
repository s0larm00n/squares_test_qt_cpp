#include "qttest/MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    qttest::MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
