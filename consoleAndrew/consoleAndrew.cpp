// consoleAndrew.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Qna.h"
#include "Question.h"
#include "NumberGame.h"
#include "NumberGameLauncher.h"

//Functio prototype
void qnaTest();

void main()
{
	//qnaTest();
	numberGame();
}

void qnaTest()
{
	Qna theQna = Qna();

	do
	{
		theQna.runQnaProgram();
	} while (theQna.getUnitSelection() != 0);
}//END qnaTest()

void numberGame()
{
	NumberGameLauncher theNumGame = NumberGameLauncher();

	theNumGame.runNumberGame();
}//END numberGame()