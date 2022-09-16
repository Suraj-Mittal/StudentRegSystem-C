/******************************************************** 
* Title: Lab Assessment #3 - Student Registration System 
* Course: CST8234 C Language
* File: display.c
* @Author: Suraj Mittal (041027220)
* Lab Section: 012
* Professor: Surbhi Bahri
* Due date: 03/07/2022
* Submission date: 03/07/2022 
*********************************************************/

//including all the required libraries
#include <stdlib.h>
#include <stdio.h>

//iterator
int i = 0;

/****************************************************************************
Function Name: displayMenu
Purpose: displays Main Menu
Function in parameters: nothing
Function out parameter: void
Version: 1
Author: Suraj Mittal
*****************************************************************************/
void displayMenu() {
    printf("\n\n********** Main Menu **********\n");
    printf("\n1. Register a student in a course.\n2. Withdraw a student from a course.\n3. Display registeration table\n4. Exit\nEnter an option: ");
}

/****************************************************************************
Function Name: displayStudents
Purpose: displays list of student IDs
Function in parameters: integer numStudents- number of students to display, studentId- pointer to array of student IDs
Function out parameter: void
Version: 1
Author: Suraj Mittal
*****************************************************************************/
void displayStudents(int numStudents, int* studentId) {
    printf("\n\nList of Student IDs\n");

    //displays student IDs one by one
    for (i=0; i < numStudents; i++) {
        printf("\nIndex %d\t\t %d", i, studentId[i]);
    }   
}

/****************************************************************************
Function Name: displayCourses
Purpose: displays list of course IDs
Function in parameters: integer numCourses- number of courses to display, courseId- pointer to array of course IDs
Function out parameter: void
Version: 1
Author: Suraj Mittal
*****************************************************************************/
void displayCourses(int numCourses, char** courseId) {
    printf("\n\nList of Available Course IDs\n");

    //displays courseIDs one by one
    for (i=0; i < numCourses; i++) {
        printf("\nIndex %d\t\t %s", i, courseId[i]);
    }  
}

/****************************************************************************
Function Name: registrationTable
Purpose: displays registration table consisting all the registrations made so far
Function in parameters: registration- double pointer to registration table, numRegistrations- number of registrations, sindex- pointer to array of student indexes of registeratons, cindex- pointer to array of course indexes of registeratons, studentId - pointer to array of student IDs, courseId- pointer to array of course IDs
Function out parameter: void
Version: 1
Author: Suraj Mittal
*****************************************************************************/
void registrationTable(int** registration, int numRegistrations, int* sindex, int* cindex, int* studentId, char** courseId) {

    printf("\n\t\t\t\tRegistration Table\n");
    printf ("\nRegistration Index\t Student ID\t Course ID\t Registration Status\n");
    //printing registratons one by one
    for(i=0 ; i< numRegistrations; i++) {
        printf("\n\t %d", i);
        printf("\t\t  %d", studentId[sindex[i]]);
        printf("\t\t  %s", courseId[cindex[i]]);
        //if value is 1 prints R
        if (*(*(registration + sindex[i]) + cindex[i]) == 1) {
            printf("\t\tR");
        }
        // if value is 0 prints D
        else if(*(*(registration + sindex[i]) + cindex[i]) == 0) {
            printf("\t\tD");
        }
    }

}