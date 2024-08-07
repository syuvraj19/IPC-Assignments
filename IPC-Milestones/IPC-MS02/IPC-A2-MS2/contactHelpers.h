/* -------------------------------------------
Name:            Yuvraj Singh
Student number:  155580210
Email:           yuvraj-singh5@myseneca.ca
Assignment-2-Milestone-2
---------------------------------------------- */

/*--------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks.
---------------------------------------------------------------------*/

// HINT:
// You will most likely want to include this header file
// in other files of the project since it provides general
// helper functions that can be used throughout.

//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);

// getInt:
// Put function prototype below:
int getInt(void);

// getIntInRange:
// Put function prototype below:
int getIntInRange(int min, int max);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);

//--------------------------------
// Personal Function
// Creat to check valid and positive integer at one time
//--------------------------------

// streetNumber:
// Put function prototype below:
int streetNumber(void);

// apartNumber:
// Put function prototype below:
int apartmentNumber(void);

// Feedback ->  If you added another argument to the a single function,
//              you could reduce this to 1 function where the argument would be the “error” message:
// Put function prototype below:
int getPositiveInt(const char *errrMsg);
