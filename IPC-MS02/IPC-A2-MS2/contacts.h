/* -------------------------------------------
Name:            Yuvraj Singh
Student number:  155580210
Email:           yuvraj-singh5@myseneca.ca
Assignment-2-Milestone-2
---------------------------------------------- */

//--------------------------------
// Structure Types
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        contents below...                        |
// +-------------------------------------------------+

// Structure type Name declaration (Milestone 1)
struct Name
{
  char firstName[31];
  char middleInitial[7];
  char lastName[36];
};

// Structure type Address declaration (Milestone 1)
struct Address
{
  int streetNumber;
  char street[41];
  int apartmentNumber;
  char postalCode[8];
  char city[41];
};

// Structure type Numbers declaration (Milestone 1)
struct Numbers
{
  char cell[11];
  char home[11];
  char business[11];
};

// Structure type Contact declaration (Milestone 3)
struct Contact
{
  struct Name name;
  struct Address address;
  struct Numbers numbers;
};

//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------------+
// |    ====== Assignment 2 | Milestone 1 =======    |
// |                                                 |
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Get and store from standard input the values for Name
void getName(struct Name *name);

// Get and store from standard input the values for Address
void getAddress(struct Address *address);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers *numbers);

// Get and stroe from standard input the values for Contact
void getContact(struct Contact *contact);
