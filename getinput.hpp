#ifndef GETINPUT_HPP
#define GETINPUT_HPP
#include <iostream>
#include <string>

#define MAX_STUDENTS 50
#define MAX_GRADES    5

struct Student {
    std::string name;
    float grades[5];   // up to 5 grades
    int gradeCount;
    float gpa;
    char letterGrade;
};

// Pointer concept: takes index by value, returns a valid float
float getValidGrade(int index) {
    float grade;
    while (true) {
        std::cout << "  Grade " << (index + 1) << ": ";
        std::cin  >> grade;
        if (grade >= 0.0f && grade <= 100.0f)
            return grade;
        std::cout << "  Invalid! Enter a grade between 0 and 100.\n";
    }
}

// Pass struct by pointer so it can be filled in-place
void getStudentInfo(Student* s) {
    // Pointer concept: always verify a pointer isn't null before using it
    if (s == nullptr) {
        std::cout << "Error: null pointer passed to getStudentInfo!\n";
        return;
    }

    std::cout << "Enter student name: ";
    std::cin >> s->name;

    // Pointer concept: s->gradeCount writes directly into the original struct
    do {
        std::cout << "How many grades? (1-5): ";
        std::cin  >> s->gradeCount;
    } while (s->gradeCount < 1 || s->gradeCount > MAX_GRADES);

    for (int i = 0; i < s->gradeCount; i++) {
        s->grades[i] = getValidGrade(i);
    }
}

// Pass count by pointer so caller sees updated value
void getAllStudents(Student* students, int* count) {
    // Pointer concept: check BOTH pointers before touching either
    if (students == nullptr || count == nullptr) {
        std::cout << "Error: null pointer passed to getAllStudents!\n";
        return;
    }

    // Pointer concept: *count dereferences to write into caller's variable
    do {
        std::cout << "How many students? (1-" << MAX_STUDENTS << "): ";
        std::cin  >> *count;
    } while (*count < 1 || *count > MAX_STUDENTS);

    for (int i = 0; i < *count; i++) {
        std::cout << "\n--- Student " << (i + 1) << " ---\n";
        getStudentInfo(&students[i]);
    }
}

#endif