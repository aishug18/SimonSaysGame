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

Model::Model(QObject *parent)
    : QObject{parent},
    sequence{std::rand() % 2},
    currentPosition(0)
{}

void Model::startGame() {
    displaySequence();
}

void Model::buildSequence() {
    sequence.push_back(std::rand() % 2);
    currentPosition = 0;
    emit computerTurn();
    displaySequence();
}

void Model::pressedRed() {
    emit lightUpRed();

    if(sequence[currentPosition] == 0) {    // Player is correct
        currentPosition++;

        if(currentPosition >= static_cast<int>(sequence.size())) {
            emit updateProgress(100);
            // wait, then reset progress to 0.
            buildSequence();
        }
        else {
            emit updateProgress(currentPosition/sequence.size() * 100);
        }
    }
    else {  // Player made a mistake, game over
        resetGame();
        emit gameOver();
    }
}

void Model::pressedBlue() {
    emit lightUpBlue();

    if(sequence[currentPosition] == 1) {    // Player is correct
        currentPosition++;

        if(currentPosition >= static_cast<int>(sequence.size())) {
            emit updateProgress(100);
            // wait, then reset progress to 0
            buildSequence();
        }
        else {
            emit updateProgress(currentPosition/sequence.size() * 100);
        }
    }
    else {  // Player made a mistake, game over
        resetGame();
        emit gameOver();
    }
}

void Model::displaySequence() {
    // use QTimer

    for(size_t i = 0; i < sequence.size(); i++) {
        if(sequence[i] == 0) {
            emit lightUpRed();
        }
        else {
            emit lightUpBlue();
        }
    }

    emit playerTurn();  // to enable red and blue buttons
}

void Model::resetGame() {
    sequence.clear();
    currentPosition = 0;
}
