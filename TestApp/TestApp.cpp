// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream> //Include IO library
#include <string> //Include string library (for writing and reading strings to and from the console)
#include <regex> //Include Regex Library for Validation
#include <fstream>
#include <vector> //Include Vector Library
#include <sstream> //Include String Stream Libarary
#include <stdlib.h> 

int GetGuess();

using namespace std; //Namespace for libraries

int answer = 0;
int guess = 0;
int turnNumber = 0;
const int allowedGuesses = 8;
const int maxAnswerNumber = 1000;

regex regex_pattern("^[1-9][0-9]?$|^100$"); //Regular Expression for Checking Input is Valid (only accepting 1, 2 or 3)

int main()
{
	std::cout << "//// GUESS THE NUMBER ////" << endl;
    std::cout << "I'm thinking of a number. Guess it and win...satisfaction of defeating a computer, I suppose.\nSad but true." << endl;
	std::cout << "///////////////////////////" << endl;

	answer = rand() % (maxAnswerNumber + 1) + 1;

	do {
		//Display error and ask for new input
		guess = GetGuess();
		if (guess == answer) {
			cout << "Correct! Well done!" << endl;
			system("pause");//Pause console
		}
		else {
			turnNumber++;
			if (guess > answer) {
				cout << "Nope! Lower!\n Guess Number " << turnNumber << endl;
				std::cout << "///////////////////////////" << endl;
			}
			if (guess < answer) {
				cout << "Nope! Higher!\n Guess Number " << turnNumber << endl;
				std::cout << "///////////////////////////" << endl;
			}
		}
	} while (guess != answer && turnNumber < allowedGuesses);

	if (turnNumber >= allowedGuesses) {
		cout << "Nope. You lose, I win. Game Over.\n\nNo hard feelings?" << endl;
		system("pause");//Pause console
	}
}

int GetGuess() {
	string checkString; //A string to load the console input into for checking
	do {
		checkString = ""; //Make checkstring blank
		cout << "Enter Guess Between 1 - 100" << endl; //Ask for input
		std::cout << ">";
		cin >> checkString; //Get console input
		if (!regex_match(checkString, regex_pattern)) { //Check that input matches expected regular expression
			cout << checkString + "- Not Valid" << endl << endl; //If it doesn't work, then we display that to the screen as an error message
		}
	} while (!regex_match(checkString, regex_pattern)); //Keep asking for and checking input until valid against the regular expression 
	return stoi(checkString); //Turn the string into an integer then return it
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
