//
//  student.h
//  studentData_Table
//
//  Created by TechCoda on 12/22/23.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student
{
public: // constant
    const static int daysinCourseArraySize = 3;  // D: CLASS STUDENT - Constant for daysinCourse array size

private: // object
    std::string studentID;  // D1: CLASS STUDENT - Member variable for studentID
    std::string firstName;  // D1: CLASS STUDENT - Member variable for firstName
    std::string lastName;  // D1: CLASS STUDENT - Member variable for lastName
    std::string email;  // D1: CLASS STUDENT - Member variable for email
    int age;  // D1: CLASS STUDENT - Member variable for age
    int daysinCourse[daysinCourseArraySize];  // D1: CLASS STUDENT - Member variable for daysinCourse array
    DegreeProgram degreeProgram;  // D1: CLASS STUDENT - Member variable for degreeProgram enum

public:
    Student();  // D1: CLASS STUDENT - Default constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysinCourse[], DegreeProgram degreeProgram);  // D1: CLASS STUDENT - Constructors
    ~Student();  // D: CLASS STUDENT - Destructor

    std::string getID();  // D2A: ACCESSOR - Getter function for studentID
    std::string getfirstName();  // D2A: ACCESSOR - Getter function for firstName
    std::string getlastName();  // D2A: ACCESSOR - Getter function for lastName
    std::string getemail();  // D2A: ACCESSOR - Getter function for email
    int getage();  // D2A: ACCESSOR - Getter function for age
    int *getdaysinCourse();  // D2A: ACCESSOR - Getter function for daysinCourse array
    DegreeProgram getDegreeProgram();  // D2A: ACCESSOR - Getter function for degreeProgram

    void setID(std::string studentID);  // D2B: MUTATOR - Setter function for studentID
    void setfirstName(std::string firstName);  // D2B: MUTATOR - Setter function for firstName
    void setlastName(std::string lastName);  // D2B: MUTATOR - Setter function for lastName
    void setemail(std::string email);  // D2B: MUTATOR - Setter function for email
    void setage(int age);  // D2B: MUTATOR - Setter function for age
    void setdaysinCourse(int daysinCourse[]);  // D2B: MUTATOR - Setter function for daysinCourse array
    void setDegreeProgram(DegreeProgram dp);  // D2B: MUTATOR - Setter function for degreeProgram

    static void printHeader();  // D2E: PRINTING SPECIFIC DATA - Static function to print header

    void print();  // D2E: PRINTING SPECIFIC DATA - Print function

    int getAverageDaysInCourse() const {
        // Calculate the average days in the course and round to the nearest whole number
        return (daysinCourse[0] + daysinCourse[1] + daysinCourse[2] + daysinCourseArraySize / 2) / daysinCourseArraySize;  // D2E: PRINTING SPECIFIC DATA - Calculate and return average days in course
    }
};

#endif /* STUDENT.HPP */
