#include "Word.h"

Word::Word()
{
    setAnswer();

    //Lazy game tutorial
    std::cout << "  _ _ _ _____ _____ ____  __    _____ " << "\n";
    std::cout << " | | | |     | __  |     |  |  |   __|" << "\n";
    std::cout << " | | | |  |  |    -|  |  |  |__|   __|" << "\n";
    std::cout << " |_____|_____|__|__|____/|_____|_____|" << "\n";

    std::cout << '\n';

    std::cout << " You have six attempts to guess a FIVE letter word" << std::endl << '\n';
    std::cout << " " << FOREGROUND(ForegroundColor::Black, BACKGROUND(BackgroundColor::BrightGreen, " ")) << " = Letter is in the correct place \n";
    std::cout << " " << FOREGROUND(ForegroundColor::Black, BACKGROUND(BackgroundColor::BrightYellow, " ")) << " = Letter is in the wrong place \n";
    std::cout << " " << FOREGROUND(ForegroundColor::Black, BACKGROUND(BackgroundColor::BrightBlack, " ")) << " = Letter not included in answer \n";
}

bool Word::compareInput(std::string input)
{
    std::string tmpAnswer = answer; // feedback: you are relying on answer is being set here. For more robust design its good to do a check if it was
                                    // actually set and not empty.
    std::string tmpInput = input;

    //If the whole input string matches the answer.
    if (input == answer)
    {
        for (int i = 0; i < answer.length(); i++)
        {
            if (input[i] == answer[i])
            {
                tmpInput[i] = '0';
            }
        }

        printChar(tmpInput, input);

        std::cout << "Congratulations, you have guessed correct! ";

        return true;
    }

    /*
     * Setting 'out' to answer just to get the correct size instead of hard code it.
     * Setting all 'chars' to NULL makes it easier when doing the final check.
     */
    std::string out = answer;
    for (int i = 0; i < answer.length(); i++)
    {
        out[i] = NULL; // feedback: not sure I understand the purpose of setting characters to NULL here.
                       // If I'd do this compare, I'd do it like this:
                       // for each character in input do:
                       //   if character is same in the same position in target word: set green color
                       //   if charecter is present in any position in target word: set yellow color
                       //   else: set grey.
                       // Not sure why compare needs to be more complicated than that
    }



    /*
     * Check every 'char' that is already a correct match and in correct position.
     * For every valid check remove them from the temp containers.
     */
    for (int i = 0; i < answer.length(); i++)
    {
	    if (input[i] == answer[i])
	    {
            tmpInput[i] = '0';
            tmpAnswer[i] = NULL;

            out[i] = input[i];
	    }
    }

	/*
     * Check every 'char' if it matches anywhere in the answer string.
     * For every valid check i remove them from the temp containers.
     */
    for (int i = 0; i < answer.length(); i++)
    {
        if (tmpAnswer[i] == NULL)
        {
            continue;
        }

        for (int j = 0; j < answer.length(); j++)
        {
            if (tmpAnswer[i] == tmpInput[j])
            {
                tmpInput[j] = '1';
                tmpAnswer[i] = NULL;

                out[j] = input[j];
                break;
            }
        }
    }

	/*
	* Since we already done every valid check, everything that is still NULL
	* in 'out' is gonna be invalid 'char' matches.
	*/
    for (int i = 0; i < answer.length(); i++)
    {
        if (out[i] == NULL)
        {
            tmpInput[i] = '2';
            out[i] = input[i];
        }
    }

    printChar(tmpInput, input);
    return false;
}

void Word::setColor(BackgroundColor bgColor, ForegroundColor fgColor, char c)
{
    std::cout << BACKGROUND(bgColor, FOREGROUND(fgColor, c));
}

//Set a random word from .txt as the current answer using time as seed
std::string Word::setAnswer() // feedback: I'd say the name of this function is a bit misleading, as it actually gets the random word from the file.
{
    std::string line;

    srand(time(0));
    int index = 1 + (rand() % getWordCount()); // feedback: you read the whole file once here, to calculate the number of lines in the file,
                                               // then you do it again below. I'd say it would be more efficient to read the whole file in memory
                                               // once and then pick a random word from memory.

    word_txt.open("words.txt", std::ifstream::in);
    for (int i = 1; i <= index; ++i)
    {
        if (i == index)
        {
            word_txt >> answer;
            break;
        }

        std::getline(word_txt, line);
    }
    word_txt.close();

    return answer;
}

std::string Word::getAnswer()
{
	return answer;
}

void Word::printChar(std::string tmpInput, std::string  input)
{
    for (int i = 0; i < answer.length(); i++)
    {
        switch (tmpInput[i])
        {
        case '0':
        {
            setColor(BackgroundColor::BrightGreen, ForegroundColor::Black, input[i]);
            continue;
        }
        case '1':
        {
            setColor(BackgroundColor::BrightYellow, ForegroundColor::Black, input[i]);
            continue;
        }
        case '2':
        {
            setColor(BackgroundColor::BrightBlack, ForegroundColor::Black, input[i]);
        }
        }
    }

    std::cout << "\n\n";
}

//Count number of words in .txt
int Word::getWordCount()
{
    int line_count = 0;
    std::string line;

    word_txt.open("words.txt", std::ifstream::in);
    while (std::getline(word_txt, line))
    {
        line_count++;
    }
    word_txt.close();

    return line_count;
}




