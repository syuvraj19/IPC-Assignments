/*--------------------SENECA COLLEGE-----------------------------
Student       : Yuvraj Singh
Student ID    : 155580210
Student Email : yuvraj-singh5@myseneca.ca
Class         : IPC-144 - Introduction to Programming using C
Description   : Workshop 10 - Strings
---------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

// Define statements
#define _CRT_SECURE_NO_WARNINGS
#define JEDI_MASTER "jedi_master.txt"
#define TRUE 1


// Is Jedi Master
int isJediMaster(const char name[])
{
	FILE *fp = NULL;

	int isJedi = 0,
		jediMasterCounter = 0;

	char jediName[31] = { "" };

	// opens the file
	fp = fopen(JEDI_MASTER, "r");

	// if the file is opened
	if (fp != NULL)
	{
		do
		{
			jediMasterCounter = fscanf(fp, "%30[^\n]\n", jediName);
			if (jediMasterCounter == 1)
			{
				// compare the Jedi name with the master list
				if (strcmp(name, jediName) == 0)
					isJedi = TRUE;
			}
		} while (jediMasterCounter == 1);

	}

	return isJedi;
}

// Format Jedi Phone Record
void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[])
{
	const int nameLength = strlen(fullName),
			  spaceLength = 16 - nameLength;

	char spaces[17] = "                "; // 16 spaces

	strcpy(formattedRecord, fullName); // copy the fullName to formattedRecord

	// if the name has more than 16 characters (including), short it and add ..
	if (nameLength > 16)
	{
		formattedRecord[14] = '.'; // first dot
		formattedRecord[15] = '.'; // second dot
		formattedRecord[16] = '\0'; // truncate the string
	}
	else
	{
		spaces[spaceLength] = '\0'; // truncate the string
		strcat(formattedRecord, spaces); // Add spaces to the formattedRecord to fill 16 positions
	}
	
	// concatenates the information in one single string
	// 1
	strcat(formattedRecord, " (");
	// 2
	strcat(formattedRecord, npa);
	// 3
	strcat(formattedRecord, ") ");
	// 4
	strcat(formattedRecord, co);
	// 5
	strcat(formattedRecord, "-");
	// 6
	strcat(formattedRecord, number);
	// 7 - if this the name is of a Jedi Master, concatenate (" Jedi Master")
	strcat(formattedRecord, (isJediMaster(fullName) == TRUE ? " Jedi Master" : "") );

}


/* formatted strings:
Padme Amidala    (418) 555-0105
Mace Windu       (438) 555-0155 Jedi Master.
Emperor Palpat.. (450) 555-0143
*/
