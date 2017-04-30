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
	// A generate function that if any of the imported value matches
	// process to the next IF statment in printQuiz().
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

void NumberGameLauncher::runNumberGame()
{
	// The program will not exit the loop
	// if and only if all guesses are correct.
	do 
	{
		printQuiz();
		isAnswer(promptGuess());
	} while (!isAllCorrect());
}//END runNumberGame()


int NumberGameLauncher::promptGuess()
{
	int userInput = 0;

	cout << "\nEnter Your Guess! : ";
	cin >> userInput;

	return userInput;
}//END promptGuess()


bool NumberGameLauncher::isAnswer(int inAnswer)
{
	int searchResult = binarySearch(inAnswer);
	bool isResultMatch = false; // Use as an return type

	// rand() will generate random number that's out of the range.
	// while having no real theoretical explanation,
	// this statement fixed the bug.
	if (theGame.getEmpty3() > 9 && isEmpty3Correct == false)
	{
		isEmpty3Correct = true;
	}//END if

	// Trigger IF userInput matches any of the answer.
	if (searchResult == theGame.getEmpty1())
	{
		isEmpty1Correct = true;
		isResultMatch = true;
	}
	else if (searchResult == theGame.getEmpty2())
	{
		isEmpty2Correct = true;
		isResultMatch = true;
	}
	else if (searchResult == theGame.getEmpty3())
	{
		isEmpty3Correct = true;
		isResultMatch = true;
	}//END if

	// Output message accordingly.
	if (isResultMatch)
	{
		cout << "Slot " << searchResult + 1 << " is correct!\n" << endl;
		return isResultMatch;
	}
	else
	{
		cout << "Good guess! But WRONG!!\n" << endl;
		return isResultMatch;
	}
}//END checkAnswer()

bool NumberGameLauncher::isAllCorrect()
{
	// A general function that IF all returned true,
	// the game is over.
	if (getIsEmpty1Correct() && getIsEmpty1Correct() && getIsEmpty3Correct())
	{
		return true;
	}
	else
	{
		return false;
	}
}