//==============================================
// Name:           KYO JUNG KIM
// Student Number: 132625161
// Email:          kkim107@myseneca.ca
// Section:        IPC144ZAA
// Date:           2021-07-27
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"
#define MAXCONTACTS 5

void clearKeyboard(void)
{
    char trash = 0;
    while (trash != '\n')
    {
        scanf("%c", &trash);
    }
}

// pause function definition goes here:
void pause(void)
{
    char pause;
    printf("(Press Enter to Continue)");
    scanf("%c", &pause);
}

// getInt function definition goes here:
int getInt(void)
{
    int num = 0;
    char line = 0;
    do {
        scanf("%d%c", &num, &line);
        if (line != '\n') {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }
    } while (line != '\n');

    return num;
}

// getIntInRange function definition goes here:
int  getIntInRange(int min, int max)
{
    int integer;
    do {
        integer = getInt();
        if (integer < min || integer > max) {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }
    } while (integer < min || integer > max);
    printf("\n");
    return integer;
}

// yes function definition goes here:
int yes(void)
{
    char i;
    char line = 0;
    do
    {
        scanf("%c%c", &i, &line);
        if (!(i == 'y' || i == 'Y' || i == 'N' || i == 'n') || line != '\n')
        {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            if (line != '\n') { clearKeyboard(); }
        }
    } while (!(i == 'y' || i == 'Y' || i == 'N' || i == 'n') || line != '\n');
    if (line != '\n') { clearKeyboard(); }
    return i == 'y' || i == 'Y';
}


// menu function definition goes here:
int menu(void)
{
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\nSelect an option:> ");


    return getIntInRange(0, 6);
}




// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
    int z = 0;
  
    struct Contact contacts[MAXCONTACTS] =
    { { { "Rick", {'\0'}, "Grimes" },
        { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
        { "4161112222", "4162223333", "4163334444" } },
      {
        { "Maggie", "R.", "Greene" },
        { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
        { "9051112222", "9052223333", "9053334444" } }, 
      {
        { "Morgan", "A.", "Jones" },
        { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
        { "7051112222", "7052223333", "7053334444" } },
      {
        { "Sasha", {'\0'}, "Williams" },
        { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
        { "9052223333", "9052223333", "9054445555" } },
    };
    do {

        z = menu();


        if (z == 1) 
        {
            displayContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
        }
        else if (z == 2) {
            addContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
        }
        else if (z == 3) {
            updateContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
        }
        else if (z == 4) {
            deleteContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
        }
        else if (z == 5) {
            searchContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
        }
        else if (z == 6) {
            sortContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
        }
        else
        {
            printf("Exit the program? (Y)es/(N)o: ");
            if (1 == yes())
            {
                printf("\nContact Management System: terminated");
                z = 8;
            }
            printf("\n");
        }
    } while (z != 8);
}


void Dname(struct Name* discard_name)
{
    strcpy(discard_name->firstName, "");
    strcpy(discard_name->middleInitial, "");
    strcpy(discard_name->lastName, "");
}
void Daddress(struct Address* discard_address)
{
    strcpy(discard_address->street, "");
    strcpy(discard_address->city, "");
    strcpy(discard_address->postalCode, "");
    discard_address->apartmentNumber = 0;
    discard_address->streetNumber = 0;
}
void Dnumber(struct Numbers* discard_number)
{
    strcpy(discard_number->cell, "");
    strcpy(discard_number->home, "");
    strcpy(discard_number->business, "");
}

void switchContacts(struct Contact* contactN, struct Contact* contactS)
{
    strcpy(contactN->address.city, contactS->address.city);
    strcpy(contactN->address.postalCode, contactS->address.postalCode);
    strcpy(contactN->numbers.cell, contactS->numbers.cell);
    strcpy(contactN->numbers.home, contactS->numbers.home);
    strcpy(contactN->numbers.business, contactS->numbers.business);
    strcpy(contactN->name.firstName, contactS->name.firstName);
    strcpy(contactN->name.middleInitial, contactS->name.middleInitial);
    strcpy(contactN->name.lastName, contactS->name.lastName);
    contactN->address.streetNumber = contactS->address.streetNumber;
    strcpy(contactN->address.street, contactS->address.street);
    contactN->address.apartmentNumber = contactS->address.apartmentNumber;
 
}

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;
    while (needInput == 1) {
        scanf("%10[0-9]s", phoneNum);
        clearKeyboard();
        if ((strlen(phoneNum) == 10))
        {
            needInput = 0;
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    
    int i, j = -1;
    int A = 1;
    for (i = 0; (i < size) && (A == 1); i++)
    {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
        {
            j = i;
            A = 0;
        }
    }
    return j;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
 printf("+-----------------------------------------------------------------------------+\n|                              Contacts Listing                               |\n+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
printf("+-----------------------------------------------------------------------------+\n");
printf("Total contacts: %d\n\n", count);
}



// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
    printf(" ");
    printf("%s", contact->name.firstName);
    if (strlen(contact->name.middleInitial) > 0)
    {
        printf(" ");
        printf("%s", contact->name.middleInitial);
    }
    printf(" ");
    printf("%s\n", contact->name.lastName);
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact -> numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact -> address.street);
    if (contact->address.apartmentNumber > 0) 
    {printf("Apt# %d, ", contact->address.apartmentNumber);}
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}




// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
    displayContactHeader();
    int i, A = 0;
    for (i = 0; i < size; i++) 
    {
        if (strlen(contacts[i].numbers.cell) > 0) 
        {displayContact(&contacts[i]);
            A++;}
    }
    displayContactFooter(A);
}


// searchContacts:
// Put empty function definition below:

void searchContacts(const struct Contact contacts[], int size)
{
    int i;
    char Num[11];
    printf("Enter the cell number for the contact: ");
 
    getTenDigitPhone(Num);
    i = findContactIndex(contacts, size, Num);
    if (i == -1)
    {
        printf("*** Contact NOT FOUND ***\n\n");
    }
    else
    {
        printf("\n");
        displayContact(&contacts[i]);
        printf("\n");
    }
}



// addContact:
// Put empty function definition below:

void addContact(struct Contact contacts[MAXCONTACTS], int size)
{
    int i;
    i = findContactIndex(contacts, size, "");
    if (i == -1) 
    {
        printf("*** ERROR: The contact list is full! ***\n\n");
    }
    else
    {
        getContact(&contacts[i]);
        printf("--- New contact added! ---\n\n");
    }
}



// updateContact:
// Put empty function definition below:

void updateContact(struct Contact contacts[], int size)
{
    int i;
    char Num[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(Num);
    i = findContactIndex(contacts, size, Num);
    if (i == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    }
    else
    {
        printf("\n");
        printf("Contact found:\n");
        displayContact(&contacts[i]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        if (yes() == 1) {
            Dname(&(contacts[i].name));
            getName(&(contacts[i].name));
        }
        printf("Do you want to update the address? (y or n): ");
        if (yes() == 1) {
            Daddress(&(contacts[i].address));
            getAddress(&(contacts[i].address));
        }
        printf("Do you want to update the numbers? (y or n): ");
        if (yes() == 1) {
            Dnumber(&(contacts[i].numbers));
            getNumbers(&(contacts[i].numbers));
        }
        printf("--- Contact Updated! ---\n\n");
    }
}
// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
    int i;
    char Num[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(Num);
    i = findContactIndex(contacts, size, Num);
    if (i == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    }
    else
    {
        printf("\n");
        printf("Contact found:\n");
        displayContact(&contacts[i]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes() == 1) 
        { 
            Daddress(&(contacts[i].address));
            Dname(&(contacts[i].name));
            Dnumber(&(contacts[i].numbers));
            printf("--- Contact deleted! ---\n");
        }
        printf("\n");
    }
}







// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[MAXCONTACTS], int size)
{
    int i, j, m;
    struct Contact Contact;
    for (i = 0; i < size; i++) {
        m = i;
        for (j = i + 1; j < size; j++) {if (strcmp(contacts[j].numbers.cell, contacts[m].numbers.cell)< 0) {m = j;}}
        if (m != i) 
        {
            switchContacts(&Contact, &contacts[i]);
            switchContacts(&contacts[i], &contacts[m]);
            switchContacts(&contacts[m], &Contact);
        }
    }
    printf("--- Contacts sorted! ---\n\n");
}




