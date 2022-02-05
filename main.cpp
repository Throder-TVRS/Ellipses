#include "mainwindow.h"
#include "rasterwindow.h"
#include "movingprocessor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MovingProcessor mp;
    MainWindow w1(&mp);
    w1.show();
    RasterWindow w2(&mp);
    w2.setAnimating(true);
    w2.show();

    return a.exec();
}
