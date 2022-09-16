/********************************************************
* Title: Lab Assessment #3 - Student Registration System 
* Course: CST8234 C Language
* File: input.c
* @Author: Suraj Mittal (041027220)
* Lab Section: 012
* Professor: Surbhi Bahri
* Due date: 03/07/2022
* Submission date: 03/07/2022 
*********************************************************/

//including all the required libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096  /*Defining the size of all the buffer memories used throughout the program*/

//defining variables
int status;               // used in validateIntegerInput function
char temp;                // used in validateIntegerInput function 

/****************************************************************************
Function Name: parse_int
Purpose: validates if the provided number integer or not
Function in parameters: pointer to string to conver to int, and pointer to int to store the coverted integer
Function out parameter: boolean, true on success else false
Version: 1
Author: Suraj Mittal
*****************************************************************************/
bool parse_int(char *string, int *integer) {
    
  // i will keep our current index into the string as we loop through it one character at a time
  int i = 0;
  
  // move through any leading whitespace
  while (isspace(string[i])) i++;
  
  // get the length of the string
  int length = strlen(string);
  
  // if the entire string was just whitespace characters ("a blank string") we'll have reached the end of the string and we can return false as the string did not contain an integer
  if (length == i) return false;
  
  /* the integer chars will be stored into integer_buffer, we'll use 
  * integer_chars to keep track of our index into this buffer as we store 
   each character*/
  char integer_buffer[BUFFER_SIZE];
  int integer_chars = 0;
  
  //if we encounter negative sign this means the inout is a negative number so we will return false 
  if(string[i] == '-') {
      while(getchar() != '\n');
      return false;
  }
  
  // loop through characters until we reach the end of the string or a trailing
  // whitespace character
  while (i < length && !isspace(string[i]))
  {
    // if we encounter anything that is not a digit, we do not have a valid int 
    // in the string
    if (!isdigit(string[i])) return false;
    
    // store the next character into the buffer, advance both indexes
    integer_buffer[integer_chars] = string[i];
    integer_chars++;
    i++;
  }
  
  // put a null terminator onto the end of the buffer to make it a proper string
  integer_buffer[integer_chars] = '\0';
  
  // loop through any trailing whitespace characters
  while (isspace(string[i])) i++;
  
  // if after doing so, we are NOT at the end of the string, then the string 
  // does not contain a valid integer
  if (string[i] != '\0') return false;
  
  // atoi converts the string representation of our integer to an int type 
  // value in C, and we de-reference integer to "return" the value via a pointer
  *integer = atoi(integer_buffer);
  
  // we've successfully validated the presence of an int and so can return true
  return true;
}

/****************************************************************************
Function Name: validateIntegerInput
Purpose: validates if the provided number integer or not
Function in parameters: pointer to number to validate
Function out parameter: void
Version: 1
Author: Suraj Mittal
*****************************************************************************/
void validateIntegerInput(int *number) {
    status = scanf("%d", number);            //if scanf fails status will be 0
    while(status!=1){                        
        while((temp=getchar()) != EOF && temp != '\n');             //on unsuccessful scanf statement clear the input stream until a newline character is found
        printf("Invalid input... please enter a number: ");
        status = scanf("%d", number);                               //takes input again
    }
}

/****************************************************************************
Function Name: validateStudentId
Purpose: validates if the provided student id is 5 digits only or not
Function in parameters: pointer to student id to validate
Function out parameter: boolean, true if validated correct else false
Version: 1
Author: Suraj Mittal
*****************************************************************************/
bool validateStudentId(int* studentId) {

    if(*studentId < 100000 && *studentId > 9999) {             //checks the range of argument
        return true;                                           //if true return true
    }
    //else
    else {
        return false;
    }
}

/****************************************************************************
Function Name: validateCourseId
Purpose: validates if the provided course id is 3 alpha characters and 4 digits not
Function in parameters: pointer to courseId id to validate
Function out parameter: boolean, true if validated correct else false
Version: 1
Author: Suraj Mittal
*****************************************************************************/
bool validateCourseId(char* buffer) {

    if (strlen(buffer) != 7) return false;              //if length is equal to 7 return false
    if (!isalpha(buffer[0])) return false;              //if first character is not alpha return false
    if (!isalpha(buffer[1])) return false;              //if second character is not alpha return false
    if (!isalpha(buffer[2])) return false;              //if third character is not alpha return false
    if (!isdigit(buffer[3])) return false;              //if fourth character is not digit return false
    if (!isdigit(buffer[4])) return false;              //if fifth character is not digit return false
    if (!isdigit(buffer[5])) return false;              //if sixth character is not digit return false
    if (!isdigit(buffer[6])) return false;              //if seventh character is not digit return false

    //else
    return true;
}