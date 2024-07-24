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
	const double	QUARTER = 0.25,
					DIMME	= 0.10,
					NICKEL	= 0.05,
					PENNY	= 0.01,
					GST		= 0.13,
					ROUND	= 0.005;
	

	// Variable Definition
	double	amountDue = 0,
			amountGST = 0;

	int	looniesRequired		= 0,
		quartersRequired	= 0,
		dimmesRequired		= 0,
		nickelsRequired		= 0,
		penniesRequired		= 0;
		

	// Input
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountDue);

	// Calculate GST
	amountGST = amountDue * GST;
	amountDue += amountGST;
	// Round
	amountDue += ROUND;

	// Output after GST
	printf("GST: %.2lf\n", amountGST);
	printf("Balance owing: $%.2lf\n", amountDue);

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

	// Calculation (Dimmes)
	for (dimmesRequired = 0; amountDue >= DIMME; dimmesRequired++)
	{
		amountDue -= DIMME;
	}

	// Output (Dimmes)
	printf("Dimes required: %d, balance owing $%.2lf\n", dimmesRequired, amountDue);

	// Calculation (Nickels)
	for (nickelsRequired = 0; amountDue >= NICKEL; nickelsRequired++)
	{
		amountDue -= NICKEL;
	}

	// Output (Nickels)
	printf("Nickels required: %d, balance owing $%.2lf\n", nickelsRequired, amountDue);

	// Calculation (Pennies)
	for (penniesRequired = 0; amountDue >= ROUND; penniesRequired++)
	{
		amountDue -= PENNY;
	}

	// Correct the amount due rounding issue
	if (amountDue < 0)
		amountDue = 0;

	// Output (Pennies)
	printf("Pennies required: %d, balance owing $%.2lf\n", penniesRequired, amountDue);

	return 0;
}
