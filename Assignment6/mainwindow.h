#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * The user interface for the Simon game.
 * The program displays a sequence of buttons that light up, and the player must repeat the
 * sequence by pushing the buttons. If the player successfully repeats the sequence, the program
 * adds an additional button press to the end of the same sequence.
 * If the player makes a mistake, the game is over.
 * The game is not winnable, the sequence will repeat over and over again.
 *
 * Aishwarya Golakoti and Nicholas Cicalese
 * 13 March 2025
 */

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
