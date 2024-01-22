# Student Data Management System

This C++ project, **Student Data Management System**, is designed to manage student information using object-oriented programming principles.

## Table of Contents

- [Description](#description)
- [Project Structure](#project-structure)
- [Features](#features)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  -  [Trouble Shooting](#trouble-shooting)
- [Usage](#usage)
- [File Descriptions](#file-descriptions)
- [Sample Data](#sample-data)
- [How to Contribute](#how-to-contribute)
- [License](#license)

## Description

This project implements a Student Data Management System where students' information is stored, managed, and displayed using classes and objects in C++. The system includes functionalities such as adding students, removing students, printing student details, and more.

## Project Structure

- **main.cpp**: Main program file containing the project's entry point.
- **roster.h, roster.cpp**: Implementation of the Roster class, responsible for managing students.
- **student.h, student.cpp**: Implementation of the Student class, defining student attributes and behaviors.
- **degree.h, degree.cpp**: Definition of the DegreeProgram enumeration.
- **studentData.csv**: Sample data file containing student information for testing.

## Features

- Add students to the system.
- Remove students from the system.
- Print details of all students.
- Calculate and display average days in the course for each student.
- Identify and print invalid email addresses.
- Print students based on their degree program.

### Prerequisites

- C++ development environment (e.g., Visual Studio, Code::Blocks).
- Standard C++ libraries.

### Installation

1. Clone the repository.
2. Open the project in your preferred C++ development environment.
3. Build and run the project.

## Troubleshooting

### Xcode Build Error: "No rule to process file"

If you encounter the following error during the build process in Xcode:


#### Solution

This error may occur when Xcode encounters difficulties processing certain file types, such as `.hpp` files.

1. **Step 1**: Identify the problematic files causing the error. In this case, it was the `.hpp` files.
2. **Step 2**: Delete the `.hpp` files from the source build directory.

This should resolve the "No rule to process file" error. If you face similar issues with file processing, consider checking the compatibility of file types with your Xcode build settings.

Feel free to update this section with any other encountered errors and their solutions during your project development.

## Usage

- Follow the on-screen instructions to interact with the system.
- Refer to the code comments for detailed information on each section.

## File Descriptions

- **main.cpp**: Main program file with the entry point and main logic.
- **roster.h, roster.cpp**: Implementation of the Roster class with student management functions.
- **student.h, student.cpp**: Implementation of the Student class with student attributes and behaviors.
- **degree.h, degree.cpp**: Definition of the DegreeProgram enumeration.
- **studentData.csv**: Sample data file for testing.

## Sample Data

Use the provided sample data in **studentData.csv** for testing the system.

## How to Contribute

1. Fork the project.
2. Create a new branch.
3. Make your changes.
4. Submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
