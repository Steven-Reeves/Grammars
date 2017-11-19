/*
Steven Reeves
CST 229
Assignment 4 part 2
*/

// Tape.cpp

#include "stdafx.h"
#include "Tape.h"

Tape::Tape(std::string initial)
{
	rightContents = initial;
	leftContents = "__";
	currentLocation = 0;
}

void Tape::Left()
{
	// Move left
	currentLocation--;

	// if on left side
	if (currentLocation < 0 && (size_t)-currentLocation >= leftContents.length())
	{
		// Grow the tape and add more blanks
		leftContents += '_';
	}
}
void Tape::Right()
{
	// Move right
	currentLocation++;

	// if on left side
	if (currentLocation >= 0 && (size_t)currentLocation >= rightContents.length())
	{
		// Grow the tape and add more blanks
		rightContents += '_';
	}
}

char Tape::Read()
{
	// Find out what side of tape and use correct side
	if (currentLocation >= 0)
	{
		// Right side
		// return character under the tape head
		return rightContents[currentLocation];
	}
	else
	{
		// Left side
		// return character under the tape head
		return leftContents[-currentLocation];
	}
}

void Tape::Write(char c)
{
	if (currentLocation >= 0)
	{
		// Right side
		rightContents[currentLocation] = c;
	}
	else
	{
		// Left side
		leftContents[-currentLocation] = c;
	}
}

std::string Tape::ToString()
{
	int i;
	std::string result = leftContents.substr(1);

	for (i = result.length() - 1; i >= 0 && result[i] == '_'; i--);
		if (i > 0)
			result.erase(i-1);

	std::reverse(result.begin(), result.end());

	result += rightContents;
	for (i = result.length() - 1; i >= 0 && result[i] == '_'; i--);
		if (i > 0)
			result.erase(i-1);

	return result;
}
