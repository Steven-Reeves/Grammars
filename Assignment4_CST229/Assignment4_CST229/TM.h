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
		char writeChar;
		DIRECTION direction;
		char nextState;

		Transition(char wC, DIRECTION d, char nS) { writeChar = wC; direction = d;  nextState = nS; };
		Transition() { writeChar = '_'; direction = LEFT;  nextState = 'H'; }

	};

	char initialState;
	char finalState;

	std::map<std::string, Transition> transitions;				// <currentState><readChar> => <transition>


public:
	TM(char initialState);
	~TM();
	void AddTransision(char currentState, char readChar, char writeChar, char direction, char nextState);
	void setFinalState(char finalState);
	bool Accept(std::string s, Tape & t);

private:
	std::string MakeKey(char currentState, char inputChar);
};