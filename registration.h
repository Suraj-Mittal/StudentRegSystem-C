/********************************************************
* Title: Lab Assessment #3 - Student Registration System 
* Course: CST8234 C Language
* File: registration.h
* @Author: Suraj Mittal (041027220)
* Lab Section: 012
* Professor: Surbhi Bahri
* Due date: 03/07/2022
* Submission date: 03/07/2022 
*********************************************************/

//including the required libraries
#include <stdbool.h>

/****************************************************************************
Function Name: registerStudent
Purpose: registers a student with the provided student and course id into a registration table
Function in parameters: registration- double pointer to registration table, numRegistrations- number of registrations so far in the table, sindex- index of student in the studentID array to register in the table, cindex- index of course in the courseID to register a student into
Function out parameter: boolean, true if registration is successful else false
Version: 1
Author: Suraj Mittal
*****************************************************************************/
bool registerStudent(int** registration, int* numRegistrations, int sindex, int cindex);

/****************************************************************************
Function Name: withdrawStudent
Purpose: drops a student registration with the provided registration index
Function in parameters: registration- double pointer to registration table, registrationIndex- index of registration table to drop, registeredStudentIndex - pointer to array storing indexes of registered student IDs, registeredCourseIndex - pointer to array storing indexes of registered course IDs
Function out parameter: boolean, true if drop is successful else false
Version: 1
Author: Suraj Mittal
*****************************************************************************/
bool withdrawStudent(int** registration, int registrationIndex, int* registeredStudentIndex, int* registeredCourseIndex);