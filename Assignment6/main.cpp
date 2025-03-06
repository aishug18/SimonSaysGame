/**
 * The main application that executes the Simon game.
 *
 * Aishwarya Golakoti and Nicholas Cicalese
 * 13 March 2025
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
