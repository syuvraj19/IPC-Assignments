/*--------------------SENECA COLLEGE-----------------------------
Student       : Yuvraj Singh
Student ID    : 155580210
Student Email : yuvraj-singh5@myseneca.ca
Class         : IPC-144 - Introduction to Programming using C
Description   : Workshop 04 - Arrays
---------------------------------------------------------------*/

#include <stdio.h>
#define ARRAY_SIZE 10 // maximum elements for the array

int main(void)
{
	// Variable Declaration
	int numberOfDays = 0, i = 0, daysForMeanCalculation = 0, meanDenominator = 0, loopControl = 0;
	double	highTemperature[ARRAY_SIZE],
			lowTemperature[ARRAY_SIZE],
			meanResult = 0;

	// Title of the application
	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &numberOfDays);

	// Manages user input (number of days)
	while (numberOfDays < 3 || numberOfDays > 10)
	{
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &numberOfDays);
	}

	// For Loop
	for (i = 0; i < numberOfDays; i++)
	{
		// store values for the high temperature
		printf("Day %d - High: ", i + 1);
		scanf("%lf", &highTemperature[i]);

		// store values for the low temperature
		printf("Day %d - Low: ", i + 1);
		scanf("%lf", &lowTemperature[i]);

		// Manages user input (temperature)
		while (highTemperature[i] < -41 || highTemperature[i] > 41 || lowTemperature[i] < -41 || lowTemperature[i] > 41 || highTemperature[i] < lowTemperature[i])
		{
			// error message
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");

			// store values for the high temperature
			printf("Day %d - High: ", i + 1);
			scanf("%lf", &highTemperature[i]);

			// store values for the low temperature
			printf("Day %d - Low: ", i + 1);
			scanf("%lf", &lowTemperature[i]);
		}
	}

	// Output (1st part)
	printf("\nDay  Hi  Low\n\n");

	for (i = 0; i < numberOfDays; i++)
	{
		printf("%d    %.0lf    %.0lf\n", i + 1, highTemperature[i], lowTemperature[i]);
	}

	// At Home upgrade
	while (loopControl >= 0)
	{
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", numberOfDays);
		scanf("%d", &daysForMeanCalculation);

		// Manages user input
		while (daysForMeanCalculation == 0 || daysForMeanCalculation > numberOfDays)
		{
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", numberOfDays);
			scanf("%d", &daysForMeanCalculation);
		}

		if (daysForMeanCalculation < 0) 
		{
			loopControl = -1;
		}
		else
		{
			for (i = 0; i < daysForMeanCalculation; i++)
			{
				meanResult += highTemperature[i] + lowTemperature[i];
				meanDenominator += 2;
			}

			meanResult /= meanDenominator;
			printf("\nThe average temperature up to day %d is: %.2lf\n", daysForMeanCalculation, meanResult);
			meanResult = 0;
			meanDenominator = 0;
		}	
	}

	printf("\nGoodbye!\n");


	return 0;
}




