#pragma once
#include "NumberGame.h"

class NumberGameLauncher
{
private:
	bool isEmpty1Correct, isEmpty2Correct, isEmpty3Correct;
	NumberGame theGame;

public:
	NumberGameLauncher();
	void setIsEmpty1Correct(bool);
	void setIsEmpty2Correct(bool);
	void setIsEmpty3Correct(bool);
	bool getIsEmpty1Correct();
	bool getIsEmpty2Correct();
	bool getIsEmpty3Correct();

	bool isEmpty(int);
	void printQuiz();
	int binarySearch(int);
	
	void runNumberGame();
	int promptGuess();
	bool isAnswer(int);
	bool isAllCorrect();
};