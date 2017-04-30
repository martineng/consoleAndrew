#include "NumberGame.h"
#include "stdlib.h"
#include "time.h"
#include "iostream"
#include "string"

using namespace std;

NumberGame::NumberGame()
{
	//Empty constructor
}

void NumberGame::setEmpty1(int inEmpty1)
{
	empty1 = inEmpty1;
}

void NumberGame::setEmpty2(int inEmpty2)
{
	empty2 = inEmpty2;
}

void NumberGame::setEmpty3(int inEmpty3)
{
	empty3 = inEmpty3;
}

int NumberGame::getEmpty1()
{
	return empty1;
}

int NumberGame::getEmpty2()
{
	return empty2;
}

int NumberGame::getEmpty3()
{
	return empty3;
}

int NumberGame::getNumberArrayValue(int inIndex)
{
	return numberArray[inIndex];
}



int NumberGame::generateRandomNumber(int inMin, int inMax)
{
	int randomNumber = 0;

	randomNumber = rand() % inMax + inMin; //Random Number between inMax and inMin

	return randomNumber;
}

void NumberGame::initializeNumberArray()
{
	numberArray = new int[10];

	for (int index = 0; index < 10; index++)
	{
		numberArray[index] = generateRandomNumber(1, 100);
	}
}

void NumberGame::freeNumberArray()
{
	delete[] numberArray;
}


void NumberGame::mergeSort(int inLeftStart, int inRightEnd)
{
	int middle;

	if (inLeftStart < inRightEnd)
	{
		middle = inLeftStart + (inRightEnd - inLeftStart) / 2;

		mergeSort(inLeftStart, middle);
		mergeSort(middle + 1, inRightEnd);
		merge(inLeftStart, middle, inRightEnd);
	}
}

void NumberGame::merge(int inLeftStart, int inMiddle, int inRightEnd)
{
	int left, index, rightStart, counterSort;
	int* tempArray = new int[10];
	left = inLeftStart;
	index = inLeftStart;
	rightStart = inMiddle + 1;

	while ((left <= inMiddle) && (rightStart <= inRightEnd))
	{
		if (numberArray[left] <= numberArray[rightStart])
		{
			tempArray[index] = numberArray[left];
			left++;
		}
		else
		{
			tempArray[index] = numberArray[rightStart];
			rightStart++;
		}
		index++;
	}
	if (left>inMiddle)
	{
		for (counterSort = rightStart; counterSort <= inRightEnd; counterSort++)
		{
			tempArray[index] = numberArray[counterSort];
			index++;
		}
	}
	else
	{
		for (counterSort = left; counterSort <= inMiddle; counterSort++)
		{
			tempArray[index] = numberArray[counterSort];
			index++;
		}
	}
	for (counterSort = inLeftStart; counterSort <= inRightEnd; counterSort++)
	{
		numberArray[counterSort] = tempArray[counterSort];
	}

	delete[] tempArray; //Free tempArray memory
}

void NumberGame::setEmptySlots()
{
	setEmpty1(generateRandomNumber(1, 3));
	setEmpty2(4);
	setEmpty3(generateRandomNumber(5, 8));
}

void NumberGame::newGame()
{
	srand(time(NULL)); //Initialize random seed for random number
	initializeNumberArray();
	mergeSort(0, 9);
	setEmptySlots();
}