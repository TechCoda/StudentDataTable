//  roster.cpp
//  studentData_Table
//
//  Created by TechCoda on 12/22/23.
//

#include "roster.h"
#include <iostream>
#include <sstream>

const int Roster::initialCapacity;

// Function to convert degreeProgramStr to DegreeProgram enum
DegreeProgram convertToDegreeProgram(const std::string& degreeProgramStr) {
    // C: ENUMERATED DATA TYPE
    // Convert the string representation of DegreeProgram to the corresponding enum value
    if (degreeProgramStr == "SECURITY") {
        return DegreeProgram::SECURITY;
    } else if (degreeProgramStr == "NETWORK") {
        return DegreeProgram::NETWORK;
    } else if (degreeProgramStr == "SOFTWARE") {
        return DegreeProgram::SOFTWARE;
    }
    return DegreeProgram::SOFTWARE;  // Default to SOFTWARE if not recognized
}

// Roster class member function implementations

Roster::Roster() {
    // D1: CLASS STUDENT
    // Constructor: Initialize the Roster object
    lastIndex = -1;
    classRosterArray = new Student*[initialCapacity];  // Allocate initialCapacity elements
}

Student** Roster::getStudents() const {
    return classRosterArray;
}

int Roster::getLastIndex() const {
    return lastIndex;
}

Roster::~Roster() {
    // F5: DESTRUCTOR
    // Destructor: Deallocate memory for each student and the dynamic array
    for (int i = 0; i <= lastIndex; ++i) {
        delete classRosterArray[i];
    }
    delete[] classRosterArray;  // Deallocate the dynamic array
}

void Roster::parse(std::string row) {
    std::istringstream ss(row);
    std::string studentID, firstName, lastName, emailAddress, ageStr, days1Str, days2Str, days3Str, degreeProgramStr;
    int age, days1, days2, days3;
    DegreeProgram degreeProgram;

    // E2A: PARSED DATA
    // Parse the input string and call add function
    getline(ss, studentID, ',');
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, emailAddress, ',');
    getline(ss, ageStr, ',');
    getline(ss, days1Str, ',');
    getline(ss, days2Str, ',');
    getline(ss, days3Str, ',');
    getline(ss, degreeProgramStr, ',');

    // Convert string values to appropriate types
    age = std::stoi(ageStr);
    days1 = std::stoi(days1Str);
    days2 = std::stoi(days2Str);
    days3 = std::stoi(days3Str);

    // Use the convertToDegreeProgram function
    degreeProgram = convertToDegreeProgram(degreeProgramStr);

    // Call the add function
    add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    // E3A: ADD FUNCTION
    // Add a new student to the roster
    if (lastIndex < initialCapacity - 1) {
        lastIndex++;

        Student* newStudent = new Student(
            studentID, firstName, lastName, emailAddress, age,
            new int[Student::daysinCourseArraySize] {daysInCourse1, daysInCourse2, daysInCourse3},
            degreeProgram
        );

        classRosterArray[lastIndex] = newStudent;
    } else {
        std::cerr << "Error: Unable to add student. Roster is full." << std::endl;
    }
}

void Roster::remove(std::string studentID) {
    // E3B: REMOVE FUNCTION
    // Remove a student from the roster by student ID
    bool studentFound = false;

    // Iterate through the roster to find the student with the specified ID
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] && classRosterArray[i]->getID() == studentID) {
            // Found the student, remove from roster
            studentFound = true;
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;

            // Shift remaining elements
            for (int j = i; j < lastIndex; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
            }

            // Decrement lastIndex after removal
            lastIndex--;
            break;
        }
    }

    // Print an error message if student not found
    if (!studentFound) {
        std::cerr << "Error: Student with ID " << studentID << " not found." << std::endl;
    }
}

void Roster::printAll() {
    // E3C: PRINT ALL FUNCTION
    // Print information for all students in the roster
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    // E3D: PRINT AVERAGE FUNCTION
    // Print the average number of days in courses for a specific student
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] && classRosterArray[i]->getID() == studentID) {
            double average = classRosterArray[i]->getAverageDaysInCourse();
            std::cout << "Student ID: " << studentID << ", average days in course is: " << average << std::endl;
            return;
        }
    }
    std::cerr << "Error: Student with ID " << studentID << " not found." << std::endl;
}

void Roster::printInvalidEmails() {
    // E3E: PRINT INVALID EMAILS FUNCTION
    // Print invalid email addresses for students in the roster
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]) {
            std::string email = classRosterArray[i]->getemail();
            if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
                std::cout << "Invalid email: " << email << " (Student ID: " << classRosterArray[i]->getID() << ")\n";
            }
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram dp) {
    // E3F: PRINT DEGREE PROGRAM FUNCTION
    // Print information for students in the roster based on degree program
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] && classRosterArray[i]->getDegreeProgram() == dp) {
            classRosterArray[i]->print();
        }
    }
}
