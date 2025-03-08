/**
 * The main application that executes the Simon game.
 *
 * Team: Aishwarya Golakoti and Nicholas Cicalese
 * GitHub Usernames: Aishwarya1036 and ncicalese
 * URL of GitHub Repository: https://github.com/UofU-CS3505/cs3505-assignment6-Aishwarya1036
 *
 * Description of Creative Element:
 *
 * We chose to add sound effects to our Simon game. Sound effects play whenever a button is lit up by a player or the computer, when the player completes a round successfully, and when
 * the player loses the game. To add the sound effects, we used QMediaPlayer and QAudioOutput from the QMultimedia library. To gain access to the .mp3 files, we added a .qrc file
 * to the Qt project, which is an XML file that contains information for outside resources that the application can use.
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
