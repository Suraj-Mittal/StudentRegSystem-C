/******************************************************** 
* Title: Lab Assessment #3 - Student Registration System 
* Course: CST8234 C Language
* File: input.h
* @Author: Suraj Mittal (041027220)
* Lab Section: 012
* Professor: Surbhi Bahri
* Due date: 03/07/2022
* Submission date: 03/07/2022 
*********************************************************/

//importing all te required c libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/****************************************************************************
Function Name: validateStudentId
Purpose: validates if the provided student id is 5 digits only or not
Function in parameters: pointer to student id to validate
Function out parameter: boolean, true if validated correct else false
Version: 1
Author: Suraj Mittal
*****************************************************************************/
bool validateStudentId(int* studentId);

/****************************************************************************
Function Name: validateCourseId
Purpose: validates if the provided course id is 3 alpha characters and 4 digits not
Function in parameters: pointer to courseId id to validate
Function out parameter: boolean, true if validated correct else false
Version: 1
Author: Suraj Mittal
*****************************************************************************/
bool validateCourseId(char *buffer);

/****************************************************************************
Function Name: validateIntegerInput
Purpose: validates if the provided number integer or not
Function in parameters: pointer to number to validate
Function out parameter: void
Version: 1
Author: Suraj Mittal
*****************************************************************************/
void validateIntegerInput(int *number);

/****************************************************************************
Function Name: parse_int
Purpose: validates if the provided number integer or not
Function in parameters: pointer to string to conver to int, and pointer to int to store the coverted integer
Function out parameter: boolean, true on success else false
Version: 1
Author: Suraj Mittal
*****************************************************************************/
bool parse_int(char *string, int *integer);