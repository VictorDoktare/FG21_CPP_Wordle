#pragma once

#include <iostream>
#include <fstream>
#include <string>

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"

enum class ForegroundColor : int
{
    Black = 30,
};

enum class BackgroundColor : int
{
    BrightBlack = 100,
    BrightGreen = 102,
    BrightYellow = 103
};

class Word
{
public:
	Word();

	bool compareInput(std::string input); // feedback: string arguments usually can be a string references, to avoid copying

	void setColor(BackgroundColor bgColor, ForegroundColor fgColor, char c);

	std::string setAnswer();
	std::string getAnswer();
private:
	std::ifstream word_txt;
	std::string answer;
	void printChar(std::string tmpInput, std::string  input);
	int getWordCount();
};

