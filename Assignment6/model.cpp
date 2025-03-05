#include "model.h"
#include <random>

Model::Model(QObject *parent)
    : QObject{parent},
    sequence{std::rand() % 2},
    currentPosition(0)
{}

void Model::startGame() {
    // display sequence and enable/disable buttons
}

void Model::buildSequence() {
    sequence.push_back(std::rand() % 2);
    currentPosition = 0;
    displaySequence();
}

void Model::pressedRed() {
    emit lightUpRed();
    if(sequence[currentPosition] == 0) {
        // player is correct
        currentPosition++;
        if(currentPosition >= sequence.size()) {    // comparing int to size_t is an issue, fix comparison type
            buildSequence();
            emit updateProgress(100);
            // wait, then reset progress to 0.
        }
        else {
            emit updateProgress(currentPosition/sequence.size() * 100);
        }
    }
    else {
        // game over
        resetGame();
        emit gameOver();
    }
}

void Model::pressedBlue() {
    emit lightUpBlue();
    if(sequence[currentPosition] == 1) {
        // player is correct
        currentPosition++;
        if(currentPosition >= sequence.size()) {
            buildSequence();
            emit updateProgress(100);
            // wait, then reset progress to 0.
        }
        else {
            emit updateProgress(currentPosition/sequence.size() * 100);
        }
    }
    else {
        // game over
        resetGame();
        emit gameOver();
    }
}

void Model::displaySequence() {
    // use QTimer
    // after displaying sequence, enable and disable buttons to allow player to play
}

void Model::resetGame() {
    sequence.clear();
    currentPosition = 0;
    // enable/disable buttons
}
