/* -------------------------------------------
Name:            Yuvraj Singh
Student number:  155580210
Email:           yuvraj-singh5@myseneca.ca
Assignment-2-Milestone-2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               |
// +-------------------------------------------------+

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(struct Name *name)
{
  // int yesNo; // Feedback -> To make more simply. do not need to declear variable

  printf("Please enter the contact's first name: ");
  scanf("%30[^\n]", name->firstName);
  clearKeyboard();

  printf("Do you want to enter a middle initial(s)? (y or n): ");
  // yesNo = yes();   // Feedback -> To make more simply. do not need to declear variable
  // if (yesNo == 1)  // Feedback -> To make more simply. do not need to declear variable
  if (yes() == 1) // Feedback -> To make more simply. do not need to declear variable
  {
    printf("Please enter the contact's middle initial(s): ");
    scanf("%6[^\n]", name->middleInitial);
    clearKeyboard();
  }

  printf("Please enter the contact's last name: ");
  scanf("%35[^\n]", name->lastName);
  clearKeyboard();
}

// getAddress:
void getAddress(struct Address *address)
{
  // int yesNo; // Feedback -> To make more simply. do not need to declear variable

  printf("Please enter the contact's street number: ");
  // address->streetNumber = streetNumber(); // Feedback -> you could reduce this to 1 function where the argument would be the “error” message:
  address->streetNumber = getPositiveInt("*** INVALID STREET NUMBER *** <must be a positive number>: ");

  printf("Please enter the contact's street name: ");
  scanf("%40[^\n]", address->street);
  clearKeyboard();

  printf("Do you want to enter an apartment number? (y or n): ");
  // yesNo = yes();     // Feedback -> To make more simply. do not need to declear variable
  // if (yesNo == 1)    // Feedback -> To make more simply. do not need to declear variable
  if (yes() == 1) // Feedback -> To make more simply. do not need to declear variable
  {
    printf("Please enter the contact's apartment number: ");
    // address->apartmentNumber = apartmentNumber();  // Feedback -> you could reduce this to 1 function where the argument would be the “error” message:
    address->apartmentNumber = getPositiveInt("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
  }

  printf("Please enter the contact's postal code: ");
  scanf("%7[^\n]", address->postalCode);
  clearKeyboard();

  printf("Please enter the contact's city: ");
  scanf("%40[^\n]", address->city);
  clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers *numbers)
{
  // int yesNo; // Feedback -> To make more simply. do not need to declear variable

  printf("Please enter the contact's cell phone number: ");
  scanf("%10[^\n]", numbers->cell);
  clearKeyboard();

  printf("Do you want to enter a home phone number? (y or n): ");
  // yesNo = yes();   // Feedback -> To make more simply. do not need to declear variable
  // if (yesNo == 1)  // Feedback -> To make more simply. do not need to declear variable
  if (yes() == 1) // Feedback -> To make more simply. do not need to declear variable
  {
    printf("Please enter the contact's home phone number: ");
    scanf("%10[^\n]", numbers->home);
    clearKeyboard();
  }

  printf("Do you want to enter a business phone number? (y or n): ");
  // yesNo = yes();   // Feedback -> To make more simply. do not need to declear variable
  // if (yesNo == 1)  // Feedback -> To make more simply. do not need to declear variable
  if (yes() == 1) // Feedback -> To make more simply. do not need to declear variable
  {
    printf("Please enter the contact's business phone number: ");
    scanf("%10[^\n]", numbers->business);
    clearKeyboard();
  }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *contact)
{
  getName(&contact->name);
  getAddress(&contact->address);
  getNumbers(&contact->numbers);
}
