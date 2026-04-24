#include <iostream>
#include <fstream>
#include "getinput.hpp"
#include "calc.hpp"
#include "print.hpp" 
int main() {
	Student s;
  getStudentInfo(&s);
  int result = mainCalculation();
  if (result != 0) {
    std::cout << "Error: something wrong with caculations"
      return 1;
  }
std::ifstream gpaFile("gpa.txt");
if (!gpaFile) {
  std::cout << " Error: could not open gpa.txt\n";
return 1;
}
gpaFile >> s.gpa;
gpaFile.close();
printResults(&s);
return 0;
}
