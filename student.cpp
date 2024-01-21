//
//  student.cpp
//  studentData_Table
//
//  Created by Rayyan Kerkmaz on 12/22/23.
//

#include <iostream>
#include <string>
#include "student.h"
using namespace std;

// Initialize daysinCourseArraySize
const int Student::daysinCourseArraySize;  // D: CLASS STUDENT - Constant initialization

// Constructors
Student::Student() {
    // Default values
    this->studentID = "";  // D2A: ACCESSOR - Default value for studentID
    this->firstName = "";  // D2A: ACCESSOR - Default value for firstName
    this->lastName = "";  // D2A: ACCESSOR - Default value for lastName
    this->email = "";  // D2A: ACCESSOR - Default value for email
    this->age = 0;  // D2A: ACCESSOR - Default value for age
    this->degreeProgram = DegreeProgram::SECURITY;  // D2A: ACCESSOR - Default value for degreeProgram
    for (int i = 0; i < daysinCourseArraySize; ++i) {
        this->daysinCourse[i] = 0;  // D2A: ACCESSOR - Default value for daysinCourse
    }
}

Student::Student(std::string studentID, std::string firstName, std::string lastName,
                 std::string email, int age, int daysinCourse[], DegreeProgram degreeProgram) {
    // Pointer initialization.
    this->studentID = studentID;  // D2A: ACCESSOR - Initialize studentID
    this->firstName = firstName;  // D2A: ACCESSOR - Initialize firstName
    this->lastName = lastName;  // D2A: ACCESSOR - Initialize lastName
    this->email = email;  // D2A: ACCESSOR - Initialize email
    this->age = age;  // D2A: ACCESSOR - Initialize age
    this->degreeProgram = degreeProgram;  // D2A: ACCESSOR - Initialize degreeProgram
    for (int i = 0; i < daysinCourseArraySize; ++i) {
        this->daysinCourse[i] = daysinCourse[i];  // D2A: ACCESSOR - Initialize daysinCourse
    }
}

Student::~Student() {}  // D: CLASS STUDENT - Destructor

// Getter functions
std::string Student::getID() {
    return this->studentID;  // D2A: ACCESSOR - Return studentID
}
std::string Student::getfirstName() {
    return this->firstName;  // D2A: ACCESSOR - Return firstName
}
std::string Student::getlastName() {
    return this->lastName;  // D2A: ACCESSOR - Return lastName
}
std::string Student::getemail() {
    return this->email;  // D2A: ACCESSOR - Return email
}
int Student::getage() {
    return this->age;  // D2A: ACCESSOR - Return age
}
int* Student::getdaysinCourse() {
    return this->daysinCourse;  // D2A: ACCESSOR - Return daysinCourse
}
DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;  // D2A: ACCESSOR - Return degreeProgram
}

// Setter functions
void Student::setID(std::string studentID) { this->studentID = studentID; }  // D2B: MUTATOR - Set studentID
void Student::setfirstName(std::string firstName) { this->firstName = firstName; }  // D2B: MUTATOR - Set firstName
void Student::setlastName(std::string lastName) { this->lastName = lastName; }  // D2B: MUTATOR - Set lastName
void Student::setemail(std::string email) { this->email = email; }  // D2B: MUTATOR - Set email
void Student::setage(int age) { this->age = age; }  // D2B: MUTATOR - Set age
void Student::setdaysinCourse(int daysinCourse[]) {  // D2B: MUTATOR - Set daysinCourse
    for (int i = 0; i < daysinCourseArraySize; ++i) {
        this->daysinCourse[i] = daysinCourse[i];
    }
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }  // D2B: MUTATOR - Set degreeProgram

void Student::printHeader() {
    std::cout << "output format: studentID||firstName||lastName||email||age||Days in course\n";  // F1: SCREEN PRINT OUT - Print header
}

// Print function
void Student::print() {
    std::cout << this->studentID << '\t';  // F1: SCREEN PRINT OUT - Print studentID
    std::cout << this->firstName << '\t';  // F1: SCREEN PRINT OUT - Print firstName
    std::cout << this->lastName << '\t';  // F1: SCREEN PRINT OUT - Print lastName
    std::cout << this->email << '\t';  // F1: SCREEN PRINT OUT - Print email
    std::cout << this->age << '\t';  // F1: SCREEN PRINT OUT - Print age
    std::cout << this->daysinCourse[0] << ", " << this->daysinCourse[1] << ", " << this->daysinCourse[2] << "}\t";  // F1: SCREEN PRINT OUT - Print daysinCourse
    std::cout << degreeProgramStrings[static_cast<int>(this->degreeProgram)] << '\n';  // F1: SCREEN PRINT OUT - Print degreeProgram
}
