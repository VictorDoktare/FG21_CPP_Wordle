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


    while (isRunning)
    {
	    switch (gameState)
	    {
	    case GameState::GuessWord:
		{
            std::cout << "Attempts Left: " << guessCounter << "\n";
            std::cout << "Guess: ";
            input.setInput();
            guessCounter--;

            if (word.compareInput(input.getInput()) || guessCounter == 0)
            {
                gameState = GameState::RestartGame;
            }
            break;
		}
	    case GameState::RestartGame:
        {
            std::cout << '\n' << "Game Restarting";
            break;
        }
        case GameState::EndGame:
        {
            std::cout << '\n' << "Game Restarting";
            isRunning = false;
            break;
        }
	    }
    }


    return 0;
}