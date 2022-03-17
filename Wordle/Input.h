#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Word.h"

class Input
{
public:
	Input(Word &word);
	void setGuessInput();
	void setRestartInput();
	std::string getInput();
private:
	Word* word;
	std::string input;

	const std::string ALLOWED_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	bool checkValidity(std::string input);
};
