/* -------------------------------------------
Name:            Yuvraj Singh
Student number:  155580210
Email:           yuvraj-singh5@myseneca.ca
Assignment-2-Milestone-2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 1 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition
void clearKeyboard(void)
{
  {
    while (getchar() != '\n')
      ; // empty execution code block on purpose
  }
}

// pause: Empty function definition goes here:
void pause(void)
{
  printf("(Press Enter to Continue)");
  clearKeyboard();
}

// getInt: Empty function definition goes here:
int getInt(void)
{
  int validInt;
  char invalidChar = 'x'; // Declaration to enter the condition of while loop

  while (invalidChar != '\n')
  {
    scanf("%d%c", &validInt, &invalidChar); // Receive only the integer value from the user
    if (invalidChar != '\n')                // Check the second character is a new line or not
    {
      clearKeyboard();
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");
    }
  }
  return validInt;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
  int validRange = getInt();

  while (validRange < min || validRange > max)
  {
    printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
    validRange = getInt();
  }
  return validRange;
}

// yes: Empty function definition goes here:
int yes(void)
{
  int validYes = 0; // 0 means "NO"
  char validChar, newlineChar;

  do
  {
    scanf("%c%c", &validChar, &newlineChar);
    // if statement assess only if the first value is one of the 4 valid characters.
    if (newlineChar != '\n' || (validChar != 'Y' && validChar != 'y' && validChar != 'N' && validChar != 'n'))
    {
      if (newlineChar != '\n') // Set up to erase the new line in the second value
      {
        clearKeyboard();
      }

      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
    }
    else if (validChar == 'Y' || validChar == 'y')
    {
      validYes = 1; // 1 menas "YES"
    }
  } while (newlineChar != '\n' || (validChar != 'Y' && validChar != 'y' && validChar != 'N' && validChar != 'n'));

  return validYes;
}

// menu: Empty function definition goes here:
int menu(void)
{
  puts("Contact Management System");
  puts("-------------------------");
  puts("1. Display contacts");
  puts("2. Add a contact");
  puts("3. Update a contact");
  puts("4. Delete a contact");
  puts("5. Search contacts by cell phone number");
  puts("6. Sort contacts by cell phone number");
  puts("0. Exit");
  puts("");
  printf("Select an option:> ");
  return getIntInRange(0, 6);
}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
  // int getMenu, valid = 0;  // Feedback -> To make more simply. do not need to declear variable
  int valid = 0; // Feedback -> To make more simply. do not need to declear variable

  do
  {
    // getMenu = menu();  // Feedback -> To make more simply. do not need to declear variable

    // switch (getMenu)   // Feedback -> To make more simply. do not need to declear variable
    switch (menu()) // Feedback -> To make more simply. do not need to declear variable
    {
    case 0:
      puts("");
      printf("Exit the program? (Y)es/(N)o: ");
      valid = yes();
      puts("");
      break;

    case 1:
      puts("");
      puts("<<< Feature 1 is unavailable >>>\n");
      pause();
      puts("");
      break;

    case 2:
      puts("");
      puts("<<< Feature 2 is unavailable >>>\n");
      pause();
      puts("");
      break;

    case 3:
      puts("");
      puts("<<< Feature 3 is unavailable >>>\n");
      pause();
      puts("");
      break;

    case 4:
      puts("");
      puts("<<< Feature 4 is unavailable >>>\n");
      pause();
      puts("");
      break;

    case 5:
      puts("");
      puts("<<< Feature 5 is unavailable >>>\n");
      pause();
      puts("");
      break;

    case 6:
      puts("");
      puts("<<< Feature 6 is unavailable >>>\n");
      pause();
      puts("");
      break;

    default:
      break;
    }
  } while (valid != 1);

  puts("Contact Management System: terminated");
}

//--------------------------------
// Personal Function
// Creat to check valid and positive integer at one time
//--------------------------------

int streetNumber(void)
{
  int validInt = getInt();

  while (validInt < 0) // Verify that the integer value entered is positive
  {
    printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
    validInt = getInt();
  }

  return validInt;
}

int apartmentNumber(void)
{
  int validInt = getInt();

  while (validInt < 0) // Verify that the integer value entered is positive
  {
    printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
    validInt = getInt();
  }

  return validInt;
}

// Feedback ->  If you added another argument to the a single function,
//              you could reduce this to 1 function where the argument would be the “error” message:
int getPositiveInt(const char *errrMsg)
{
  int validInt = getInt();

  while (validInt < 0) // Verify that the integer value entered is positive
  {
    printf(errrMsg);
    validInt = getInt();
  }

  return validInt;
}
