/* ******************************************************
* Title: Lab Assessment #3 - Student Registration System 
* Course: CST8234 C Language
* File: main.c
* @Author: Suraj Mittal (041027220)
* Lab Section: 012
* Professor: Surbhi Bahri
* Due date: 03/07/2022
* Submission date: 03/07/2022 
*********************************************************/

/*importing all the required c librariea*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"                  /*importing the local input header file which declares methods related to taking user inputs*/
#include "registration.h"           /*importing the local registration header file which declares methods related to registring and drop a student from a course */
#include "display.h"                /*importing the local display header file which declared methods related to displaying registration table, Student IDs and course IDs*/
#include <stdbool.h>

#define BUFFER_SIZE 4096                 /*Defining the size of all the buffer memories used throughout the program*/

/*Declaration of all the required variables*/
int **registration;                      /*double pointer for registration table*/
int *studentId;                          /*pointer to point an array of student IDs*/
char **courseId;                         /*double pointer to point to pointers pointing to array of characters*/
int numRegistrations = 0;                /*variabke to hold the value of number of registrations made in the registration table*/
int numStudents = 0;                     /*stores the total number of students input by the user*/
int numCourses = 0;                      /*stores the total number of courses input by the user*/
int *registeredCourseIndex;              /*pointer to an array which stores indexes of course IDs in the order as they are in the registration table*/
int *registeredStudentIndex;             /*pointer to an array which stores indexes of student IDs in the order as they are in the registration table*/
int registrationIndex = -1;              /*This variable stores the index selected by the user to drop a registration*/

