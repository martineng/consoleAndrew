#pragma once

class NumberGame
{
private:
	int* numberArray;
	int  empty1, empty2, empty3;
	
public:
	NumberGame();
	void setEmpty1(int);
	void setEmpty2(int);
	void setEmpty3(int);
	int getEmpty1();
	int getEmpty2();
	int getEmpty3();
	int getNumberArrayValue(int);

	int generateRandomNumber(int, int);
	void initializeNumberArray();
	void freeNumberArray();

	void mergeSort(int, int);
	void merge(int, int, int);

	void setEmptySlots();
	void newGame();
};