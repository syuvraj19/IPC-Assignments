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

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "core.h"

// As demonstrated in the course notes:
// https://protect-us.mimecast.com/s/sfKvCAD7KyCvMVNNIG-5O3?domain=intro2c.sdds.ca
// Clear the standard input buffer
void clearInputBuffer(void)
{
// Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend (void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void)
{
    int amt=0;
    char new_line = 'x';

    do
    {
        scanf("%d%c", &amt, &new_line);
        if(new_line != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }while(new_line != '\n');
    return amt;
}

int inputIntPositive(void)
{
    int plusval = 0;
    while(1)
    {
        plusval = inputInt();
        if(plusval < 1)
        {
            printf("ERROR! Value must be > 0: ");
        }
        else
        {
            break;
        }
    }
    return plusval;
}

int inputIntRange(int lower_bound, int upper_bound)
{
    
    int sec = 0;
    while(1)
    {
        sec = inputInt();

        if (sec < lower_bound || sec > upper_bound)
        {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
        else
        {
            break;
        }
    }
    return sec;
}

char inputCharOption(const char range[])
{
    
    int i = 0, dunk = 1, bro = 0, x = 1;

    for(i = 0; range[i] != '\0'; i++)
    {
        bro++;
    }
    char one = 0;
    while (x < 5)
    {
        scanf("%c", &one);
        clearInputBuffer();
        
            while( i < dunk && bro)
            {
                if (one == range[i])
                {
                    break;
                }i++;
            }
            if(x !=4)
            {
                printf("ERROR: Character must be one of [qwErty]: ");
            }x++;
    }
    return one;
}

void inputCString(char charx[], int min_char, int max_char)
{
    char word[500];
    int i = 0, j = 0, k = 0;

    while(1)
    {
        scanf("%[^\n]", word);
        clearInputBuffer();

        for(i = 0; word[i] != '\0'; ++i)
        {
            k++;
        }
        if (( i < min_char || i > max_char) && (min_char == max_char))
        {
            printf("ERROR: String length must be exactly 6 chars: ");
        }
        else if ( i > max_char && (min_char != max_char))
        {
            printf("ERROR: String length must be no more than 6 chars: ");
        }
        else if ( i < min_char && (min_char != max_char))
        {
            printf("ERROR: String length must be between 5 and 6 chars: ");
        }
        else
        {
            for(j = 0; j < i + 1; j++)
            {
                charx[j] = word[j];
            }
            break;
        }
    }
}

void displayFormattedPhone(const char* cell)
{
    int x,y,a=0,s=0;
    char num[]="0123456789";
    
    if (cell == NULL)
    {a = 1;}
    
    else if (cell != NULL)
    {
        x=0;
        while(cell[x] !='\0')
        {x++;}
        if(x!=10)
        {a = 1;}
    }
    
    if (a!=1)
    {
        y=0;
        while (y<10 && !a)
        {
            s = 0;
            x=0;
            while(x<10 && !s)
            {
                if(num[x]==cell[y])
                {
                    s = 1;
                }
                x++;
            }
            if(!s)
            {
                a = 1;
            }y++;
        }
    }
    
    if (a==1)
    {
        printf("(___)___-____");
    }
    
    else
    {
        printf("(%.3s)",cell);
        for (x=3;x<6;x++)
        {
            printf("%c",cell[x]);
        }
        printf("-");
        for(x=6;x<10;x++)
        {
            printf("%c",cell[x]);
        }
    }
}
