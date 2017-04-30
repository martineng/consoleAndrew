#pragma once
#include "string"
using std::string;

class Question
{
private:
	string index, topic, answer;

public:
	Question();
	Question(string, string, string);

	void setIndex(string);
	void setTopic(string);
	void setAnswer(string);

	string getIndex();
	string getTopic();
	string getAnswer();
};//END class