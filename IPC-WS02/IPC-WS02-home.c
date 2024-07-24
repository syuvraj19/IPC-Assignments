/*--------------------SENECA COLLEGE-----------------------------
Student       : Yuvraj Singh
Student ID    : 155580210
Student Email : yuvraj-singh5@myseneca.ca
Class         : IPC-144 - Introduction to Programming using C
Description   : Workshop 02 - Expressions
---------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	// Constant Definition
	const double QUARTER = 0.25;

	// Variable Definition
	double	amountDue = 0;
	int		looniesRequired	 = 0,
			quartersRequired = 0;

	// Input
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountDue);

	// Calculation (Loonies)
	looniesRequired = (int)amountDue; // cast to integer to truncate the value

	amountDue -= looniesRequired;

	// Output (Loonies)
	printf("Loonies required: %d, balance owing $%.2lf\n", looniesRequired, amountDue);

	// Calculation (Quarters)
	// for each step, increment the variable that sums the number of quarters
	for (quartersRequired = 0; amountDue >= QUARTER; quartersRequired++)
	{
		amountDue -= QUARTER;
	}

	// Output (Quarters)
	printf("Quarters required: %d, balance owing $%.2lf\n", quartersRequired, amountDue);

	return 0;
}
