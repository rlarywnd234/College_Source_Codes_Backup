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

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
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
    } 
    while (!(i == 'y' || i == 'Y' || i == 'N' || i == 'n') || line !='\n');
    if (line != '\n') { clearKeyboard();}
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