// CST229Assign2StevenReeves.cpp : Defines the entry point for the console application.
//

/*
Steven Reeves
CST 229
Assignment 2 part 2
*/

#include "stdafx.h"
#include "DFA.h"
#include <string>
#include <list>
#include <iostream>
#include <conio.h>

int main()
{
	// test inputs 1-4 check out
	// Note: make sure test files are here:
	// ... \CST229_Assign2_Steven_Reeves\CST229_Assign2_Steven_Reeves\CST 229 - Assign 2 - Test 4.txt

	// Currently no cmd args in VS project.

	int nStates = 0;
	std::list<std::string> transitions;
	std::list<char> finalStates;
	std::list<std::string> inputStrings;
	std::string comments;

	// Read input
	std::string line;
	// Remove first line of comments
	std::getline(std::cin, line);
	comments = line;
	// Get next line including number of states
	std::getline(std::cin, line);
	nStates = atoi(line.c_str());
	// Read transitions
	std::getline(std::cin, line);
	
	while (line[0] != 'F')
	{
		transitions.push_back(line);
		std::getline(std::cin, line);
	}

	// Parse final states
	for (unsigned int i = 3; i < line.length(); i = i + 3)
	{
		finalStates.push_back(line[i]);
	}

	// Read in strings
	while (std::getline(std::cin, line))
	{
		inputStrings.push_back(line);
	}

	DFA dfa(transitions.front()[0]);

	// Add transitions
	for each(std::string t in transitions)
	{
		// Each transition is 8 characters including null terminator
		dfa.AddTransision(t[0], t[3], t[6]);
	}

	// Set final states
	for each(char f in finalStates)
	{
		dfa.setFinalState(f);
	}

	// Note comments before returning strings
	std::cout << "Comments: " << "\t" << comments << std::endl;

	// Process each string and print accept or reject
	for each(std::string s in inputStrings)
	{
		if (dfa.Accept(s))
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

