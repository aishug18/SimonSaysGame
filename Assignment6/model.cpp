/**
 * The model for the Simon game.
 * Contains logic for the Simon game, what happens behind the scene.
 *
 * Aishwarya Golakoti and Nicholas Cicalese
 * 13 March 2025
 */

#include "model.h"
#include <random>
#include <QTimer>
#include <QDebug>

Model::Model(QObject *parent)
    : QObject{parent},
    sequence{std::rand() % 2, std::rand() % 2},
    currentPosition(0),
    interval(1000)
{}

void Model::startGame() {
    emit computerTurn();
    displaySequence();
}

void Model::buildSequence() {
    sequence.push_back(std::rand() % 2);
    currentPosition = 0;

    interval -= 10;
    emit computerTurn();
    QTimer::singleShot(1000, this, [this]{displaySequence();});
}

void Model::pressedRed() {
    emit playerLightUpRed(interval);

    if(sequence[currentPosition] == 0) {    // Player is correct
        currentPosition++;

        if(currentPosition >= static_cast<int>(sequence.size())) {
            emit updateProgress(100);
            buildSequence();
        }
        else {
            int progress = (currentPosition/static_cast<double>(sequence.size())) * 100;
            emit updateProgress(progress);
        }
    }
    else {  // Player made a mistake, game over
        resetGame();
        emit gameOver();
    }
}

void Model::pressedBlue() {
    emit playerLightUpBlue(interval);

    if(sequence[currentPosition] == 1) {    // Player is correct
        currentPosition++;

        if(currentPosition >= static_cast<int>(sequence.size())) {
            emit updateProgress(100);
            buildSequence();
        }
        else {
            int progress = (currentPosition/static_cast<double>(sequence.size())) * 100;
            emit updateProgress(progress);
        }
    }
    else {  // Player made a mistake, game over
        resetGame();
        emit gameOver();
    }
}

void Model::displaySequence() {
    emit updateProgress(0);

    for(size_t i = 0; i < sequence.size(); i++) {

        if(sequence[i] == 0) {
            emit lightUpRed(interval, i);
        }
        else {
            emit lightUpBlue(interval, i);
        }
    }

    QTimer::singleShot(interval * sequence.size(), this, [this]{emit playerTurn();});
    //emit playerTurn();  // to enable red and blue buttons
}

void Model::resetGame() {
    sequence.clear();
    currentPosition = 0;
}
