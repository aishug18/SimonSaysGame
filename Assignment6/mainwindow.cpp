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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(Model* model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    /* FROM VIEW TO MODEL CONNECTIONS */

    // Connect startPushButton to startGame
    connect(ui->startPushButton,
            &QPushButton::clicked,
            model,
            &Model::startGame);

    // Player clicked redPushButton
    connect(ui->redPushButton,
            &QPushButton::clicked,
            model,
            &Model::pressedRed);

    // Player clicked bluePushButton
    connect(ui->bluePushButton,
            &QPushButton::clicked,
            model,
            &Model::pressedBlue);





    /* FROM MODEL TO VIEW CONNECTIONS */

    // Update progressBar
    connect(model,
            &Model::updateProgress,
            ui->progressBar,
            &QProgressBar::setValue);

    // Flash redPushButton to bright red
    connect(model,
            &Model::lightUpRed,
            this,
            &MainWindow::flashRed);

    // Flash bluePushButton to bright blue
    connect(model,
            &Model::lightUpBlue,
            this,
            &MainWindow::flashBlue);

    // It's the player's turn now
    connect(model,
            &Model::playerTurn,
            this,
            &MainWindow::enableRedAndBlueButtons);

    // Game over, display gameOverLabel
    connect(model,
            &Model::gameOver,
            this,
            &MainWindow::displayGameOverLabel);

    // It's the computer's turn to display the sequence
    connect(model,
            &Model::computerTurn,
            this,
            &MainWindow::disableRedAndBlueButtons);



    /* FROM VIEW TO VIEW CONNECTIONS */

    // Disable startPushButton after clicked
    connect(ui->startPushButton,
            &QPushButton::clicked,
            this,
            &MainWindow::disableStart);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::flashRed(int interval, int position) {
    QTimer::singleShot(interval*(position+1), this, [this]{ui->redPushButton->setStyleSheet(QString("QPushButton {background-color: red;}"));
    ui->redPushButton->update();});
    QTimer::singleShot(interval*(position+1) + interval, this, [this]{ui->redPushButton->setStyleSheet(QString("QPushButton {background-color: darkRed;}"));
    ui->redPushButton->update();})
    // ui->redPushButton->setStyleSheet(QString("QPushButton {background-color: red;}"));
    // after some time, go back to original color
    // more work to do here

    //200ms  400 600 800
    //400    600 800 1000
}

void MainWindow::flashBlue(int interval, int position) {
    QTimer::singleShot(interval*(position+1), this, [this]{ui->bluePushButton->setStyleSheet(QString("QPushButton {background-color: blue;}"));
    ui->bluePushButton->update();});
    QTimer::singleShot(interval*(position+1) + interval, this, [this]{ui->bluePushButton->setStyleSheet(QString("QPushButton {background-color: darkBlue;}"));
    ui->bluePushButton->update();})
    // ui->bluePushButton->setStyleSheet(QString("QPushButton {background-color: blue;}"));
    // after some time, go back to original color
    // more work to do here
}

void MainWindow::enableRedAndBlueButtons() {
    ui->redPushButton->setEnabled(true);
    ui->bluePushButton->setEnabled(true);
}

void MainWindow::disableStart() {
    ui->startPushButton->setEnabled(false);
}

void MainWindow::displayGameOverLabel() {
    ui->gameOverLabel->setStyleSheet("QLabel: {background-color: white; border: black;}");
    ui->gameOverLabel->setText("GAME OVER\nYOU LOSE!!\nclick Start to play again");
    ui->startPushButton->setEnabled(true);
}

void MainWindow::disableRedAndBlueButtons() {
    ui->redPushButton->setEnabled(false);
    ui->bluePushButton->setEnabled(false);
}
