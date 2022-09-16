/********************************************************
* Title: Lab Assessment #3 - Student Registration System 
* Course: CST8234 C Language
* File: registration.c
* @Author: Suraj Mittal (041027220)
* Lab Section: 012
* Professor: Surbhi Bahri
* Due date: 03/07/2022
* Submission date: 03/07/2022 
*********************************************************/

//including required libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/****************************************************************************
Function Name: registerStudent
Purpose: registers a student with the provided student and course id into a registration table
Function in parameters: registration- double pointer to registration table, numRegistrations- number of registrations so far in the table, sindex- index of student in the studentID array to register in the table, cindex- index of course in the courseID to register a student into
Function out parameter: boolean, true if registration is successful else false
Version: 1
Author: Suraj Mittal
*****************************************************************************/
bool registerStudent(int** registration, int* numRegistrations, int sindex, int cindex) {
    
    if(*(*(registration + sindex) + cindex) == -1) {                   //checks if the value of registration status at the location(based on the provided student and course ID by the user) in the registration table
        //if the values equals to -1 then register the student by assigning 1
        *(*(registration + sindex) + cindex) = 1;
        *numRegistrations += 1;                                             //now if the student is registred increase the number of registrations count
        return true;  
    }
    //if the value equals to 1 that means student is already registered so returns false
    else if(*(*(registration + sindex) + cindex) == 1) {
        printf("\nStudent is already registered with the course");
        return false;
    }
    //if the value equals to 0 that means student has dopped out from the course so returns false
    else if(*(*(registration + sindex) + cindex) == 0) {
        printf("\nStudent has dropped out from the selected course.");
        return false;
    }
    return false;
}

/****************************************************************************
Function Name: withdrawStudent
Purpose: drops a student registration with the provided registration index
Function in parameters: registration- double pointer to registration table, registrationIndex- index of registration table to drop, registeredStudentIndex - pointer to array storing indexes of registered student IDs, registeredCourseIndex - pointer to array storing indexes of registered course IDs
Function out parameter: boolean, true if drop is successful else false
Version: 1
Author: Suraj Mittal
*****************************************************************************/
bool withdrawStudent(int** registration, int registrationIndex, int* registeredStudentIndex, int* registeredCourseIndex) {
    
    //if the value of registration status in the registration table(based on student ID and course ID at the registratiomn index) equals to 1 this means student is registered so set it to 0 which indicates false
    if(*(*(registration + registeredStudentIndex[registrationIndex]) + registeredCourseIndex[registrationIndex]) == 1) {
        *(*(registration + registeredStudentIndex[registrationIndex]) + registeredCourseIndex[registrationIndex]) = 0;
        return true;
    }
    //if the value equals 0 this means student is already dropped out from the course 
    else if(*(*(registration + registeredStudentIndex[registrationIndex]) + registeredCourseIndex[registrationIndex]) == 0) {
        printf("\nStudent is already dropped out of this course.");
        return false;
    }
    else {
        return false;
    }

}