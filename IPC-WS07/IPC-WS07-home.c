/*--------------------SENECA COLLEGE-----------------------------
Student       : Yuvraj Singh
Student ID    : 155580210
Student Email : yuvraj-singh5@myseneca.ca
Class         : IPC-144 - Introduction to Programming using C
Description   : Workshop 07 - Functions with Pointers
---------------------------------------------------------------*/

#include <stdio.h>

// Maximum phone number
#define SIZE 3

// boolean definition
#define TRUE 0
#define FALSE 1

// decompose function prototype
void decompose(const long long, int*, int*, int*);

// isValid function prototype
int isValid(const long long);

/* main program */
int main(void) {

	// Variable Definition
	int option,
		AAA = 0, // area code
		PPP = 0, // prefix
		LLLL = 0, // line number
		numberOfPhones = 0,
		i = 0,
		phoneValidation = 0;

	long long phoneNumber[SIZE] = { 0LL }, // Phone Number
			  tempPhoneNumber = 0; // temporary variable to store the phone

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:

			// Exit the program
			printf("Exiting Phone Number App. Good Bye!!!\n");
			break;

		case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");

			// Display each number in decomposed form
			for (i = 0; i < SIZE; i++)
			{
				if (phoneNumber[i] != 0)
				{
					decompose(phoneNumber[i], &AAA, &PPP, &LLLL);
					printf("(%3d)-%3d-%4d\n", AAA, PPP, LLLL);
				}
			}

			printf("\n");

			break;

		case 2:	// Add a Phone Number
				// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");

			if (numberOfPhones >= SIZE)
				printf("ERROR!!! Phone Number List is Full\n");
			else
			{
				// store the phone in a temporary variable
				scanf("%lld", &tempPhoneNumber);
				
				// Validate the phone number and store the result
				phoneValidation = isValid(tempPhoneNumber);

				// if the phone is valid, store the phone number
				if (phoneValidation == TRUE)
				{
					phoneNumber[numberOfPhones] = tempPhoneNumber;
					tempPhoneNumber = 0;
					numberOfPhones++;
				}
				else
					printf("ERROR!!! Phone Number is not Valid\n");
			}

			printf("\n");

			break;

		default:
			printf("ERROR!!!: Incorrect Option: Try Again\n\n");
			break;

		}

	} while (option != 0);

	return 0;
}

// decompose function definition
void decompose(const long long phoneNumber, int *phoneAAA, int *phonePPP, int *phoneLLLL)
{
	// Area Code
	*phoneAAA = (int)(phoneNumber / 10000000);

	// Prefix
	*phonePPP = (int)(phoneNumber - (*phoneAAA * 10000000)) / 10000;

	// Line Number
	*phoneLLLL = (int)(phoneNumber - (*phoneAAA * 10000000) - (*phonePPP * 10000));

}

// isValid function definition
int isValid(const long long phoneNumber)
{
	int areaCodes[] = { 416, 647, 905 }, // GTA area codes
		prefixLow = 100, // Lowest possible phone prefix
		prefixHigh = 999, // Highest possible phone prefix
		phoneAAA = 0, // area code
		phonePPP = 0, // prefix
		result = FALSE,
		i = 0;

	// fill the area code and prefix based on the phone number given
	phoneAAA = (int)(phoneNumber / 10000000);
	phonePPP = (int)(phoneNumber - (phoneAAA * 10000000)) / 10000;

	for (i = 0; i < SIZE; i++)
	{
		if (areaCodes[i] == phoneAAA && phonePPP >= prefixLow && phonePPP <= prefixHigh)
		{
			result = TRUE;
		}

	}

	return result;
}

// Program Input/Output
/*

---=== Phone Numbers ===---

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 1

Phone Numbers
==============

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
4164915050

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
9052301212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
6475551212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 1

Phone Numbers
==============
(416)-491-5050
(905)-230-1212
(647)-555-1212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
ERROR!!! Phone Number List is Full

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 0

Exiting Phone Number App. Good Bye!!!

*/
