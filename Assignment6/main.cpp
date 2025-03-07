/**
 * The main application that executes the Simon game.
 *
 * Team: Aishwarya Golakoti and Nicholas Cicalese
 * GitHub Usernames: Aishwarya1036 and ncicalese
 * URL of GitHub Repository: https://github.com/UofU-CS3505/cs3505-assignment6-Aishwarya1036
 *
 * Description of Creative Element:
 *  __
 *
 *
 * 13 March 2025
 */

#include "mainwindow.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("Fusion");
    Model m;
    MainWindow w(&m);
    w.show();
    return a.exec();
}
