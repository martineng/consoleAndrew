#include "Question.h"

Question::Question()
{
	index = "";
	topic = "";
	answer = "";
}//END default

Question::Question(string inIndex, string inTopic, string inAnswer)
{
	setIndex(inIndex);
	setTopic(inTopic);
	setAnswer(inAnswer);
}

void Question::setIndex(string inIndex)
{
	index = inIndex;
}

void Question::setTopic(string inTopic)
{
	topic = inTopic;
}

void Question::setAnswer(string inAnswer)
{
	answer = inAnswer;
}

string Question::getIndex()
{
	return index;
}

string Question::getTopic()
{
	return topic;
}

string Question::getAnswer()
{
	return answer;
}
