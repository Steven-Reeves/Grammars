/*
Steven Reeves
CST 229
Assignment 3 part 2
*/

// PDA.cpp
// Class represents a PDA

#include "stdafx.h"
#include "PDA.h"
#include <stack>
#include <conio.h>

PDA::PDA(char initialState)
{
	this->initialState = initialState;
	finalState = '\0';
}

PDA::~PDA()
{
}

void PDA::AddTransision(char currentState, std::string action, char dataChar, char nextState)
{
	// Map for transitions
	std::string key = MakeKey(currentState, dataChar);
	transitions[key] = nextState;

	ACTION_TYPE at = READ;
	if (action == "push")
		at = PUSH;
	else if (action == "pop")
		at = POP;
	else if (action == "read")
		at = READ;
	else
		throw "unrecognized action!";

	actions[currentState] = Action(at, dataChar);

}

void PDA::setFinalState(char finalState)
{
	this->finalState = finalState;
}

bool PDA::Accept(std::string s)
{
	//Start at beginning
	char currentState = initialState;
	std::stack<char> theStack;

	int index = 0;

	while (currentState != finalState)
	{
		Action & act = actions[currentState];
		char c = act.dataChar;

		switch (act.type)
		{
		case PUSH:
			theStack.push(act.dataChar);
			break;

		case POP:
			if (theStack.empty())
				c = 'z';
			else
			{
				c = theStack.top();
				theStack.pop();
			}
			break;

		case READ:
			if (index >= s.length())
				c = 'z';
			else
				c = s[index++];
			break;
		}

		// Transisiton to next state 
		std::string key = MakeKey(currentState, c);
		if (transitions.find(key) != transitions.end())
			currentState = transitions[key];
		else
			return false;
	}

	return true;
}

std::string PDA::MakeKey(char currentState, char inputChar)
{
	std::string key;
	key += currentState;
	key += inputChar;

	return key;
}