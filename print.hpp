#ifndef PRINT_HPP
#define PRINT_HPP
#include <iostream>
#include <string>
#include "getinput.hpp"

char getLetterGrade(float gpa)
{
  if (gpa >= 3.5)
    return 'A';
  else if (gpa >= 2.5)
    return 'B';
  else if (gpa >= 1.5)
    return 'C';
  else if (gpa >= 1.0)
    return 'D';
  else
    return 'F';
}
void printResults(Student* s)
{
  if (s ==nullptr) {
      std::cout << "Error: null pointer !\n";
      return;
  }
s->letterGrade = getLetterGrade(s->gpa);
std::cout << "\n===== GPA Results =====\n";
	std::cout << "Name: " << s->name << "\n";
	std::cout << "Grades:\n";
	for (int i = 0; i < s->gradeCount; i++) {
		std::cout << "  Grade " << (i + 1) << ": " << s->grades[i] << "\n";
	}
	std::cout << "GPA: " << s->gpa << " / 4.0\n";
	std::cout << "Letter Grade: " << s->letterGrade << "\n";
	std::cout << "=======================\n";
}
#endif
