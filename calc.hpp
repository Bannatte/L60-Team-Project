#pragma once
#include <fstream>
#include <iostream>
#include <string>

// in main, write "#include calc.hpp"
// to call my function, write "mainCalculation();"

inline float calculateGpa(const std::string& filename) // reference to the string-filename
{
  std::ifstream inFile(filename);
	if (!inFile) {
        	std::cerr << "Error opening " << filename << "\n";
        	return -1;
	}

	std::string name;
	std::getline(inFile, name);
	
	int numClasses;
	inFile >> numClasses;

	if (numClasses <= 0) {
		return -1;
	}

	float* grades = new float[numClasses]; // creates a new array of floats, grades is simply a pointer to the first index of the array
	float gpa = 0;
	for (int i = 0; i < numClasses; i++) {
		inFile >> grades[i];
		float grade = grades[i];

		if (grade >= 90) { // 90 and above
			gpa += 4.0;
		} else if (grade >= 80) { // 80 to 89.9
			gpa += 3.0;
		} else if (grade >= 70) { // 70 to 79.9
			gpa += 2.0;
		} else if (grade >= 60) { // 60 to 69.9
			gpa += 1.0;
		} else { // 59.9 and below
			gpa += 0;
		}
	}

	delete[] grades;
	gpa /= numClasses;
	
	inFile.close();
	return gpa;
}

inline void writeGpaToFile(const std::string& filename, float gpa) // reference to the string-filename
{ 
	std::ofstream outFile(filename);
	if (!outFile) {
		std::cerr << "Error opening " << filename << "\n";
		return;
	}

	outFile << gpa;

	outFile.close();
}

inline int mainCalculation() {
	float studentGpa = calculateGpa("info.txt");

	if (studentGpa < 0 || studentGpa > 4.0) {
		return -1;
	}
	
    writeGpaToFile("gpa.txt", studentGpa);
	return 0;
}
