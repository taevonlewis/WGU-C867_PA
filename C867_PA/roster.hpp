//
//  roster.hpp
//  C867_PA
//
//  Copyright © 2024 TaeVon Lewis. All rights reserved.
//


#ifndef roster_hpp
#define roster_hpp

#pragma once
#include "student.hpp"

class Roster {
public:
    Roster();
    ~Roster();

    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram deg);
    void remove(std::string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

private:
    Student* classRosterArray[5];
    int lastIndex = -1;
};

#endif /* roster_hpp */
