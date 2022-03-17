#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Word.h"

class Input
{
public:
	Input(Word &word);
	void setInput();
	std::string getInput();
private:
	Word* word;
	std::string input;
};
