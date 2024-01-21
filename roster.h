//
//  roster.h
//  studentData_Table
//
//  Created by Rayyan Kerkmaz on 12/22/23.
//
#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

class Roster {
private:
    static const int initialCapacity = 5;  // C: ENUMERATED DATA TYPE - Add this line
    Student** classRosterArray;
    int lastIndex;

public:
    Roster();  // D1: CLASS STUDENT - Constructor
    ~Roster();  // F5: DESTRUCTOR - Destructor

    void parse(std::string row);  // E2A: PARSED DATA - Parse input string and call add function
    void add(
        std::string studentID, std::string firstName, std::string lastName,
        std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
        int daysInCourse3, DegreeProgram degreeProgram);  // E3A: ADD FUNCTION - Add a new student to the roster

    void remove(std::string studentID);  // E3B: REMOVE FUNCTION - Remove a student from the roster by student ID
    void printAll();  // E3C: PRINT ALL FUNCTION - Print information for all students in the roster
    void printAverageDaysInCourse(std::string studentID);  // E3D: PRINT AVERAGE FUNCTION - Print average days in courses for a specific student
    void printInvalidEmails();  // E3E: PRINT INVALID EMAILS FUNCTION - Print invalid email addresses for students in the roster
    void printByDegreeProgram(DegreeProgram dp);  // E3F: PRINT DEGREE PROGRAM FUNCTION - Print information for students based on degree program

    // Accessor methods
    Student** getStudents() const;  // D2A: ACCESSOR - Accessor function for the classRosterArray
    int getLastIndex() const;  // D2A: ACCESSOR - Accessor function for the lastIndex

    // New member function to check if a student with the given ID exists
    bool isStudentExists(std::string studentID) const;
};
#endif
