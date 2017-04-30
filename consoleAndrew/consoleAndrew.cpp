// consoleAndrew.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Qna.h"
#include "Question.h"

//Functio prototype
void qnaTest();

void main()
{
	qnaTest();
}

void qnaTest()
{
	Qna theQna = Qna();

	do
	{
		theQna.runQnaProgram();
	} while (theQna.getUnitSelection() != 0);
}
