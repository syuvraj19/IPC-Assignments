/*--------------------SENECA COLLEGE-----------------------------
Student       : Yuvraj Singh
Student ID    : 155580210
Student Email : yuvraj-singh5@myseneca.ca
Class         : IPC-144 - Introduction to Programming using C
Description   : Workshop 09 - Files
---------------------------------------------------------------*/

#include <stdio.h>
#define MAX_TITLE_SIZE 21 // 20 chars + 1 terminator
#define TRUE 1
#define FALSE 0

//Type the struct here
struct Book {
	int _isbn;
	float _price;
	int _year;
	int _qty;
	char _title[MAX_TITLE_SIZE];
};


/*---------------------------------------------------------------
----------------------PROTOTYPES---------------------------------
---------------------------------------------------------------*/
void flushKeyboard(void);
int getInt(void);
float getFloat(void);
void menu();
void displayInventory(const char filename[]);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);
int searchInventory(FILE *fp, const int isbn2find);
float calculateCapital(const char filename[]);
int readRecord(FILE *fp, struct Book *b2read);

/*---------------------------------------------------------------
----------------------FUNCTION DEFINITION------------------------
---------------------------------------------------------------*/
// Flush Keyboard
void flushKeyboard(void)
{
	// Clear the input buffer
	while (getchar() != '\n')
		; // empty statement
}
//---------------------------------------------------------------

// Get Int
// receive an integer from keyboard
int getInt(void)
{
	int inputInteger = 0, //user input
		returnScanf = 0, // return code from scanf function
		keepTrying = 1; // controls iteration
	char inputCharacter = 'x'; // controls <ENTER>

							   // capture user input and check if its an integer
	do {

		returnScanf = scanf("%d%c", &inputInteger, &inputCharacter);

		if (returnScanf == 0 || inputCharacter != '\n')
		{
			// if not, clear buffer and try again
			printf("Invalid integer, please try again: ");
			flushKeyboard();
		}
		else
			// set to 0 to exit
			keepTrying = 0;
	} while (keepTrying == 1);

	return inputInteger;
}
//---------------------------------------------------------------

// Get Float
// receive a float from keyboard
float getFloat(void)
{
	float inputFloat = 0, //user input
		returnScanf = 0, // return code from scanf function
		keepTrying = 1; // controls iteration
	char inputCharacter = 'x'; // controls <ENTER>

							   // capture user input and check if its a float
	do {

		returnScanf = scanf("%f%c", &inputFloat, &inputCharacter);

		if (returnScanf == 0 || inputCharacter != '\n')
		{
			// if not, clear buffer and try again
			printf("Invalid number, please try again: ");
			flushKeyboard();
		}
		else
			// set to 0 to exit
			keepTrying = 0;
	} while (keepTrying == 1);

	return inputFloat;
}
//---------------------------------------------------------------

// Menu
void menu()
{
	printf("Please select from the following options:\n"
		"1) Display the inventory.\n"
		"2) Add a book to the inventory.\n"
		"3) Check price.\n"
		"4) Calculate total capital of the store.\n"
		"0) Exit.\n");
}
//---------------------------------------------------------------

// Read Record
int readRecord(FILE *fp, struct Book *b2read)
{
	int result = 0;

	// Read the first register from fp
	result = fscanf(fp, "%d;%f;%d;%d;%20[^\n]", &b2read->_isbn, &b2read->_price, &b2read->_year, &b2read->_qty, b2read->_title);

	return result;
}
//---------------------------------------------------------------

// Display Inventory
void displayInventory(const char filename[])
{
	int isFive = 0;

	FILE *fp = NULL;

	//Define an object of struct Book
	struct Book book = { 0 };

	//Open the file
	fp = fopen(filename, "r");

	// Check for NULL pointer (file closed)
	if (fp != NULL)
	{
		// Print header
		printf("\n\n"
			"Inventory\n"
			"===================================================\n"
			"ISBN      Title               Year Price  Quantity\n"
			"---------+-------------------+----+-------+--------\n");

		// Read all registers from the file (5 columns)
		do
		{
			isFive = readRecord(fp, &book);
			if (isFive == 5)
				printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);
		} while (isFive == 5);

		// Print footer
		printf("===================================================\n\n");

	}

	// Close the file
	fclose(fp);

}
//---------------------------------------------------------------

