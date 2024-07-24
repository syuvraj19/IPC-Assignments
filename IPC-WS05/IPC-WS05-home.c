/*--------------------SENECA COLLEGE-----------------------------
Student       : Yuvraj Singh
Student ID    : 155580210
Student Email : yuvraj-singh5@myseneca.ca
Class         : IPC-144 - Introduction to Programming using C
Description   : Workshop 05 - Structures
---------------------------------------------------------------*/

// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements

#include <stdio.h>

// Define Number of Employees "SIZE" to be 4
#define SIZE 4

// Declare Struct Employee 
struct Employee
{
	int employeeID,
		employeeAge;
	double employeeSalary;
};


/* main program */
int main(void) {

	int option = 0,
		i = 0,
		numberOfEmployees = 0,
		searchEmployeeID = 0,
		arraySearchControl = -1;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee emp[SIZE] = { { 0 } };

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program

			break;
		case 1: // Display Employee Data
				// @IN-LAB

			if (numberOfEmployees > 0) // check if there's any Employee in the array
			{

				printf("EMP ID  EMP AGE EMP SALARY\n");
				printf("======  ======= ==========\n");

				// Use "%6d%9d%11.2lf" formatting in a   
				// printf statement to display
				// employee id, age and salary of 
				// all  employees using a loop construct 
				for (i = 0; i < SIZE; i++)
				{
					// The loop construct will be run for SIZE times 
					// and will only display Employee data 
					// where the EmployeeID is > 0
					if (emp[i].employeeID > 0)
					{
						printf("%6d%9d%11.2lf\n", emp[i].employeeID, emp[i].employeeAge, emp[i].employeeSalary);
					}
				}
				printf("\n");
			}
			else // if not, print error message
				printf("Sorry! No Employees to be displayed. Please select another option.\n\n");

			break;
		case 2:	// Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			// data accordingly. 
			if (numberOfEmployees < SIZE)
			{
				printf("Enter Employee ID: ");
				scanf("%d", &emp[numberOfEmployees].employeeID);

				printf("Enter Employee Age: ");
				scanf("%d", &emp[numberOfEmployees].employeeAge);

				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[numberOfEmployees].employeeSalary);

				printf("\n");

				numberOfEmployees += 1;
			}
			else
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");

			break;

		case 3: // Update Employee

			if (numberOfEmployees > 0) // check if there's any Employee in the array
			{
				printf("Update Employee Salary\n");
				printf("======================\n");

				do
				{
					printf("Enter Employee ID: ");
					scanf("%d", &searchEmployeeID);

					// search the array for the value entered
					for (i = 0; i < SIZE; i++)
					{
						if (emp[i].employeeID == searchEmployeeID)
						{
							arraySearchControl = i; // store the array index
						}
					}

				} while (arraySearchControl < 0);

				printf("The current salary is %.2lf\n", emp[arraySearchControl].employeeSalary);
				printf("Enter Employee New Salary: ");
				scanf("%lf", &emp[arraySearchControl].employeeSalary);

				printf("\n");

				arraySearchControl = -1; // reset value for the search control
			}
			else // if not, print error message
				printf("Sorry! No Employees registered yet. Please select another option.\n\n");

			break;

		case 4: // Remove Employee

			if (numberOfEmployees > 0) // check if there's any Employee in the array
			{

				printf("Remove Employee\n");
				printf("===============\n");

				do
				{
					printf("Enter Employee ID: ");
					scanf("%d", &searchEmployeeID);

					// search the array for the value entered
					for (i = 0; i < SIZE; i++)
					{
						if (emp[i].employeeID == searchEmployeeID)
						{
							arraySearchControl = i; // store the array index
						}
					}

				} while (arraySearchControl < 0);

				printf("Employee %d will be removed\n", emp[arraySearchControl].employeeID);
				printf("\n");

				emp[arraySearchControl].employeeID = 0; // remove the employee by putting 0 to the ID
				numberOfEmployees -= 1; // reduce the employee valid count
				arraySearchControl = -1; // reset value for the search control

			}
			else // if not, print error message
				printf("Sorry! No Employees registered yet. Please select another option.\n\n");


			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	printf("Exiting Employee Data Program. Good Bye!!!\n");


	return 0;
}


// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 113
Enter Employee Age: 53
Enter Employee Salary: 120345.78

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 114
Enter Employee Age: 25
Enter Employee Salary: 46780

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 112
The current salary is 65000.00
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   99999.99
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 112
Employee 112 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/
