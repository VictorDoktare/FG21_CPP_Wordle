#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Word
{
public:
	Word();

	void returnHint(std::string input);
	std::string setAnswer();
	std::string getAnswer();

private:
	std::ifstream word_txt;
	std::string answer;

	int getWordCount();
};

