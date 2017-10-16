/*
Steven Reeves
CST 229
Assignment 2 part 2
*/

#pragma once

// DFA.h
// class represents a DFA

#include <string>
#include <map>
#include <list>
#include <set>

class DFA
{
private:
	class Transition
	{
	public:
		char currentState;
		char inputChar;
		char nextState;
		Transition(char c, char i, char n);
	};
	char initialState;
	// TODO: Remove these
	std::list<Transition> transitions;
	std::list<char> finalStates;

	//Mapping idea
	std::map<std::string, char> transitions1;
	std::set<char> finalStates1;

public:
	DFA(char initialState);
	~DFA();
	void AddTransision(char currentState, char inputChar, char nextState);
	void setFinalState(char finalState);
	bool Accept(std::string s);

private:
	std::string MakeKey(char currentState, char inputChar);
};