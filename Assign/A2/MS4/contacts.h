/* -------------------------------------------
Name:KYO JUNG KIM
Student number:132625161
Email:kkim107@myseneca.ca
Section:IPC144ZAA
Date:2021-07-27
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */
struct Name 
{
    char firstName[31];
    char middleInitial[30]; 
    char lastName[36];
};
// Structure type Address declaration (Milestone 1)..
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
    char cell[30];
    char home[30];
    char business[30];
};
// Structure type Contact declaration (Milestone 3)
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};
// Function Prototypes
//------------------------------------------------------
// ====== Milestone 4 =======
// Get and store from standard input the values for Name

void getName(struct Name*);
// Get and store from standard input the values for Address

void getAddress(struct Address*);
// Get and store from standard input the values for Numbers

void getNumbers(struct Numbers*);
void getContact(struct Contact* contact);
