/*
Steven Reeves
CST 229
Assignment 3 part 2
*/

#pragma once

// PDA.h
// class represents a PDA

#include <string>
#include <map>
#include <list>
#include <set>

class PDA
{
private:
	enum ACTION_TYPE {READ, PUSH, POP};

	struct Action
	{
		ACTION_TYPE type;
		char dataChar;

		Action(ACTION_TYPE t, char dataChar);

	};

	char initialState;
	char finalState;

	std::map<std::string, char> transitions;	// <currentState><dataChar> => <nextState>
	std::map<char, Action> actions;				// <state> ==> <action to take when entering this state>


public:
	PDA(char initialState);
	~PDA();
	void AddTransision(char currentState, std::string action, char dataChar, char nextState);
	void setFinalState(char finalState);
	bool Accept(std::string s);

private:
	std::string MakeKey(char currentState, char inputChar);
};
