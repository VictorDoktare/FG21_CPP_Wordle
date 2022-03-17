#include <iostream>
#include "Word.h"
#include "Input.h"

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"

enum class ForegroundColor : int {
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    White = 37,
    BrightBlack = 90,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93
};

enum class BackgroundColor : int {
    Black = 40,
    Red = 41,
    Green = 42,
    Yellow = 43,
    White = 47,
    BrightBlack = 100,
    BrightRed = 101,
    BrightGreen = 102,
    BrightYellow = 103
};

int main()
{
    Word word;
    Input input(word);

    std::cout << word.getAnswer() << std::endl;
    input.setInput();
    word.returnHint(input.getInput());


    return 0;
}