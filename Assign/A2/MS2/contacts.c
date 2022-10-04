//==============================================
// Name:           KYO JUNG KIM
// Student Number: 132625161
// Email:          kkim107@myseneca.ca
// Section:        IPC144ZAA
// Date:           2022-07-14
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS
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
    scanf("%30[^\n]%*c", name->firstName);
    

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    yesNo=yes();

    if (yesNo == 1)
    {
     printf("Please enter the contact's middle initial(s): ");
     scanf("%6[^\n]%*c", name->middleInitial);
     clearKeyboard();
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);



}
// clear


void getAddress(struct Address* address)
{
    int yesNo;
    int integer;
    printf("Please enter the contact's street number: ");
    integer = getInt();
    
    if (integer < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();
    }

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
  
    yesNo = yes();

    if (yesNo == 1) 
    {
        printf("Please enter the contact's apartment number: ");
        integer = getInt();
        
        if (integer < 0)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
        } 
    }

    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]%*c", address->postalCode); 
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]%*c", address->city);
}
// clear


void getNumbers(struct Numbers* numbers)
{
    int yesNo;


    printf("Please enter the contact's cell phone number: ");
    scanf("%10[^\n]%*c", numbers->cell);


    printf("Do you want to enter a home phone number? (y or n): ");
    yesNo = yes();

    if (yesNo == 1)
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]%*c", numbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    yesNo = yes();

    if (yesNo == 1) 
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]%*c", numbers->business);
    }
}

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
