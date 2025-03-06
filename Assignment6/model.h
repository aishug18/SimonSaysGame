#ifndef MODEL_H
#define MODEL_H

/**
 * The model for the Simon game.
 * Contains logic for the Simon game, what happens behind the scene.
 *
 * Aishwarya Golakoti and Nicholas Cicalese
 * 13 March 2025
 */

#include <QObject>
#include <vector>

class Model : public QObject
{
    Q_OBJECT

private:
    std::vector<int> sequence; // store the sequence of colors emitted, red = 0, blue = 1
    int currentPosition;
    void buildSequence();

public:
    explicit Model(QObject *parent = nullptr);

public slots:
    /**
     * Starts the game.
     * Displays the computer-generated sequence.
     * Disables start button and red and blue buttons.
     */
    void startGame();

    /**
     * The player pressed the red button.
     */
    void pressedRed();

    /**
     * The player pressed the blue button.
     */
    void pressedBlue();

    /**
     * Display the computer-generated sequence.
     * After sequence is played, enable red and blue buttons.
     */
    void displaySequence();

    /**
     * Game over, reset the game.
     */
    void resetGame();

signals:
    /**
     * Emitted when the game is over.
     * Disable red and blue buttons, enable start button.
     */
    void gameOver();

    /**
     * Emitted when the red button should be lit, either when the red button is pressed
     * or when the display sequence should emit red.
     */
    void lightUpRed();

    /**
     * Emitted when the blue button should be lit, either when the blue button is pressed
     * or when the display sequence should emit blue.
     */
    void lightUpBlue();

    /**
     * Emitted when the progress bar should be updated.
     * @param percentage of progress
     */
    void updateProgress(int percentage);

};

/*
something creative: playing with sound
Add timer logic in model
*/

#endif // MODEL_H
