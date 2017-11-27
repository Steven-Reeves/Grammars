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

// TODO check this and change things
std::string Tape::ToString()
{
	unsigned int i;
	std::string result = "";

	// copy in the leftContents (not including the 0th unused character)
	// skipping any leading blanks '_'
	for (i = leftContents.length() - 1; i > 0 && leftContents[i] == '_'; i--);
	for (; i > 0; i--)
		result += leftContents[i];

	// find where the rightContents ends, before trailing blanks '_'
	unsigned int last = rightContents.find_last_not_of('_');
	if (last != -1)
	{
		// copy in the rightContents
		for (i = 0; i <= last; i++)
			result += rightContents[i];
	}

	return result;
}

