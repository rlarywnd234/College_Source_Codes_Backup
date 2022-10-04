//==============================================
// Name:           KYO JUNG KIM
// Student Number: 132625161
// Email:          kkim107@myseneca.ca
// Section:        IPC144ZAA
// Date:           2021-07-27
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+
void getName(struct Name* name)
{
    int yesNo;
    printf("Please enter the contact's first name: ");
    scanf("%[^\n]s", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    yesNo=yes();

    if (yesNo == 1)
    {
     printf("Please enter the contact's middle initial(s): ");
     scanf("%[^\n]s", name->middleInitial);
     clearKeyboard();
    }
    printf("Please enter the contact's last name: ");
    scanf("%[^\n]s", name->lastName);
    clearKeyboard();
}



void getAddress(struct Address* address)
{
    int yesNo;
    int integer=0;
    printf("Please enter the contact's street number: ");
    integer = getInt();
    address->streetNumber = integer;
    
    if (integer < 0)
    {
     printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
     integer = getInt();
     address->streetNumber = integer;
     
    }

    printf("Please enter the contact's street name: ");
    scanf("%[^\n]s", address->street);
    clearKeyboard();
    
    printf("Do you want to enter an apartment number? (y or n): ");
    yesNo = yes();

    if (yesNo == 1)
    {
        printf("Please enter the contact's apartment number: ");
        integer = getInt();
        address->apartmentNumber = integer;

        if (integer < 0)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            integer = getInt();
            address->apartmentNumber = integer;
         
        }
    }
    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]s", address->postalCode);
    clearKeyboard();
    
    printf("Please enter the contact's city: ");
    scanf("%[^\n]s", address->city);
    clearKeyboard();
}



void getNumbers(struct Numbers* numbers)
{
    int yesNo;
    


    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);
   
  
    printf("Do you want to enter a home phone number? (y or n): ");
    yesNo = yes();

    if (yesNo == 1)
    {
    printf("Please enter the contact's home phone number: ");
    getTenDigitPhone(numbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    yesNo = yes();

    if (yesNo == 1) 
    {
    printf("Please enter the contact's business phone number: ");
    getTenDigitPhone(numbers->business);
    }
}

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
