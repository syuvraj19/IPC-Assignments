/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : IPC-144-ZEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
// Copy your work done from Milestone #1 (core.h) into this file
//
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
#ifndef CORE_H_
#define CORE_H_


// -----------------------------------------
// Function Prototypes


// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for the user to input the "enter" key to continue
void suspend(void);
// Get a valid integer from keyboard
int inputInt(void);
// Get a valid integer from keyboard and validate if greater than 0
int inputIntPositive(void);
// Get a valid integer from keyboard and validate if within a range of values
int inputIntRange(int lower_limit, int upper_limit);
// Get a single character from keyboard and validate if it matches any character in a given string
char inputCharOption(const char *charx);
// Get a C string from keyboard and validate if its length is within a given range
void inputCString(char *charx, int lowerbound, int upperbound);
// Display an array of 10 character digits as a formatted phone number
void displayFormattedPhone(const char *cell);
#endif /* CORE_H_ */
