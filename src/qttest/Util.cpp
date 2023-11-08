#include "qttest/Util.h"

namespace qttest {

    QColor getRandomColor() {
        int red = QRandomGenerator::global()->bounded(256);
        int green = QRandomGenerator::global()->bounded(256);
        int blue = QRandomGenerator::global()->bounded(256);
        return {red, green, blue};
    }

}
