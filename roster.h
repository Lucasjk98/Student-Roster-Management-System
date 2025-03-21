// roster.h
#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster {
private:
    Student* classRosterArray[5];
    int lastIndex;

public:
    Roster();
    ~Roster();

    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    // Function to get the class roster array
    Student** getClassRosterArray();
};

#endif