// GPACalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


void tokenizeInput(string entireLine, string &outputOne, string &outputTwo, int numberOfOutput) {
	std::stringstream ss;
	ss << entireLine;
	
	if (numberOfOutput > 2 || numberOfOutput <= 0) {
		cout << "Invalid number of outputs given" << endl;
	}
	
	if (numberOfOutput > 0) {
		ss >> outputOne;
	}

	if(numberOfOutput > 1){
		ss >> outputTwo;
	}
}


int main()
{
	string isCumlativeString = "", lineInput = "", temp = "", creditForClass = "", gradeForClass = "";
	ifstream input("gpa.txt");
	float credits = 0.0, grades = 0.0, total = 0.0, classGrade = 0.0, classCredit = 0.0;
	
	if (!input) 
	{
		cout << "File not found" << endl;
	}
	
	else 
	{
				
		getline(input, isCumlativeString);
		tokenizeInput(isCumlativeString, isCumlativeString, temp , 1); //temp is used as a dummy variable
		std::transform(isCumlativeString.begin(), isCumlativeString.end(), isCumlativeString.begin(), ::tolower);

		
		//get cumlative gpa and credits if selected, if not skip
		getline(input, lineInput);
		if (isCumlativeString == "true") {
			tokenizeInput(lineInput, gradeForClass, creditForClass, 2);
			credits += stof(creditForClass);			
			total += stof(gradeForClass) * stof(creditForClass);

		}

		//get input from all the classes
		while (getline(input, lineInput)) {
			tokenizeInput(lineInput, gradeForClass, creditForClass, 2);
			credits += stof(creditForClass);
			total += stof(gradeForClass) * stof(creditForClass);
		}
		
		cout <<"Total of Credits * Score: "  << total << endl;
		cout <<"Total amount of Credits attempted: "  << credits << endl;
		cout <<"Your projected GPA: " <<  total / credits << endl;
	
	}


}
	

