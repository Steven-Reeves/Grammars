/*
Steven Reeves
CST 229
Assignment 2 part 2
*/

// DFA.cpp
// Class represents a DFA

#include "stdafx.h"
#include "DFA.h"


DFA::Transition::Transition(char c, char i, char n)
	: currentState(c), inputChar(i), nextState(n)
{

}

DFA::DFA(char initialState)
{
	this->initialState = initialState;
}

DFA::~DFA()
{

}

void DFA::AddTransision(char currentState, char inputChar, char nextState)
{
	// Map for transitions
	std::string key = MakeKey(currentState, inputChar);	
	transitions1[key] = nextState;
}

void DFA::setFinalState(char finalState)
{
	// use a set for final states
	finalStates1.insert(finalState);
}

bool DFA::Accept(std::string s)
{
	//Start at beginning
	char currentState = initialState;

	//Character by char, move the machine
	for each (char inputChar in s)
	{
		std::string key = MakeKey(currentState, inputChar);

		if (transitions1.find(key) != transitions1.end())
		{
			// change to next state
			currentState = transitions1[key];
		}
		else
		{
			// No transition, not accepted!
			return false;
		}
	}

	// if ended in a final state, we're good
	return finalStates1.find(currentState) != finalStates1.end();

}

std::string DFA::MakeKey(char currentState, char inputChar)
{
	std::string key;
	key += currentState;
	key += inputChar;

	return key;
}