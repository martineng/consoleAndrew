#include "Qna.h"
#include "stdlib.h"
#include "iostream"
#include "string"
#include "fstream"
#include "conio.h"

using namespace std;

Qna::Qna()
{
	//empty
}

void Qna::setUnitSelection(int inSelection)
{
	unitSelection = inSelection;
}

int Qna::getUnitSelection()
{
	return unitSelection;
}

void Qna::setMaxCol(int inMaxCol)
{
	maxCol = inMaxCol;
}

int Qna::getMaxCol()
{
	return maxCol;
}

void Qna::setQuestionSelection(int inSelection)
{
	questionSelection = inSelection;
}

int Qna::getQuestionSelection()
{
	return questionSelection;
}



void Qna::runQnaProgram()
{
	setUnitSelection(0);
	setMaxCol(0);

	openUnitMenu();

	do
	{
		if (isUnitSelectionValid())
		{
			readFile();
			openQuestionMenu();

			if (isQuestionSelectionValid())
			{
				openAnswer();
			}

			freeQuestionArray();
		}
	} while (getQuestionSelection() != 0);
		
}


void Qna::openUnitMenu()
{
	bool isValid = false;
	int theSelection = 0;

	do
	{
		cout << "\n\nEnter Index Number: " << endl;
		cout << "[1] ICTPRG478 - Apply Intermediate Programming Skills in Another Langugae" << endl;
		cout << "[2] ICTPRG502 - Manage a Project Using Software Management Tools" << endl;
		cout << "[0] Back" << endl;
		cout << "Enter: ";

		if (cin >> theSelection) //Validate user input
		{
			if (theSelection >= 0 && theSelection < 3) //User input valid
			{
				isValid = true; // Terminate the loop
			} //END if
			else // IF user enter index not listed
			{
				cout << "!!! INCORRECT INPUT !!!" << endl;
			} //END else
		}//END if
		else // Input datatype mismatched
		{
			cin.clear();
			cin.ignore();
			cout << "!!! INVALID INPUT, PLEASE TRY AGAIN !!!" << endl;
		} //END else
	} while (isValid == false);

	setUnitSelection(theSelection);
}

void Qna::openQuestionMenu()
{
	// This Menu allow user to choose which answer to view

	bool isValid = false; //To check user input
	int theSelection = 0;

	do
	{
		cout << "\n\nEnter Index Number: " << endl;

		// Loop through 2D-Array and get the menu printed
		for (int col = 0; col != getMaxCol(); col++)
		{
			//col + 1 because array index start from 0.
			cout << "[" << col + 1 << "] - " << questionArray[col][1] << endl;
		}//END for

		cout << "[" << getMaxCol() + 2 << "] - Binary Search for Question " << endl;

		cout << "[0] - Back" << endl;
		cout << "Enter: ";
		if (cin >> theSelection) // Handling cin input
		{
			if (theSelection >= 0 && theSelection <= getMaxCol()) //IF user input valid
			{
				isValid = true; // Terminate the loop
			}//END if
			else // IF user input index not listed
			{
				cout << "!!! INCORRECT INPUT !!!" << endl;
			}//END else
		}//END if
		else // Input datatype mismatched
		{
			cin.clear();
			cin.ignore();
			cout << "!!! INVALID INPUT, PLEASE TRY AGAIN !!!" << endl;
		}//END else

	} while (isValid == false);

	setQuestionSelection(theSelection);
}

void Qna::openAnswer()
{
	// inSelection - 1 becaseu array index start from 0.
	cout << "\n----------------------------------------------------------------------------" << endl;
	cout << "<<" << questionArray[getQuestionSelection() - 1][0] << ">>" << endl;
	cout << "\t" << questionArray[getQuestionSelection() - 1][1] << endl;
	cout << "\nAnswer: " << endl;
	cout << "\t" << questionArray[getQuestionSelection() - 1][2] << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "\nEnter any key to return...";

	_getch(); //To achieve press anything to continue
}

void Qna::readFile()
{
	string fileName;

	switch (getUnitSelection())
	{
	case 1:
		fileName = "ICTPRG418.txt";
		defineArrayColSize(fileName);
		initializeQuestionArray();
		openFile(fileName);
		break;
	case 2:
		fileName = "ICTPRG502.txt";
		defineArrayColSize(fileName);
		initializeQuestionArray();
		openFile(fileName);
		break;
	default:
		break;
	}

}

void Qna::openFile(string inFileName)
{
	ifstream theFile;
	theFile.open(inFileName, ios::in);

	if (theFile.fail()) // IF File not exit
	{
		cout << "!!! UNABLE TO OPEN FILE !!!" << endl;
	}//END if
	else
	{
		string line;
		int counter = 0;

		while (getline(theFile, line))
		{
			int splitArray[2], position = 0; // To hold the seperator ','

			for (int index = 0; index < line.length(); index++)
			{
				if (line[index] == ';')
				{
					splitArray[position] = index;
					position++;
				}//END if	
			}//END for

			 // Save to 2D-Array
			questionArray[counter][0] = line.substr(0, splitArray[0]);
			questionArray[counter][1] = line.substr(splitArray[0] + 1, splitArray[1] - splitArray[0] - 1);
			questionArray[counter][2] = line.substr(splitArray[1] + 1);

			counter++; //next line
		}//END while
	}//END else
	theFile.close();
}

void Qna::defineArrayColSize(string inFileName)
{
	//To find the length of Array
	string line;
	int counter = 0;
	ifstream theFile;
	theFile.open(inFileName, ios::in);

	while (getline(theFile, line))
	{
		counter++;
	}//END while

	setMaxCol(counter);
}

void Qna::initializeQuestionArray()
{
	//Dynamically assgin the 2D-Array.
	int maxRow = 3; //Base on the Question Text file, Row will always be 3 slots.

	questionArray = new string*[getMaxCol()]; //Create Colume

	for (int index = 0; index < getMaxCol(); index++)
	{
		questionArray[index] = new string[maxRow]; //Create Row on each Columes
	}
}

void Qna::freeQuestionArray()
{
	//This is a special function to free the memory allocated for the 2D-Array
	for (int col = 0; col < getMaxCol(); col++)
	{
		delete[] questionArray[col]; //Delete Level 2 array, the Rows.
	}

	delete questionArray; //Delete Colume
}

bool Qna::isUnitSelectionValid()
{
	if (getUnitSelection() != 0 && getUnitSelection() <= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Qna::isQuestionSelectionValid()
{
	if (getQuestionSelection() != 0 && getQuestionSelection() <= getMaxCol())
	{
		return true;
	}
	else
	{
		return false;
	}
}

