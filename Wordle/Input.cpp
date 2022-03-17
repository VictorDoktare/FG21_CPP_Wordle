#include "Input.h"

Input::Input(Word &word) : word(&word){}

void Input::setGuessInput()
{
	std::cin >> input;

	//Validify input
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);

	if (!checkValidity(input))
	{
		std::cout << "\n" << "Input can not contain numerical or special letters\n";
		std::cout << "Guess: ";
		setGuessInput();
	}

	if (input.length() > word->getAnswer().length() || input.length() < word->getAnswer().length())
	{
		std::cout << "\n" << "Input needs to be " << word->getAnswer().length() << " letters.\n";
		std::cout << "Guess: ";
		setGuessInput();
	}

	input = this->input;
}

void Input::setRestartInput()
{
	std::cin >> input;

	//Validify input
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);

	input = this->input;
}

std::string Input::getInput()
{
	return this->input;
}

//Check input against valid characters.
bool Input::checkValidity(std::string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (ALLOWED_CHARS.find(input[i]) == std::string::npos)
		{
			return false;
		}
	}

	return true;
}