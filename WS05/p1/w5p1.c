/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   :KYOJUNG KIM
	ID     :kkim107
	Email  :kkim107@myseneca.ca
	Section:IPC144ZAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXSIZE 8 // output is 8 lines, should be 8

struct Record

{
    int id;
    char firstName[31];
    char lastName[31];
    char cellPhone[11];
};


int main(void)

{
    struct Record record[MAXSIZE];
    int numberOfRecords = 0;
    FILE* fp = NULL;
    int i = 0;
  
 fp = fopen ("myData.txt", "r"); // open file in read mode not in write mode

 if (fp != NULL)
{
     while(i < MAXSIZE && fscanf(fp, "%s %s %s", record[i].firstName, record[i].lastName, record[i].cellPhone) != EOF)//if i<MAXSIZE > out of array range
  {
    record[i].id = i + 1;
    numberOfRecords++;
    i++;      
   }
}

 fp = fopen("myData.txt", "w"); //append > write

 if (fp != NULL)
{
     for (i = 0; i < numberOfRecords; i++)
     {
         fprintf(fp, "%d %s %s %s\n", record[i].id, record[i].firstName, record[i].lastName, record[i].cellPhone);//Enter between variables
     }
  }
 fclose(fp); // closing file
 return 0;
}



