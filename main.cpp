#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

int main() {
    // Print course information
    cout << "Course Title: C867 Scripting and Programming - Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 012363326" << endl;
    cout << "Name: Lucas Jimenez" << endl;
    cout << endl;

    // Create a roster
    Roster classRoster;

    // Student data 
    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Susan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Lucas,Jimenez,ljimen22@wgu.edu ,26,45,50,55,SOFTWARE" 
    };

    // Parse and add students to the roster
    for (int i = 0; i < 5; i++) {
        stringstream ss(studentData[i]);
        string token;
        string data[9];
        int j = 0;
        while (getline(ss, token, ',')) {
            data[j++] = token;
        }
        DegreeProgram degreeProgram = SECURITY;
        if (data[8] == "NETWORK") {
            degreeProgram = NETWORK;
        } else if (data[8] == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }
        classRoster.add(data[0], data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[7]), degreeProgram);
    }

    // Print all students
    cout << "Printing all students:" << endl;
    classRoster.printAll();
    cout << endl;

    // Print invalid emails
    cout << "Printing invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    // Print average days in course for each student
    cout << "Printing average days in course:" << endl;
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray()[i]->getStudentID());
    }
    cout << endl;

    // Print students by degree program (SOFTWARE)
    cout << "Printing students by degree program (SOFTWARE):" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    // Remove a student by ID (A3)
    cout << "Removing student with ID A3:" << endl;
    classRoster.remove("A3");
    cout << endl;

    // Print all students again (A3 should be removed)
    cout << "Printing all students after removal:" << endl;
    classRoster.printAll();
    cout << endl;

    // Try to remove A3 again (should show an error)
    cout << "Attempting to remove student with ID A3 again:" << endl;
    classRoster.remove("A3");
    cout << endl;

    return 0;
}