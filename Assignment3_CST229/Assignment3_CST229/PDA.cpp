/*
Steven Reeves
CST 229
Assignment 3 part 2
*/

// PDA.cpp
// Class represents a PDA

#include "stdafx.h"
#include "PDA.h"


PDA::PDA(char initialState)
{
	this->initialState = initialState;
}

PDA::~PDA()
{

}

void PDA::AddTransision(char currentState, std::string action, char dataChar, char nextState)
{
	// Map for transitions
	std::string key = MakeKey(currentState, dataChar);
	// TODO use string to make a new action object
	transitions[key] = nextState;
}

void PDA::setFinalState(char finalState)
{
	this->finalState = finalState;
}

bool PDA::Accept(std::string s)
{
	//Start at beginning
	char currentState = initialState;

	//Character by char, move the machine
	for each (char inputChar in s)
	{
		std::string key = MakeKey(currentState, inputChar);

		if (transitions.find(key) != transitions.end())
		{
			// change to next state
			currentState = transitions[key];
		}
		else
		{
			// No transition, not accepted!
			return false;
		}
	}

	// TODO check this If in final state, you're good!
	return currentState == finalState;

}

std::string PDA::MakeKey(char currentState, char inputChar)
{
	std::string key;
	key += currentState;
	key += inputChar;

	return key;
}