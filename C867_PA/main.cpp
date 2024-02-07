//
//  main.cpp
//  C867_PA
//
//  Copyright © 2024 TaeVon Lewis. All rights reserved.
//


#include "roster.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::cout << "Course Title: Scripting and Programming - Applications – C867" << std::endl;
    std::cout << "Programming Language Used: C++" << std::endl;
    std::cout << "WGU Student ID: 011027113" << std::endl;
    std::cout << "Student Name: TaeVon Lewis" << std::endl << std::endl;
    
    const std::string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,TaeVon,Lewis,tlew662@wgu.edu,26,30,35,40,SOFTWARE"
    };

    const int numStudents = sizeof(studentData) / sizeof(studentData[0]);
    Roster classRoster;

    for (int i = 0; i < numStudents; i++) {
        std::vector<std::string> studentInfo;
        std::istringstream ss(studentData[i]);
        std::string token;

        while (std::getline(ss, token, ',')) {
            studentInfo.push_back(token);
        }

        int daysArray[3] = {std::stoi(studentInfo[4]), std::stoi(studentInfo[5]), std::stoi(studentInfo[6])};
        DegreeProgram dp = DegreeProgram::UNKNOWN;

        if (studentInfo[8] == "SECURITY") dp = DegreeProgram::SECURITY;
        else if (studentInfo[8] == "NETWORK") dp = DegreeProgram::NETWORK;
        else if (studentInfo[8] == "SOFTWARE") dp = DegreeProgram::SOFTWARE;

        classRoster.add(studentInfo[0], studentInfo[1], studentInfo[2], studentInfo[3], std::stoi(studentInfo[4]), std::stoi(studentInfo[5]), std::stoi(studentInfo[6]), std::stoi(studentInfo[7]), dp);
    }

    classRoster.printAll();

    for (int i = 0; i < numStudents; i++) {
        std::istringstream ss(studentData[i]);
        std::string studentID;
        std::getline(ss, studentID, ',');
        classRoster.printAverageDaysInCourse(studentID);
    }

    classRoster.printInvalidEmails();

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    classRoster.remove("A3");
    
    classRoster.remove("A3");

    return 0;
}
