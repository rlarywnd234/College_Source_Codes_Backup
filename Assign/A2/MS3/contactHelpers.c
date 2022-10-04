//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
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
#include "contactHelpers.h"
#include "contacts.h"

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
    char YorN;
    struct Contact cont[MAXCONTACTS] = 
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


        switch (z)
        {
        case 1:
            printf("\n<<< Feature 1 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 2:
            printf("\n<<< Feature 2 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 3:
            printf("\n<<< Feature 3 is unavailable >>>\n\n");
            pause();
            printf("\n");
        case 4:
            printf("\n<<< Feature 4 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 5:
            printf("\n<<< Feature 5 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 6:
            printf("\n<<< Feature 6 is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            scanf("%c", &YorN);
            if (YorN == 'Y' || YorN == 'y')
            {
                printf("Contact Management System: terminated");
                z = 8;
            }
            break;
        }
    } while (z != 8);
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
    int flag = 1;
    int i, indx = -1;
    for (i = 0; (i < size) && (flag == 1); i++) {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
            indx = i;
            flag = 0;
        }
    }
    return indx;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
 printf("+--------------------------------------------------------------------------+ \n");
 printf("|                             Contacts Listing                             | \n");
 printf("+--------------------------------------------------------------------------+ \n");
}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
printf("+---------------------------------------------------------------------------+\n");
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
    printf(" C: %-10s H: %-10s B: %-10s\n", contact -
> numbers.cell, contact->numbers.home, contact->numbers.business);
    printf(" %d %s, ", contact->address.streetNumber, contact -
> address.street);
    if (contact->address.apartmentNumber > 0) 
    {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}




// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) 
{
    displayContactHeader();
    int i, flag = 0;
    for (i = 0; i < size; i++) {
        if (strlen(contacts[i].numbers.cell) > 0) {
            displayContact(&contacts[i]);
            flag++;
        }
    }
    displayContactFooter(flag);
}



// searchContacts:
// Put empty function definition below:

void searchContacts(const struct Contact contacts[], int size)
{
    int index;
    char searchNum[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(searchNum);
    index = findContactIndex(contacts, size, searchNum);
    if (index == -1)
    {
        printf("*** Contact NOT FOUND ***\n\n");
    }
    else
    {
        printf("\n");
        displayContact(&contacts[index]);
        printf("\n");
    }
}



// addContact:
// Put empty function definition below:

void addContact(struct Contact contacts[MAXCONTACTS], int size)
{
    int index;
    index = findContactIndex(contacts, size, "");
    if (index == -1) {
        printf("*** ERROR: The contact list is full! ***\n\n");
    }
    else {
        getContact(&contacts[index]);
        printf("--- New contact added! ---\n\n");
    }
}



// updateContact:
// Put empty function definition below:

void updateContact(struct Contact contacts[], int size)
{
    int index;
    char searchNum[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(searchNum);
    index = findContactIndex(contacts, size, searchNum);
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    }
    else
    {
        printf("\n");
        printf("Contact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        if (yes() == 1) {
            cleanName(&(contacts[index].name));
            getName(&(contacts[index].name));
        }
        printf("Do you want to update the address? (y or n): ");
        if (yes() == 1) {
            cleanAddress(&(contacts[index].address));
            getAddress(&(contacts[index].address));
        }
        printf("Do you want to update the numbers? (y or n): ");
        if (yes() == 1) {
            cleanNumber(&(contacts[index].numbers));
            getNumber(&(contacts[index].numbers));
        }
        printf("--- Contact Updated! ---\n\n");
    }
}
// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
    int index;
    char searchNum[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(searchNum);
    index = findContactIndex(contacts, size, searchNum);
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    }
    else
    {
        printf("\n");
        printf("Contact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes() == 1) {
           
            cleanAddress(&(contacts[index].address));
            cleanName(&(contacts[index].name));
            cleanNumber(&(contacts[index].numbers));
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
    struct Contact tmpContact;
    for (i = 0; i < size; i++) {
        m = i;
        for (j = i + 1; j < size; j++) {
            if (strcmp(contacts[j].numbers.cell, contacts[m].numbers.cell)
                < 0) {
                m = j;
            }
        }
        if (m != i) {
            switchContacts(&tmpContact, &contacts[i]);
            switchContacts(&contacts[i], &contacts[m]);
            switchContacts(&contacts[m], &tmpContact);
        }
    }
    printf("--- Contacts sorted! ---\n\n");
}
void cleanName(struct Name* dName)
{
    strcpy(dName->firstName, "");
    strcpy(dName->middleInitial, "");
    strcpy(dName->lastName, "");
}
void cleanAddress(struct Address* dAddress) 
{
    strcpy(dAddress->street, "");
    strcpy(dAddress->city, "");
    strcpy(dAddress->postalCode, "");
    dAddress->apartmentNumber = 0;
    dAddress->streetNumber = 0;
}
void cleanNumber(struct Numbers* dNumber)
{
    strcpy(dNumber->cell, "");
    strcpy(dNumber->home, "");
    strcpy(dNumber->business, "");
}

void switchContacts(struct Contact* contactN, struct Contact* contactS) 
{
    strcpy(contactN->name.firstName, contactS->name.firstName);
    strcpy(contactN->name.middleInitial, contactS->name.middleInitial);
    strcpy(contactN->name.lastName, contactS->name.lastName);
    contactN->address.streetNumber = contactS->address.streetNumber;
    strcpy(contactN->address.street, contactS->address.street);
    contactN->address.apartmentNumber = contactS->address.apartmentNumber;
    strcpy(contactN->address.city, contactS->address.city);
    strcpy(contactN->address.postalCode, contactS->address.postalCode);
    strcpy(contactN->numbers.cell, contactS->numbers.cell);
    strcpy(contactN->numbers.home, contactS->numbers.home);
    strcpy(contactN->numbers.business, contactS->numbers.business);
}
