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
    int currentPosition; // The current position
    int interval; // The time interval in ms between

    /**
     * Build the sequence of colors by adding a new, random color to the end of sequence.
     * Then display the sequence.
     */
    void buildSequence();

    /**
     * Display the computer-generated sequence.
     */
    void displaySequence();

    /**
     * Game over, reset the game.
     */
    void resetGame();

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
    void lightUpRed(int interval, int position);

    /**
     * Emitted when the blue button should be lit, either when the blue button is pressed
     * or when the display sequence should emit blue.
     */
    void lightUpBlue(int interval, int position);

    /**
     * Emitted when the progress bar should be updated.
     * @param percentage of progress
     */
    void updateProgress(int percentage);

    /**
     * Emitted when the player can start pressing buttons, after the computer-generated
     * sequence is displayed.
     */
    void playerTurn();

    /**
     * Emitted when the player finished pressing buttons, and it's time for the computer to
     * display the next sequence.
     */
    void computerTurn();

    /**
     * Emitted when the player finishes the sequence
     */
    void endPlayerSequence();

};

#endif // MODEL_H
