#include <iostream>
#include "roster.h"

int main() {
    std::cout << "Course Title: C867 Scripting and Programming - Applications" << std::endl;
    std::cout << "Programming Language: C++" << std::endl;
    std::cout << "WGU Student ID: [Your Student ID]" << std::endl;
    std::cout << "Name: [Your Name]" << std::endl;

    Roster classRoster;

    const std::string studentData[] = {
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Susan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,[firstname],[lastname],[emailaddress],[age],[numberofdaystocomplete3courses],SOFTWARE"
};

for (int i = 0; i < 5; i++) {
    std::stringstream ss(studentData[i]);
    std::string token;
    std::string data[9];
    int j = 0;
    while (std::getline(ss, token, ',')) {
        data[j++] = token;
    }
    DegreeProgram degreeProgram = SECURITY;
    if (data[8] == "NETWORK") {
        degreeProgram = NETWORK;
    } else if (data[8] == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }
    classRoster.add(data[0], data[1], data[2], data[3], std::stoi(data[4]), std::stoi(data[5]), std::stoi(data[6]), std::stoi(data[7]), degreeProgram);
}

    return 0;
}