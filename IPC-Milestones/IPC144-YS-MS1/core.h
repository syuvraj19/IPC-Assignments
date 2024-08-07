/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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

#include <stdio.h>
//clear the standard input buffer
void clearInputBuffer(void);

//wait for user to input the "enter" key to continue
void suspend(void);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int lower_bound, int upper_bound);

char inputCharOption(const char range[]);

void inputCString(char charpointer[], int min_char, int max_char);

void displayFormattedPhone(const char* cell);
