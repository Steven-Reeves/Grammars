/*
Steven Reeves
CST 229
Assignment 4 part 2
*/

#pragma once

// TM.h
// class represents a TM

#include <string>
#include <map>
#include "Tape.h"

class TM
{
private:
	enum DIRECTION { LEFT, RIGHT };

	struct Transition
	{
		DIRECTION direction;
		char writeChar;
		char nextState;

		Transition(DIRECTION d, char wC, char nS) { direction = d; writeChar = wC; nextState = nS; };
		Transition() { direction = LEFT; writeChar = '_'; nextState = 'H'; }

	};

	char initialState;
	char finalState;

	std::map<std::string, Transition> transitions;				// <currentState><readChar> => <transition>


public:
	TM(char initialState);
	~TM();
	void AddTransision(char currentState, char writeChar, char direction, char nextState);
	void setFinalState(char finalState);
	bool Accept(std::string s);

private:
	std::string MakeKey(char currentState, char inputChar);
};