#include <iostream>
#include "roster.h"

Roster::Roster() {
    lastIndex = -1;
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr;
    }
}

Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
    }
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    lastIndex++;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            lastIndex--;
        }
    }
    if (!found) {
        std::cout << "Student with ID " << studentID << " not found." << std::endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            std::cout << "Average days in course for student " << studentID << ": " << (days[0] + days[1] + days[2]) / 3 << std::endl;
            return;
        }
    }
    std::cout << "Student with ID " << studentID << " not found." << std::endl;
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; i++) {
        std::string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
            std::cout << "Invalid email: " << email << std::endl;
        }
    }
}