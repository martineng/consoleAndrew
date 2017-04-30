#include "NumberGameLauncher.h"
#include "stdlib.h"
#include "string"
#include "iostream"

using namespace std;

NumberGameLauncher::NumberGameLauncher()
{
	theGame.newGame();
	setIsEmpty1Correct(false);
	setIsEmpty2Correct(false);
	setIsEmpty3Correct(false);
}

void NumberGameLauncher::setIsEmpty1Correct(bool inEmpty1)
{
	isEmpty1Correct = inEmpty1;
}

void NumberGameLauncher::setIsEmpty2Correct(bool inEmpty2)
{
	isEmpty2Correct = inEmpty2;
}

void NumberGameLauncher::setIsEmpty3Correct(bool inEmpty3)
{
	isEmpty3Correct = inEmpty3;
}

bool NumberGameLauncher::getIsEmpty1Correct()
{
	return isEmpty1Correct;
}

bool NumberGameLauncher::getIsEmpty2Correct()
{
	return isEmpty2Correct;
}

bool NumberGameLauncher::getIsEmpty3Correct()
{
	return isEmpty3Correct;
}


bool NumberGameLauncher::isEmpty(int inGuess)
{
	if (inGuess == theGame.getEmpty1() || inGuess == theGame.getEmpty2() || inGuess == theGame.getEmpty3())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void NumberGameLauncher::printQuiz()
{
	for (int count = 0; count < 10; count++)
	{
		if (isEmpty(count))
		{
			if (count == theGame.getEmpty1() && getIsEmpty1Correct() == false)
			{
				cout << " [__] ";
			}
			else if (count == theGame.getEmpty2() && getIsEmpty2Correct() == false)
			{
				cout << " [__] ";
			}
			else if (count == theGame.getEmpty3() && getIsEmpty3Correct() == false)
			{
				cout << " [__] ";
			}//END if
		}
		else
		{
			cout << " [" << theGame.getNumberArrayValue(count) << "] ";
		}//END if
	}//END for
}//END printQuiz()

int NumberGameLauncher::binarySearch(int inNumber)
{
	int first = 0, last = 9, middle = (first + last) / 2, positionFound = 0;

	while (first <= last)
	{
		if (theGame.getNumberArrayValue(middle) < inNumber)
		{
			first = middle + 1;
		}
		else if (theGame.getNumberArrayValue(middle) == inNumber)
		{
			positionFound = middle; //Found the target!
			break;
		}
		else
		{
			last = middle - 1;
		}

		middle = (first + last) / 2;
	}//END while

	if (first > last)
	{
		positionFound = 404; //Target Not Found!
	}//END if

	return positionFound;
}//END binarySearch()