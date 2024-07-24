/*--------------------SENECA COLLEGE-----------------------------
Student       : Yuvraj Singh
Student ID    : 155580210
Student Email : yuvraj-singh5@myseneca.ca
Class         : IPC-144 - Introduction to Programming using C
Description   : Workshop 06 - Functions
---------------------------------------------------------------*/

/*
== Vehicle Rentals ==

Author	: Gayan Gamage
Date	: 14-02-2017
Revision: 1.0
Workshop: #6 in-Lab

*/

#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 

// Structure Declaration for Vehicle Rentals
struct Rental
{
   int id;						// ID of the Rental Vehicle
   double baseDay;				// Daily Base Price 
   double earnings;			// Total earnings from this rental
};

/* prototype functions addPositive Here*/
double addPositive(double, double);

/* Implement Function addPositive Here*/
double addPositive(double amount, double newAmount)
{
	double result = 0;

	if (newAmount > 0)
		result = amount + newAmount;
	else
		result = amount;

	return result;
}

/* main program */
int main()
{
   const int noVehicles = 2;			// Number of Vehicles
   int option;							// Variable to store the option selected
   int flag;							// Flag to support vehicle ID find
   int tempID;							// To hold user input for vehicle ID
   int i = 0;							// Variable for "for-loop" counters

   // Initialize the struct Vehicle Rental
   struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 } };

   /*Declare Your Variables Here*/
   int rentalDays = 0;
   double	basePrice = 0,
			traveledDistance = 0,
			kmCost = 0,
			charge = 0;

   printf("***** Rental Vehicle Management App *****\n\n");

   do
   {
      // Display the option list
      printf("1.) Rental Status\n");
      printf("2.) Apply Charges\n");
      printf("0.) Log out\n\n");
      printf("Please enter an option to continue: ");

      scanf("%d", &option);

      switch (option)
      {
      case 0: // Exit the program
         break;

      case 1: // Rental Vehicle Status

         printf("\n-- Rental Vehicle Status --\n\n");
         printf("ID#      Earnings\n");
         printf("-------- ----------\n");

         // Use "%8d %10.2lf" formatting to display ID and Earnings for each rental
         // using a loop construct
		 for (i = 0; i < noVehicles; i++)
		 {
			 printf("%8d %10.2lf\n", vRent[i].id, vRent[i].earnings);
		 }

		 printf("\n");

         break;

      case 2: // Calculate Rental Charges

         flag = -1;
         printf("\n-- Rental Charges --\n\n");
         printf("Enter vehicle ID: ");
         scanf("%d", &tempID);

         // Finding the correct vehicle index
         for (i = 0; i < noVehicles && flag == -1; i++) {
            if (tempID == vRent[i].id) {
               flag = i;
            }
         }

         if (flag != -1) {

			 // Capture #days for the rental from user input
			 printf("Enter Rental Period (in Days): ");
			 scanf("%d", &rentalDays);

			 // Calculate the base price (baseDay * Days)
			 basePrice = vRent[flag].baseDay * rentalDays;

             // Calculate cost for Kilometers driven using "distRate1 & 2 above"
			 printf("Enter kilometers driven: ");
			 scanf("%lf", &traveledDistance);

			 // Calculate km cost
			 if (traveledDistance <= 100)
				 kmCost = traveledDistance * distRate1;
			 else
			 {
				 traveledDistance -= 100;
				 kmCost = (100 * distRate1) + (traveledDistance * distRate2);
			 }
				 

             // Add base Price and cost for kilometer driven in to a new variable 
             // "charge"
			 charge = kmCost + basePrice;

             /* Call addPositive function with current earnings for the rental and
               charge(calculated above) as arguments and assign the returned
               result back to earnings
             */
			 vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);


            // Display Base Charge, cost for km and the Total 
            printf("\nBase   kmCost Total\n");
            printf("====== ====== ======\n");
            // Use "%6.2lf %6.2lf %6.2lf" formatting inside a printf statement
			printf("%6.2lf %6.2lf %6.2lf\n\n", basePrice, kmCost, vRent[flag].earnings);

         }
         else {
            printf("ERROR: Vehicle ID does not exist.\n\n");
         }

         break;


      default:
         printf("Error: Please enter a valid option to continue\n\n");
         break;
      }


   } while (option != 0);


   return 0;
}

/* SAMPLE INPUT/OUTPUT EXPECTED */

/*

***** Rental Vehicle Management App *****

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 123
Enter Rental Period (in Days): 2
Enter kilometers driven: 125

Base   kmCost Total
====== ====== ======
 19.90  81.25 101.15

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 124
Enter Rental Period (in Days): 3
Enter kilometers driven: 79

Base   kmCost Total
====== ====== ======
 59.85  54.51 114.36

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 125
ERROR: Vehicle ID does not exist.

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 1

-- Rental Vehicle Status --

ID#      Earnings
-------- ----------
     123     101.15
     124     114.36

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 0

*/
