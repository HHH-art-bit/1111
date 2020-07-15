#include <QApplication>
#include <QWidget>
#include <QPainter>
#include "qwidgetdraw.h"

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);
    QWidgetDraw drawWin;
    drawWin.show();

    return a.exec();
}