/****************************************
Function Name: main
Purpose: Student Registeration System
Function in parameters: empty or not applicable
Function out parameter: EXIT_SUCCESS
Version: 1
Author: Suraj Mittal
*****************************************/
int main() {
    
    int menuOption;                         /*holds the user input value of selected menu option*/
    bool is_mo_correct;                     /*this stores if menu option entered by user is valid or not*/
    bool is_nostudents_correct;             /*this stores if number of students value entered by user is valid or not*/
    bool is_cn_correct;                     /*this stores if number of courses value entered by user is valid or not*/
    int i,j;                                /*loop iterator variables*/

    printf("Welcome to Student Registeration System.\n\n");
    
    /*This loop will continue until a valid number is entered*/
    do {
        printf("Enter the number of students to register: ");

        char numStudents_Buffer[BUFFER_SIZE];        /*to temporarily store user input as strings*/
        scanf("%s", numStudents_Buffer);             /*takes user input*/

        is_nostudents_correct = parse_int(numStudents_Buffer, &numStudents); // validate the integer input, store the int into integer if it was validated as correct
        
        /*if the parse_int function returns false which it returns when the input is invalid*/
        if(!is_nostudents_correct) {
            printf("Invalid input\n");
        }

    } while(!is_nostudents_correct);

    studentId = (int*)malloc(sizeof(int)*numStudents);  /*allocating memory to studentId pointer based on number of students entered by the user*/

    if (studentId == NULL) {
        return EXIT_FAILURE;                /*the program will return with exit failure if malloc fails to allocate the memory*/
    }

    /*this loop will take studentIDs of all the students*/
    for(i=0; i<numStudents; i++) {
        bool is_sid_correct = true;            /*boolean to store if student ID entered is correct or not*/
  
        // keep asking the user for an integer until it has been validated as correct
        do
        {
            // prompt the user for the integer
            printf("\nEnter student ID for student %d [5-digits]: ", i);
            
            // accept a line of string input from the user, store it into buffer
            char buffer[BUFFER_SIZE];
            scanf("%s", buffer);
            
            // validate the integer input, store the int into integer if it was validated as correct
            is_sid_correct = parse_int(buffer, &studentId[i]);
            
            // if the input was not a valid integer, tell the user this
            if (!is_sid_correct) {
                printf("Must be a positive integer value.\n");
            }
            else { 
                is_sid_correct = validateStudentId(&studentId[i]);   //if the input is valid, now check the range because student ID can only be 5 digits
                /*if student id entered does not consists only 5 digits then tell the user this*/
                if (!is_sid_correct)
                    printf("Student ID must consists 5 digits only.\n");
            }
        } while (!is_sid_correct);
    }
    
    /*This loop will continue until a valid number of courses is entered*/
    do {
        
        /*prompting the user to enter number of courses*/
        printf("\nEnter the number of courses offered: ");

        char cn_buffer[BUFFER_SIZE];                        /*to temporarily store user input as strings*/
        scanf("%s", cn_buffer);                             /*takes user input*/
        
        is_cn_correct = parse_int(cn_buffer, &numCourses);  // validate the integer input, store the int into integer if it was validated as correct

        // if the input is not valid, tells the user
        if(!is_cn_correct)
            printf("Invalid Input");

    } while (!is_cn_correct);

    courseId = (char**)malloc(sizeof(char*) * numCourses);  /*allocating memory to courseId pointer to point number of points based on number of courses entered by the user*/

    if(courseId == NULL) {
        return EXIT_FAILURE;  // if malloc fails to allocate memory the program will exit
    }

    // loop to get input of courseIDs of all the courses
    for(i = 0; i < numCourses; i++) {
        bool is_cid_correct;              // booleanto store if course id entered by user is valid or not

        // loop will continur to until a valid course ID is entered
        do {
            
            // prompting the user to enter the course ID
            printf("\nEnter course ID for course %d [3-Alphas][4-digits]: ", i);
            char courseBuffer[BUFFER_SIZE];               //to temporarily store course ID
            int length = 0;                               //to store length of string entered by the user
            
            
            /*if(stdin != NULL) {
                while(getchar() != '\n');
            }

            fgets(courseBuffer, BUFFER_SIZE, stdin);*/
            scanf("%s", courseBuffer);                    //takes the user input as string
            length = strlen(courseBuffer);                // getting the length of user input
            //courseBuffer[length-1] = '\0';
            is_cid_correct = validateCourseId(courseBuffer);  // validate the course ID entered by the user and returns true if valid else false

            //if course ID not correct, tells the user
            if (!is_cid_correct) {
                printf("\nIncorrect Course Id input [3-Alphas][4-digits]");
            }
            else {
                courseId[i] = malloc(sizeof(char) * length+1);      //allocating memory to the respective course ID pointer.
                strcpy(courseId[i], courseBuffer);                  //copying the valid courseID to the courseID array.
            }

        } while(!is_cid_correct);
    }

    registration = (int**)malloc(sizeof(int*) * numStudents);       //allocating memory to a double pointer registration, pointing to number(same as number of courses) of pointers 
    
    if (registration == NULL) {
        return EXIT_FAILURE;           //if malloc fails to allocate memory
    }

    // this loop will continue number of students of times
    for (i = 0; i < numStudents; i++) {
        registration[i] = (int*)malloc(sizeof(int) * numCourses);  //allocating memory to the single pointer in registration to point to number(number of courses) of pointers
    }

    // this loop will initializes all the elements of registration array to -1 to avoid conflicts with value 0
    for(i=0; i<numStudents; i++) {
        for(j=0; j<numCourses; j++) {
            *(*(registration + i) + j) = -1;
        }
    }
    
    // dynamically allocating arrays to stores studentID index and course ID index as per in student ID and course ID in the order they are registered in the registration table
    registeredCourseIndex = (int*)malloc(numCourses * numStudents);
    registeredStudentIndex = (int*)malloc(numCourses * numStudents);
    
    //this loop will continue to display menu and perform actions as per the user input unless user selects option 4 to exit the program
    while (menuOption != 4) {
        
        // loop to validate user menu selection. this loop will continue until a valid menu option is selected
        do {
            displayMenu();

            char menuBuffer[BUFFER_SIZE];                          //to temporarily store user input as string
            scanf("%s", menuBuffer);                               //takes user input

            is_mo_correct = parse_int(menuBuffer, &menuOption);    // validates user input and assigns to menuOption variable if a valid input is entered
            
            // if an invalid input is entered tell the user
            if(!is_mo_correct) {
                printf("Invalid input\n");
            }

        } while (!is_mo_correct);


        switch (menuOption)
        {
        
        // register a student into a course
        case 1:
            displayStudents(numStudents, studentId);     //displays all the students
            
            bool is_cid_correct;                         //boolean to store if course ID entered to register a student into is correct or not
            int tempsid = 0;                             // variable to store student id to register a student
            int sindex = -1;                             // to store index of studentID of a student to be registered
            int cindex = -1;                             // to store index of courseID of a course to be registered into
            char* tempcid = NULL;                        // to store course ID to be registered into
            bool is_sid_correct = true;                  //boolean to store if student ID entered to register a student is correct or not

            do
            {
            // prompt the user for the integer
            printf("\nEnter Student's ID to register into a course [5-digits]: ");
            
            // accept a line of string input from the user, store it into buffer
            char registerbuffer[BUFFER_SIZE];
            scanf("%s", registerbuffer);
            
            // validate the integer input, store the int into integer if it was 
            // validated as correct
            is_sid_correct = parse_int(registerbuffer, &tempsid);
            
            // if the input was not a valid integer, tell the user this
            if (!is_sid_correct) {
                printf("Must be a positive integer value.\n");
            }
            else { 
                is_sid_correct = validateStudentId(&tempsid);             //validating the range of student ID
                //if not in range of 5 digits
                if (!is_sid_correct)
                    printf("Student ID must consists 5 digits only.\n");
            }
            } while (!is_sid_correct);

            //loop to iterate over all student IDs to find a matching ID to user entered ID
            for(i=0; i < numStudents; i++) {
                if (studentId[i] == tempsid) {
                    sindex = i;                                      //if match found then assign the index
                }
            }

            // if no match found then tell the user and break the switch statement
            if(sindex == -1) {
                printf("No matching Student ID");
                break;
            }

            // this method will display all the courses in which a student can be registered
            displayCourses(numCourses, courseId);
            
            //loop continue to run until a valid course ID is entered by the user
            do {
            
                printf("\nEnter course ID for course %d [3-Alphas][4-digits]: ", i);
                char regcourseBuffer[BUFFER_SIZE];                                    //to temporarily store user input
                int length = 0;                                                       //to store the length of user input
                
                scanf("%s", regcourseBuffer);                                         //takes user input
                length = strlen(regcourseBuffer);                                     //assigning the length of user input
                is_cid_correct = validateCourseId(regcourseBuffer);                   // validates user entered Course ID and stores the result in a boolean

                // if the id is not correct tell the user
                if (!is_cid_correct) {
                    printf("\nIncorrect Course Id input [3-Alphas][4-digits]");
                }
                else {
                    tempcid = malloc(sizeof(char) * length+1);                        //if the course ID is correct assign memory locaation to temporary variable
                    strcpy(tempcid, regcourseBuffer);                                 // copy the user entered string to tempcid
                }

            } while(!is_cid_correct);

            //loop to iterate over all course IDs to find a matching ID to user entered ID
            for(i=0; i<numCourses; i++) {
                if(strcmp(tempcid, courseId[i]) == 0) {               //comparing string to user input
                    cindex = i;                                       //assigning matching found index to cindex
                }
            }

            //if cindex is still -1 then tell the user
            if (cindex == -1) {
                printf("\nNo matching Course ID");
                break;
            }

            if (registerStudent(registration, &numRegistrations, sindex, cindex)) {            //register the student based on user inputs of student and course ID and returns true upon successful registeration
                registeredCourseIndex[numRegistrations - 1] = cindex;                          // stores cindex in the registred course index array in the order as registered in the registration table       
                registeredStudentIndex[numRegistrations - 1] = sindex;                         // stores sindex in the registred student index array in the order as registered in the registration table
                printf("\nRegistration Successful");
            }
            else {
                printf("\nRegistration Unsuccessful");      //if registration unsuccessful tell the user
            }
            break;
        
        case 2:
            ;bool is_index_correct = true;                 //boolean to store if the index value entered by user is correct or not

            //if there are no registrations to drop, tell the user
            if(numRegistrations == 0) {
                printf("\nNo student is registered in any course.");
                break;
            }

            //displays the registration table
            registrationTable(registration, numRegistrations, registeredStudentIndex, registeredCourseIndex, studentId, courseId);
            do
            {
            // prompt the user for the integer
            printf("\nSelect an index number to drop a student registration: ");
            
            // accept a line of string input from the user, store it into buffer
            char registerIndexBuffer[BUFFER_SIZE];
            scanf("%s", registerIndexBuffer);
            //fgets(buffer, BUFFER_SIZE, stdin);
            
            // validate the integer input, store the integer into registrationIndex if it was validated as correct
            is_index_correct = parse_int(registerIndexBuffer, &registrationIndex);
            
            // if the input was not a valid integer, tell the user this
            if (!is_index_correct) {
                printf("Must be a positive integer value.\n");
            }
            //if it is valid
            else { 
                if(registrationIndex < numRegistrations) {    //check if it is less than total number of registrations
                    is_index_correct = true;                  
                }
                else {
                    is_index_correct = false;
                    printf("\nSelect index between 0 and %d", (numRegistrations-1)); //if index entered is not in correct range tell the user
                }
            }
            } while (!is_index_correct);

            //drops student based on the index entered by the user. method returns true if drop is successful
            if(withdrawStudent(registration, registrationIndex, registeredStudentIndex, registeredCourseIndex)){
                printf("Drop course successful.");
            }
            //if drop unsuccessful tell the user
            else {
                printf("Drop course unsuccessful.");
            }
            break;

        case 3:
            // displas the registration table
            registrationTable(registration, numRegistrations, registeredStudentIndex, registeredCourseIndex, studentId, courseId);
            break;
        
        case 4:
            //prints exiting message before terminating the program
            printf("Exiting...\n");
            break;
        
        default:
            // if the option does not match any of case from 1 to 4
            printf("Select an option from 1-4.\n");
            break;
        }

    }

    //freeing all the allocated memory and assigning the respective pointers to null.
    free(studentId);
    studentId = NULL;
    free(registeredCourseIndex);
    registeredCourseIndex = NULL;
    free(registeredStudentIndex);
    registeredStudentIndex = NULL;

    for(i=0; i < numCourses; i++) {
        free(courseId[i]);
        courseId[i] = NULL;
    }
    free(courseId);
    courseId = NULL;

    for(i=0; i < numStudents; i++) {
        free(registration[i]);
        registration[i] = NULL;
    }
    free(registration);
    registration = NULL; 

    return EXIT_SUCCESS;  //returning exit success
}