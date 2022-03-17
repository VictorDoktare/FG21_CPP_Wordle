#include <iostream>
#include "Word.h"
#include "Input.h"

enum class GameState : int
{
    GuessWord = 1,
    RestartGame = 2,
    EndGame = 3
};

int main()
{

    Word word;
    Input input(word);
    GameState gameState = GameState::GuessWord;

    int guessCounter = 6;
    bool isRunning {true};

    //Game Loop
    while (isRunning)
    {
	    switch (gameState)
	    {
	    case GameState::GuessWord:
		{
            std::cout << "\n" << "Attempts Left: " << guessCounter << "\n";
            std::cout << "Guess: ";
            input.setGuessInput();
            guessCounter--;

            if (word.compareInput(input.getInput()) || guessCounter == 0)
            {
                gameState = GameState::RestartGame;
            }
            break;
		}
	    case GameState::RestartGame:
        {
            std::cout << "The answer was: " << word.getAnswer() << "\n";
            std::cout << "Do you want to play again? (yes/no)\n";

            input.setRestartInput();

            if (input.getInput() == "YES")
            {
                word.setAnswer();
                std::cout << "\n" << "~NEW WORD IS GENERATED~" << "\n";
                guessCounter = 6;
                gameState = GameState::GuessWord;
            }
            else if (input.getInput() == "NO")
            {
                gameState = GameState::EndGame;
            }
            else
            {
                std::cout << "\n" << "Input not valid.";
            }

            break;
        }
        case GameState::EndGame:
        {
            isRunning = false;
            break;
        }
	    }
    }


    return 0;
}