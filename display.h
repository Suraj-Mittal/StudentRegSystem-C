/********************************************************
* Title: Lab Assessment #3 - Student Registration System 
* Course: CST8234 C Language
* File: display.h
* @Author: Suraj Mittal (041027220)
* Lab Section: 012
* Professor: Surbhi Bahri
* Due date: 03/07/2022
* Submission date: 03/07/2022 
*********************************************************/

/****************************************************************************
Function Name: displayMenu
Purpose: displays Main Menu
Function in parameters: nothing
Function out parameter: void
Version: 1
Author: Suraj Mittal
*****************************************************************************/
void displayMenu();

/****************************************************************************
Function Name: displayStudents
Purpose: displays list of student IDs
Function in parameters: integer numStudents- number of students to display, studentId- pointer to array of student IDs
Function out parameter: void
Version: 1
Author: Suraj Mittal
*****************************************************************************/
void displayStudents(int numStudents, int* studentId);

/****************************************************************************
Function Name: displayCourses
Purpose: displays list of course IDs
Function in parameters: integer numCourses- number of courses to display, courseId- pointer to array of course IDs
Function out parameter: void
Version: 1
Author: Suraj Mittal
*****************************************************************************/
void displayCourses(int numCourses, char** courseId);

/****************************************************************************
Function Name: registrationTable
Purpose: displays registration table consisting all the registrations made so far
Function in parameters: registration- double pointer to registration table, numRegistrations- number of registrations, sindex- pointer to array of student indexes of registeratons, cindex- pointer to array of course indexes of registeratons, studentId - pointer to array of student IDs, courseId- pointer to array of course IDs
Function out parameter: void
Version: 1
Author: Suraj Mittal
*****************************************************************************/
void registrationTable(int** registration, int numRegistrations, int* sindex, int* cindex, int* studentId, char** courseId);