/*
Steven Reeves
CST 229
Assignment 3 part 2
*/

#include "stdafx.h"
#include "PDA.h"
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <conio.h>

std::vector<std::string> SplitString(std::string input);

int main()
{

	// Currently no cmd args in VS project.

	std::list<std::string> transitions;
	std::list<std::string> inputStrings;
	std::string comments;

	// Read input
	std::string line;
	// Remove first line of comments
	std::getline(std::cin, line);
	comments = line;
	// Get next line including number of states
	std::getline(std::cin, line);
	// Read transitions
	std::getline(std::cin, line);

	while (line.find(',') != -1)
	{
		transitions.push_back(line);
		std::getline(std::cin, line);
	}

	// Read in strings
	do 
	{
		inputStrings.push_back(line);
	}
	while (std::getline(std::cin, line));

	PDA pda(transitions.front()[0]);

	// Add transitions
	for each(std::string t in transitions)
	{
		// Each transition includes <current state>, <action>, <data char>, <next state>
		// <action> in {"read", "pop, "push"}
		std::vector<std::string> parts = SplitString(t);
		pda.AddTransision(parts[0][0], parts[1], parts[2][0], parts[3][0]);
	}

	// Set final states
	pda.setFinalState('F');


	// Note comments before returning strings
	std::cout << "Comments: " << "\t" << comments << std::endl;

	// Process each string and print accept or reject
	for each(std::string s in inputStrings)
	{
		if (pda.Accept(s))
		{
			// Accept
			std::cout << "Accepted: " << "\t" << s << std::endl;
		}
		else
		{
			// Reject
			std::cout << "Rejected: " << "\t" << s << std::endl;
		}
	}

	std::cout << "Press Any Key To Exit...";
	_getch();

	return 0;
}

std::vector<std::string> SplitString(std::string input)
{
	std::vector<std::string> result;

	size_t i = input.find(", ");
	while (i != -1)
	{
		result.push_back(input.substr(0, i));
		input = input.substr(i+2);
		i = input.find(", ");
	}
	result.push_back(input);

	return result;
}

