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

void clearKeyboard(void);
void pause(void);
int getInt(void);
int getIntInRange(int min, int max);
int yes(void);
int menu(void);
void contactManagerSystem(void);

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

// displayContactHeader
// put function prototype here:
void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int count);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact* contact);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact contacts[], int size);
// searchContacts:
// put function prototype here:

void searchContacts(const struct Contact contacts[], int size);

// addContact:
// put function prototype here:
void addContact(struct Contact contacts[], int size);

// updateContact:
// put function prototype here:
void updateContact(struct Contact contacts[], int size);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact contacts[], int size);
// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contacts[], int size);
void Dnumber(struct Numbers* discard_number);
void Daddress(struct Address* discard_address);
void Dname(struct Name* discard_name);
void switchContacts(struct Contact* contactN, struct Contact* contactS);