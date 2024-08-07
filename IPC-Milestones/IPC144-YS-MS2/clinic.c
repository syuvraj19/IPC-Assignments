/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : yuvraj singh
Student ID#: 155580210
Email      : yuvraj-singh5@myseneca.ca
Section    : IPC-144-ZEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
   printf("Pat.# Name            Phone#\n"
          "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
   if (fmt == FMT_FORM)
   {
       printf("Name  : %s\n"
              "Number: %05d\n"
              "Phone : ", patient->name, patient->patientNumber);
       displayFormattedPhone(patient->phone.number);
       printf(" (%s)\n", patient->phone.description);
   }
   else
   {
       printf("%05d %-15s ", patient->patientNumber,
              patient->name);
       displayFormattedPhone(patient->phone.number);
       printf(" (%s)\n", patient->phone.description);
   }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
   int selection;

   do
   {
       printf("Veterinary Clinic System\n"
              "=========================\n"
              "1) PATIENT     Management\n"
              "2) APPOINTMENT Management\n"
              "-------------------------\n"
              "0) Exit System\n"
              "-------------------------\n"
              "Selection: ");
       selection = inputIntRange(0, 2);
       putchar('\n');
       switch (selection)
       {
       case 0:
           printf("Are you sure you want to exit? (y|n): ");
           selection = !(inputCharOption("yn") == 'y');
           putchar('\n');
           if (!selection)
           {
               printf("Exiting system... Goodbye.\n\n");
           }
           break;
       case 1:
           menuPatient(data->patients, data->maxPatient);
           break;
       case 2:
           printf("<<< Feature not yet available >>>\n\n");
           break;
       }
   }
   while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
   int selection;

   do
   {
       printf("Patient Management\n"
              "=========================\n"
              "1) VIEW   Patient Data\n"
              "2) SEARCH Patients\n"
              "3) ADD    Patient\n"
              "4) EDIT   Patient\n"
              "5) REMOVE Patient\n"
              "-------------------------\n"
              "0) Previous menu\n"
              "-------------------------\n"
              "Selection: ");
       selection = inputIntRange(0, 5);
       putchar('\n');
       switch (selection)
       {
       case 1:
           displayAllPatients(patient, max, FMT_TABLE);
           suspend();
           break;
       case 2:
           searchPatientData(patient, max);
           break;
       case 3:
           addPatient(patient, max);
           suspend();
           break;
       case 4:
           editPatient(patient, max);
           break;
       case 5:
           removePatient(patient, max);
           suspend();
           break;
       }
   }
   while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
   int selection;

   do
   {
       printf("Edit Patient (%05d)\n"
              "=========================\n"
              "1) NAME : %s\n"
              "2) PHONE: ", patient->patientNumber, patient->name);

       displayFormattedPhone(patient->phone.number);

       printf("\n"
              "-------------------------\n"
              "0) Previous menu\n"
              "-------------------------\n"
              "Selection: ");
       selection = inputIntRange(0, 2);
       putchar('\n');

       if (selection == 1)
       {
           printf("Name  : ");
           inputCString(patient->name, 1, NAME_LEN);
           
           putchar('\n');
           
           printf("Patient record updated!\n\n");
       }
       else if (selection == 2)
       {
           inputPhoneData(&patient->phone);
           printf("Patient record updated!\n\n");
       }

   }
   while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
   int x=0,a=0;
   while(x<max)
   {
       if(patient[x].patientNumber != 0)
       {
           a = 1;
           break;
       }x++;
   }
    
   if (a == 0)
   {
       printf("*** No records found ***\n");
   }
   else
   {
       displayPatientTableHeader();
       x=0;
       do
       {
           if(patient[x].patientNumber != 0)
               displayPatientData(&patient[x], fmt);
           x++;
       }while(x<max);
   }
   putchar('\n');
}

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
   int value;
   do
   {
       printf("Search Options\n");
       printf("==========================\n");
       printf("1) By patient number\n");
       printf("2) By phone number\n");
       printf("..........................\n");
       printf("0) Previous menu\n");
       printf("..........................\n");
       printf("Selection: ");
       
       scanf("%d",&value);
       
       putchar('\n');
       
       while (value < 0 || value > 2)
       {
           printf("Error! Value must be between 0 and 2 inclusive: ");
           value = inputInt();
       }
       switch (value) {
           case 1:
               searchPatientByPatientNumber(patient, max);
               suspend();
               break;
               
           case 2:
           
               searchPatientByPhoneNumber(patient, max);
               suspend();
           break;
               
       }
   }
   while (value);
}


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
   int i=0,avalpoint,a=0;
   while(i<max)
   {
       if(patient[i].patientNumber == 0)
       {
           a = 1;
           avalpoint = i;
           break;
       }i++;
   }
    if(a!=0)
    {
        patient[avalpoint].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[avalpoint]);
        printf("*** New patient record added ***\n");
    }
    else if (a == 0)
   {
       printf("ERROR: Patient listing is FULL!\n");
   }

   putchar('\n');
    
}

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
   printf("Enter the patient number: ");
   int val = inputInt(),patient_slot = findPatientIndexByPatientNum(val, patient, max);
   putchar('\n');
   if (patient_slot == -1)
   {
       printf("ERROR: Patient record not found!\n");
   }
   else
   {
       menuPatientEdit(&patient[patient_slot]);
   }
}


// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
   printf("Enter the patient number: ");
   int val = inputInt(),patient_slot = findPatientIndexByPatientNum(val, patient, max);
   putchar('\n');
   if (patient_slot == -1)
   {
       printf("ERROR: Patient record not found!\n");
   }
   else
   {
       printf("Name  : %s\n", patient[patient_slot].name);
       printf("Number: %05d\n", patient[patient_slot].patientNumber);
       printf("Phone : ");
       
       displayFormattedPhone(patient[patient_slot].phone.number);
       
       printf(" (%s)\n", patient[patient_slot].phone.description);
       printf("\nAre you sure you want to remove this patient record? (y/n): ");
       
       char what;
       what = inputCharOption("yn");
       
    
       if (what == 'n')
       {
           printf("Operation aborted.\n");
       }
       else
       {
           patient[patient_slot].patientNumber = 0;
           
           printf("Patient record has been removed!\n");
       }
   }
   putchar('\n');
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
   printf("Search by patient number: ");
   int val = inputInt(),patient_slot = findPatientIndexByPatientNum(val, patient, max);
    
   putchar('\n');
    if (patient_slot== -1)
        {
            printf("*** No records found ***\n");
        }
        else
        {
            displayPatientData(&patient[patient_slot], FMT_FORM);
        }
   putchar('\n');
    
}

// Search and display patient records by phone number (tabular)********************
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
   char cell_no[11];
   printf("Search by phone number: ");
   inputCString(cell_no, 10, 10);
    
   putchar('\n');
   int a = 0, x=0;
   while(x<max)
   {
       if(strcmp(cell_no, patient[x].phone.number) == 0)
       {
           a = 1;
           break;
       }x++;
   }
   displayPatientTableHeader();
   if (a == 0)
   {
       putchar('\n');
       printf("*** No records found ***\n");
   }
   else
   {
       x=0;
       do
       {
           if(strcmp(cell_no, patient[x].phone.number) == 0)
               displayPatientData(&patient[x], FMT_TABLE);
           x++;
       }while(x < max);
   }
   putchar('\n');
}

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
   int i=0,x = -1;
   do
   {
       if(patient[i].patientNumber > x)
       {
           x = patient[i].patientNumber;
       }i++;
   }while(i<max);
   ++x;
   return x;

}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
   int x=0,slot = -1;
   do
   {
       if (patient[x].patientNumber == patientNumber)
       {
           slot = x;
           break;
       }x++;
   }while(x<max);
   return slot;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////


// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    
    inputCString(patient->name, 1, NAME_LEN);
    
    putchar('\n');
    
    inputPhoneData(&(patient->phone));
}

// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
   int x;
   printf("Phone Information\n");
   printf("-----------------\n");
   printf("How will the patient like to be contacted?\n");
   printf("1. Cell\n");
   printf("2. Home\n");
   printf("3. Work\n");
   printf("4. TBD\n");
   printf("Selection: ");
    
    x = inputIntRange(1, 4);
    
   putchar('\n');
    
   if (x == 1)
   {
       printf("Contact: ");
       puts("CELL");
       strcpy(phone->description, "CELL");
   }
   if (x == 2)
   {
       printf("Contact: ");
       puts("HOME");
       strcpy(phone->description, "HOME");
   }
   if (x == 3)
   {
       printf("Contact: ");
       puts("WORK");
       strcpy(phone->description, "WORK");
   }
   if (x == 4)
   {
       strcpy(phone->description, "TBD");
   }
   else
   {
       printf("Number : ");
       inputCString(phone->number, 10, 10);
       putchar('\n');
   }
}