// Calculate Capital
float calculateCapital(const char filename[])
{
	FILE *fp = NULL;

	int isFive = 0;

	//Define an object of struct Book
	struct Book book = { 0 };

	//Define and initialize total_capital
	float totalCapital = 0;

	//Open the file, and check for null pointer
	fp = fopen(filename, "r");

	if (fp != NULL)
	{
		// Read all registers from the file (5 columns)
		do
		{
			isFive = readRecord(fp, &book);
			//Accumulate the multiplication of the price of each item to its quantity
			if (isFive == 5)
				totalCapital += (book._price * book._qty);
		} while (isFive == 5);
	}

	//Close the file
	fclose(fp);

	// Print footer
	printf("The total capital is: $%.2f.\n", totalCapital);

	//return the total_capital
	return totalCapital;

}
//---------------------------------------------------------------

// Search Inventory
int searchInventory(FILE *fp, const int isbn2find)
{
	int result = -1,
		isFive = 0;

	struct Book book = { 0 };

	if (fp != NULL)
	{
		// Read all registers from the file (5 columns)
		do
		{
			isFive = readRecord(fp, &book);
			// check if the isbn was found and return TRUE
			if (isFive == 5 && isbn2find == book._isbn)
				result = TRUE;
		} while (isFive == 5);
	}


	return result;
}
//---------------------------------------------------------------

// Add Book
void addBook(const char filename[], struct Book *b2Add)
{
	// File variable
	FILE *fp = NULL;

	int bookFound = 0;

	// open file in append mode
	fp = fopen(filename, "a");

	if (fp != NULL)
	{
		// search for the specified book
		bookFound = searchInventory(fp, b2Add->_isbn);

		// check if the book was found
		if (bookFound == TRUE)
			printf("The book exists in the repository!\n");
		else
		{
			// append book information to file
			fprintf(fp, "\n%d;%f;%d;%d;%s", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
			printf("The book is successfully added to the inventory\n\n");
		}
	}

	// close the file
	fclose(fp);
}

void checkPrice(const char filename[], const int isbn2find)
{

	// File variable
	FILE *fp = NULL;

	struct Book book = { 0 };

	int bookFound = 0,
		isFive = 0;

	// open the file
	fp = fopen(filename, "r");

	if (fp != NULL)
	{
		// search for the specified book
		bookFound = searchInventory(fp, isbn2find);
		rewind(fp);

		// check if the book was found
		if (bookFound == TRUE)
		{
			// Read all registers from the file (5 columns)
			do
			{
				isFive = readRecord(fp, &book);

				// check if the isbn was found and return TRUE
				if (isFive == 5 && isbn2find == book._isbn)
					printf("Book %d costs $%.2f\n\n", book._isbn, book._price);
			} while (isFive == 5);
		}
		else
			printf("Book not found!\n");
	}

	// close the file
	fclose(fp);

}
//---------------------------------------------------------------


/*---------------------------------------------------------------
----------------------MAIN FUNCTION------------------------------
---------------------------------------------------------------*/
int main()
{
	// Variable Definition
	struct Book mybook; //An object of struct Book 
	char filename[] = "inventory.txt"; //Name of the file
	int userInput = 0,
		isbnInput = 0,
		bookFound = 0;

	FILE *fp = NULL;

	// Welcome Message
	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	do
	{
		// Displays Menu and capture user input
		menu();
		printf("\n");
		printf("Select: ");
		userInput = getInt();

		// Check the user input
		switch (userInput)
		{
		case 0: //Exit the program
			printf("Goodbye!\n");
			break;

		case 1: // Displays Inventory
			displayInventory(filename);
			break;

		case 2: // Add Book

			// ISBN
			printf("ISBN:");
			mybook._isbn = getInt();

			// Title
			printf("Title:");
			scanf("%20[^\n]", mybook._title);
			flushKeyboard();

			// Year
			printf("Year:");
			mybook._year = getInt();

			// Price
			printf("Price:");
			mybook._price = getFloat();

			// Quantity
			printf("Quantity:");
			mybook._qty = getInt();

			fp = fopen(filename, "r");

			if (fp != NULL)
			{
				bookFound = searchInventory(fp, mybook._isbn);

				if (bookFound != TRUE)
				{
					// Add book with the information provided
					addBook(filename, &mybook);

					fclose(fp);
				}
				else
				{
					printf("The book exists in the repository!\n\n");
					fclose(fp);
				}
			}
			
				

			break;

		case 3: // Check Price

			// ISBN
			printf("Please input the ISBN number of the book:\n\n");
			isbnInput = getInt();

			checkPrice(filename, isbnInput);
			break;

		case 4: // Calculate Capital
			calculateCapital(filename);
			break;

		default: // Error message
			printf("Invalid input, try again:\n");
			break;
		}

	} while (userInput != 0);

	return 0;
}
