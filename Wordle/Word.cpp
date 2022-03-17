#include "Word.h"

Word::Word()
{
    setAnswer();

    //Game Tutorial
    std::cout << "INSTRUCTIONS:\n" << std::endl;
    std::cout << "You have six attempts to guess a FIVE letter word" << std::endl << '\n';
    std::cout << " " << FOREGROUND(ForegroundColor::Black, BACKGROUND(BackgroundColor::BrightGreen, " ")) << " = Letter is in the correct place \n";
    std::cout << " " << FOREGROUND(ForegroundColor::Black, BACKGROUND(BackgroundColor::BrightYellow, " ")) << " = Letter is in the wrong place \n";
    std::cout << " " << FOREGROUND(ForegroundColor::Black, BACKGROUND(BackgroundColor::BrightBlack, " ")) << " = Letter not included in answer \n\n";
}

bool Word::compareInput(std::string input)
{
    std::string tmpAnswer = answer;
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

        return true;
    }

    /*
     * Output string, setting it to answer just to get the correct size.
     * Setting all 'chars' to NULL makes it easier when doing the final check.
     */
    std::string out = answer;
    for (int i = 0; i < answer.length(); i++)
    {
        out[i] = NULL;
    }



    /*
     * Check every 'char' that is already a correct match and in correct position.
     * For every valid check i remove them from the temp containers.
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
std::string Word::setAnswer()
{
    std::string line;

    srand(time(0));
    int index = 1 + (rand() % getWordCount());

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




