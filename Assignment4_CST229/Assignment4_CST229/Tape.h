/*
Steven Reeves
CST 229
Assignment 4 part 2
*/

#pragma once
#include <string>

// Tape.h
// Defines a TM tape

class Tape
{
private:
	std::string rightContents;	// currentLocation >= 0 
	std::string leftContents;	// currentLocation < 0 
	int currentLocation;

public:
	Tape(std::string initial);

	void Left();
	void Right();

	char Read();
	void Write(char c);

	std::string ToString();

};