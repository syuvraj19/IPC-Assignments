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
#include <stdio.h>
#include <string.h>
#include "core.h"


void clearInputBuffer(void)
{
   while (getchar() != '\n')
   {
       ;
   }
}

void suspend(void)
{
   printf("<ENTER> to continue...");
    
   clearInputBuffer();
   putchar('\n');
}

int inputInt(void)
{
   char afterline = 'x';
   int  val;
   do
   {
       scanf("%d%c", &val, &afterline);
       if (afterline == '\n')
       {
           break;
       }
       else
       {
           clearInputBuffer();
           printf("Error! Input a whole number: ");
       }
   }while(afterline != '\n');
   return val;
}

int inputIntPositive(void)
{
   int value = inputInt();
    
   while (value <= 0)
   {
       printf("Error! Value must be > 0: ");
       value = inputInt();
   }
   return value;
}


int inputIntRange(int lower_limit, int upper_limit)
{
   int value = inputInt();
   while (value < lower_limit || value > upper_limit)
   {
       printf("Error! Value must be between %d and %d inclusive: ", lower_limit, upper_limit);
       value = inputInt();
   }
   return value;
}


char inputCharOption(const char *charx)
{
    int  stringlen = strlen(charx), x;
   char xyz;
   while (1)
   {
       scanf(" %c", &xyz);
       
       clearInputBuffer();
       int a = 0;
       
       for (x=0; x<stringlen; x++)
       {
           if (xyz == charx[x])
           {
               a = 1;
               break;
           }
       }
       if (a == 1)
       {
           break;
       }
       else
       {
           printf("Error! Character must me one of [%s]: ", charx);
       }

   }
   return xyz;
}


void inputCString(char *charx, int lowerbound, int upperbound)
{
   char str[100];
   while (1)
   {
       scanf(" %[^\n]%*c", str);
       if (lowerbound == upperbound)
       {
           if (strlen(str) != lowerbound)
           {
               printf("Error! String length must be exactly %d chars: ", lowerbound);
           }
           else
           {
               break;
           }
       }
       else
       {
           if (strlen(str) < lowerbound)
           {
               printf("Error! String length must be between %d and %d chars: ",lowerbound, upperbound);
           }
           else if(strlen(str) > upperbound)
           {
               printf("Error! String length must be no more than %d chars: ", upperbound);
           }
           else
           {
               break;
           }
       }
   }
   strcpy(charx, str);
}


void displayFormattedPhone(const char *cell)
{
   if (cell == NULL)
   {
       printf("(___)___-____");
       return;
   }
   int x = 0,count = 0,len = strlen(cell);
   while(x<len)
   {
       if(cell[x] >= '0' && cell[x] <= '9')
       {
           count++;
       }x++;
   }
   if (len != 10 || len != count)
   {
       printf("(___)___-____");
   }
   else
   {
       printf("(%c%c%c)%c%c%c-%c%c%c%c",
              cell[0],cell[1],cell[2],cell[3],cell[4],
              cell[5],cell[6],cell[7],cell[8],cell[9]);
   }
}
