/*--------------------SENECA COLLEGE-----------------------------
Student       : Yuvraj Singh
Student ID    : 155580210
Student Email : yuvraj-singh5@myseneca.ca
Class         : IPC-144 - Introduction to Programming using C
Description   : Workshop 08 - Functions with Structs
---------------------------------------------------------------*/

#include <stdio.h>

/*---------------------------------------------------------------
----------------------CONSTANT DECLARATION-----------------------
---------------------------------------------------------------*/
#define MAX_TITLE_SIZE 21 // 20 +1 for the String terminator
#define MAX_BOOKS 10

/*---------------------------------------------------------------
----------------------STRUCTURE DECLARATION----------------------
---------------------------------------------------------------*/
struct Book {
	int _isbn; // International Standard Book Number
	float _price; // Book price
	int _year; // Publication year
	char _title[MAX_TITLE_SIZE]; // Book title
	int _qty; // Book Quantity
};

/*---------------------------------------------------------------
----------------------PROTOTYPES---------------------------------
---------------------------------------------------------------*/
void flushKeyboard(void);
int getInt(void);
float getFloat(void);
void menu();
void displayInventory(const struct Book book[], const int size);
int searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);

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
		"0) Exit.\n");
}
//---------------------------------------------------------------

// Display Inventory
void displayInventory(const struct Book book[], const int size)
{
	int i = 0; // iterator

			   // Check if the inventory is empty
	if (size == 0)
	{
		printf("The inventory is empty!\n"
			"===================================================\n\n");
	}
	else
	{
		printf("\n\nInventory\n"
			"===================================================\n"
			"ISBN      Title               Year Price  Quantity\n"
			"---------+-------------------+----+-------+--------\n");

		// Display the array of Books
		for (i = 0; i < size; i++)
		{
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
		}

		// footer
		printf("===================================================\n\n");
	}
}
//---------------------------------------------------------------

// Search Inventory
int searchInventory(const struct Book book[], const int isbn, const int size)
{
	int result = -1,
		i = 0;

	// Checks if ISBN matches and return the array index
	for (i = 0; i < size; i++)
	{
		if (book[i]._isbn == isbn)
			result = i;
	}

	return result;
}
//---------------------------------------------------------------

// Add Book
void addBook(struct Book book[], int *size)
{
	int bookIndex = 0,
		auxISBN = 0, // ISBN auxiliar
		auxQty = 0; // Quantity auxiliar

	// ISBN
	printf("ISBN:");
	auxISBN = getInt();

	// Quantity
	printf("Quantity:");
	auxQty = getInt();

	// Search inventory
	bookIndex = searchInventory(book, auxISBN, *size);

	if (bookIndex != -1)
	{
		book[bookIndex]._qty += auxQty;
		printf("The book exists in the repository, quantity is updated.\n\n");
	}
	else if(bookIndex == -1 && *size >= MAX_BOOKS)
	{
		printf("The inventory is full\n");
	}
	else if (bookIndex == -1 && *size < MAX_BOOKS)
	{
		// ISBN
		book[*size]._isbn = auxISBN;

		// Quantity
		book[*size]._qty = auxQty;

		// Title
		printf("Title:");
		scanf("%20[^\n]", book[*size]._title);
		flushKeyboard();

		// Year
		printf("Year:");
		book[*size]._year = getInt();

		// Price
		printf("Price:");
		book[*size]._price = getFloat();

		// Success Message
		printf("The book is successfully added to the inventory.\n\n");

		*size += 1;
	}
}
//---------------------------------------------------------------

// Check Price
void checkPrice(const struct Book book[], const int size)
{
	int userInput = 0,
		auxIndex = 0;

	printf("Please input the ISBN number of the book:\n\n");
	userInput = getInt();

	auxIndex = searchInventory(book, userInput, size);

	if (auxIndex == -1)
		printf("Book does not exist in the bookstore! Please try again.\n");
	else
		printf("Book %d costs $%.2f\n", userInput, book[auxIndex]._price);

	printf("\n");
}
//---------------------------------------------------------------


/*---------------------------------------------------------------
----------------------MAIN FUNCTION------------------------------
---------------------------------------------------------------*/
int main(void)
{
	int userInput = 0,
		size = 0; // Number of books in the inventory. The inventory is initially empty

				  // Variable Declaration
	struct Book book[MAX_BOOKS]; // An array of Book representing the inventory

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
			displayInventory(book, size);
			break;

		case 2: // Add Book
			addBook(book, &size);
			break;

		case 3: // Check Price
			checkPrice(book, size);
			break;

		default: // Error message
			printf("Invalid input, try again:\n");
			break;
		}

	} while (userInput != 0);

	return 0;

}
