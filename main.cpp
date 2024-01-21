//  main.cpp
//  studentData_Table
//
//  Created by Rayyan Kerkmaz on 12/21/23.
//
#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
    // F1: SCREEN PRINT OUT
    // Print information about the course, language, WGU student ID, and name.
    std::cout << "Course Title: C867-Scripting & Programming: Applications\n";
    std::cout << "Language: C++\n";
    std::cout << "Student ID: 010683870\n";
    std::cout << "Name: Rayyan Kerkmaz\n\n";

    // F2: ROSTER CLASS INSTANCE
    // Creating a Roster object
    Roster classRoster;

    // F3: ADD STUDENTS
    // Adding students to the roster
    classRoster.add("A1", "John", "Smith", "john1989@em ail.com", 20, 30, 35, 40, DegreeProgram::SECURITY);
    classRoster.add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, DegreeProgram::NETWORK);
    classRoster.add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, DegreeProgram::SOFTWARE);
    classRoster.add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, DegreeProgram::SECURITY);
    classRoster.add("A5", "Rayyan", "Kerkmaz", "rkerkma@wgu.edu", 31, 25, 35, 40, DegreeProgram::SOFTWARE);

    // F4: PSEUDO CODE CONVERSION
    // Displaying all students
    std::cout << "Displaying all students:\n";
    classRoster.printAll();

    // Displaying invalid emails
    std::cout << "\nPrinting Invalid Emails:\n";
    classRoster.printInvalidEmails();

    // Displaying average days in course for each student
    std::cout << "\nPrinting Average Days in Course:\n";
    for (int i = 0; i <= classRoster.getLastIndex(); ++i) {
        if (classRoster.getStudents()[i]) {
            std::string studentID = classRoster.getStudents()[i]->getID();
            std::cout << "Student ID: " << studentID << ", average days in course is: ";
            double averageDays = classRoster.getStudents()[i]->getAverageDaysInCourse();
            std::cout << static_cast<int>(averageDays) << "\n";
        }
    }

    // empty line for average days.
    std::cout << std::endl;

    // Print students by degree program
    std::cout << "\nPrinting Students by Degree Program (SOFTWARE):\n";
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    // Remove a student
    std::cout << "\nRemoving Student A3:\n";
    classRoster.remove("A3");

    // Print all students after removal
    std::cout << "\nPrinting All Students After Removal:\n";
    classRoster.printAll();

    // F5: DESTRUCTOR
    // Destructor will be automatically called when classRoster goes out of scope

    return 0;
}
