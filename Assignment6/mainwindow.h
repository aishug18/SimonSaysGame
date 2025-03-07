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
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    /**
     * Flash redPushButton to a bright red, then go back to original color after
     * some amount of time.
     */
    void flashRed(int interval, int position);

    void playerFlashRed();

    /**
     * Flash bluePushButton to a bright blue, then go back to original color after
     * some amount of time.
     */
    void flashBlue(int interval, int position);

    void playerFlashBlue();

    /**
     * It's the player's turn now, so enable red and blue push buttons.
     */
    void enableRedAndBlueButtons();

    /**
     * Disable startPushButton since the game has started.
     */
    void disableStart();

    /**
     * The game has ended, so display a "Game over" message and enable startPushButton.
     */
    void displayGameOverLabel();

    /**
     * It's the computer's turn to display the sequence, so disable red and blue
     * push buttons.
     */
    void disableRedAndBlueButtons();

public:
    MainWindow(Model* model, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
