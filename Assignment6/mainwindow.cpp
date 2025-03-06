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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // from view to model connections
    // Connect blue button
    // connect(ui->bluePushButton,
    //         &QPushButton::clicked,
    //         model,
    //         &Model::pressedBlue);

    // // Connect red button
    // connect(ui->redPushButton,
    //         &QPushButton::clicked,
    //         model,
    //         &Model::pressedRed);

    // // Connect start button
    // connect(ui->startPushButton,
    //         &QPushButton::clicked,
    //         model,
    //         &Model::startGame);



    // // from model to view connections
    // // Connect progress bar
    // connect(model,
    //         &Model::updateProgressBar,
    //         ui->progressBar,
    //         &QProgressBar::setValue);   // is this the right slot??



}

MainWindow::~MainWindow()
{
    delete ui;
}

