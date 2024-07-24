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
	int numberOfDays = 0, i = 0;
	double	highTemperature[ARRAY_SIZE],
			lowTemperature[ARRAY_SIZE];

	// Title of the application
	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &numberOfDays);

	// Manages user input (number of days)
	while (numberOfDays < 3 || numberOfDays > 10)
	{
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &numberOfDays);
		printf("\n");
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
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
			
			// store values for the high temperature
			printf("Day %d - High: ", i + 1);
			scanf("%lf", &highTemperature[i]);

			// store values for the low temperature
			printf("Day %d - Low: ", i + 1);
			scanf("%lf", &lowTemperature[i]);
		}
	}

	// Output
	printf("\nDay  Hi  Low\n");

	for (i = 0; i < numberOfDays; i++)
	{
		printf("%d    %.0lf    %.0lf\n", i + 1, highTemperature[i], lowTemperature[i]);
	}

	return 0;
}


