/*
Steven Reeves
CST 229
Assignment 4 part 2
*/

#include "stdafx.h"
#include "TM.h"


TM::TM(char initialState) 
{
	this->initialState = initialState;
	finalState = '\0';
}

TM::~TM()
{

}

void TM::AddTransision(char currentState, char readChar, char writeChar, char direction, char nextState)
{
	std::string key = MakeKey(currentState, readChar);

	DIRECTION dir = LEFT;
	if (direction == 'L')
		dir = LEFT;
	else if (direction == 'R')
		dir = RIGHT;
	else
		throw "Unrecognized direction!";

	transitions[key] = Transition(writeChar, dir, nextState);
}

void TM::setFinalState(char finalState) 
{
	this->finalState = finalState;
}

bool TM::Accept(std::string s, Tape & t)
{
	char currentState = initialState;

	while (currentState != finalState)
	{
		// read from tape
		char readChar = t.Read();

		// Get transition, or reject
		std::string key = MakeKey(currentState, readChar);

		// if no transition, fail!
		if (transitions.find(key) == transitions.end())
			return false;

		// Write to tape
		t.Write(transitions[key].writeChar);

		// Move the tape
		switch (transitions[key].direction)
		{
		case LEFT:
			t.Left();
			break;
		case RIGHT:
			t.Right();
			break;

		default:
			throw "Unrecognized direction";
		}

		// Next state
		currentState = transitions[key].nextState;
	}

	return true;
}

std::string TM::MakeKey(char currentState, char inputChar)
{
	std::string key;
	key += currentState;
	key += inputChar;

	return key;
}
