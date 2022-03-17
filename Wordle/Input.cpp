#include "Input.h"

Input::Input(Word &word) : word(&word)
{

}

void Input::setInput()
{
	static const char ALLOWED_CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::cin >> input;

	//Validify input
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);

	input = this->input;
}

std::string Input::getInput()
{
	return this->input;
}
