#define USER 30
typedef struct phone
{
	char name[USER];
	long long int callNumber;
	double callDuration;
	int dataBytes;
	double screenTime;
}
phone; phone sorted[3];
phone original[10] = { 0 };
void readData();
void menuheader();
void menu();
void menuOption1();
void menuOption2();
void menuOption3();
void menuOption4();
void addingdata();
void sortingnames();
#pragma once