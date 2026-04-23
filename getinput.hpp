#ifndef GETINPUT_HPP
#define GETINPUT_HPP
#include <iostream>
#include <string>

#define MAX_GRADES 5

struct Student {
    std::string name;
    float grades[MAX_GRADES];
    int gradeCount;
    float gpa;
    char letterGrade;
};

// Pass struct by pointer so it can be filled in-place
void getStudentInfo(Student* s) {
    if (s == nullptr) {
        std::cout << "Error: null pointer!\n";
        return;
    }

    std::cout << "Enter student name: ";
    std::cin  >> s->name;

    do {
        std::cout << "How many grades? (1-5): ";
        std::cin  >> s->gradeCount;
    } while (s->gradeCount < 1 || s->gradeCount > MAX_GRADES);

    for (int i = 0; i < s->gradeCount; i++) {
        do {
            std::cout << "  Grade " << (i + 1) << ": ";
            std::cin  >> s->grades[i];
        } while (s->grades[i] < 0 || s->grades[i] > 100);
    }
}

#endif