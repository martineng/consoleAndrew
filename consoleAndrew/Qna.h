#pragma once
#include "Question.h"

class Qna
{
private:
	Question questionObject;
	string** questionArray;
	int unitSelection;
	int questionSelection;
	int maxCol;

public:
	Qna();
	void setUnitSelection(int);
	int getUnitSelection();
	void setQuestionSelection(int);
	int getQuestionSelection();
	void setMaxCol(int);
	int getMaxCol();

	void runQnaProgram();

	void openUnitMenu();
	void openQuestionMenu();
	void openAnswer();
	void readFile();
	void openFile(string);

	void defineArrayColSize(string);
	void initializeQuestionArray();
	void freeQuestionArray();
	
	bool isUnitSelectionValid();
	bool isQuestionSelectionValid();
};