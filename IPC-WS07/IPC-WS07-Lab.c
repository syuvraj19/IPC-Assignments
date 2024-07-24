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

// decompose function prototype
void decompose(const long long, int*, int*, int*);

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

/* main program */
int main(void) {

	// Variable Definition
	int option,
		AAA = 0, // area code
		PPP = 0, // prefix
		LLLL = 0, // line number
		numberOfPhones = 0,
		i = 0;

	long long phoneNumber[SIZE] = { 0LL }; // Phone Number

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
				scanf("%lld", &phoneNumber[numberOfPhones]);
				numberOfPhones++;
			}

			printf("\n");

			break;

		default:
			break;
						
		}

	} while (option != 0);

	return 0;
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
