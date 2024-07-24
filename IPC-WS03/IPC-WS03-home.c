/*--------------------SENECA COLLEGE-----------------------------
Student       : Yuvraj Singh
Student ID    : 155580210
Student Email : yuvraj-singh5@myseneca.ca
Class         : IPC-144 - Introduction to Programming using C
Description   : Workshop 03 - Logic
---------------------------------------------------------------*/

#include <stdio.h>

#define NUMS 4

int main(void)
{
	// Variable Declaration
	double	highTemperature = 0,
		lowTemperature = 0,
		totalHighTemperature = 0,
		totalLowTemperature = 0,
		averageTemperature = 0,
		highestTemperature = 0,
		lowestTemperature = 0;
	int i = 0, meanCounter = 0, // the meanCounter is used as denominator
		highestTempDay = 0,
		lowestTempDay = 0;

	// Header
	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++)
	{
		// Input
		printf("Enter the high value for day %d: ", i + 1);
		scanf("%lf", &highTemperature);
		printf("\n");

		printf("Enter the low value for day %d: ", i + 1);
		scanf("%lf", &lowTemperature);
		printf("\n");

		while (highTemperature < -40 || highTemperature > 40 || lowTemperature < -40 || lowTemperature > 40 || highTemperature < lowTemperature)
		{
			// error message
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");

			// enter values again
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%lf", &highTemperature);
			printf("\n");

			printf("Enter the low value for day %d: ", i + 1);
			scanf("%lf", &lowTemperature);
			printf("\n");
		}

		// Initialize Highest Temperature
		if (highestTemperature == 0)
			highestTemperature = highTemperature;

		// Initialize Lowest Temperature
		if (lowestTemperature == 0)
			lowestTemperature = lowTemperature;

		// Check Highest Temperature
		if (highTemperature >= highestTemperature)
		{
			highestTemperature = highTemperature;
			highestTempDay = i + 1;
		}

		// Check Lowest Temperature
		if (lowTemperature <= lowestTemperature)
		{
			lowestTemperature = lowTemperature;
			lowestTempDay = i + 1;
		}

		// total High Temperature
		totalHighTemperature += highTemperature;
		highTemperature = 0;
		meanCounter += 1;

		// total Low Temperature
		totalLowTemperature += lowTemperature;
		lowTemperature = 0;
		meanCounter += 1;

	}

	// average Temperature
	averageTemperature = (totalHighTemperature + totalLowTemperature) / meanCounter;

	// Output
	printf("The average (mean) temperature was: %.2lf\n", averageTemperature);
	printf("The highest temperature was %.lf, on day %d\n", highestTemperature, highestTempDay);
	printf("The lowest temperature was %.lf, on day %d\n", lowestTemperature, lowestTempDay);

	return 0;
}
