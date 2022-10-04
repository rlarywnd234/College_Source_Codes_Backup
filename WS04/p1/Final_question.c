/*
==================================================
Final Question 
==================================================
Name   :KYOJUNG KIM
ID     :kkim107
Email  :kkim107@myseneca.ca
Section:IPC144ZAA
(not a grpup, and file only one*/ 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20
#define MAX_ACTIVITY_NAME_LEN 15
#define NUM_ACTIVITY_NAMES 3

struct Participant
{
    int numActivities;
    char name[MAX_NAME_LEN + 1];
    struct Activity activities[10];
};

struct Activity 
{
    int activityType;
    struct Date date;
    double distance;
};

struct Date
{
    int year;
    int month;
    int day;
};




int zeller(const struct Date* date)
{
    int month = date->month;
    int year = date->year;
    if (date->month < 3)
    {
        year--;
        month += 12;
    }

    int yr = year % 100;
    int century = year / 100;
    int result = date->day;
    result += 13 * (month + 1) / 5;
    result += yr;
    result += yr / 4;
    result += century / 4;
    result -= 2 * century;
    result = result % 7;
    return result;
}

int findParticipant(struct Participant participants[], int count, char name[])
{
    int i = 0;

    while (i < count)
    {
        if (strcmp(participants[i].name, name) == 0)
            return i;
             i++;
    }
    return -1;
}

int findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int num, char activity[])
{
    int i = 0;
    while (i < num)
    {
        if (strcmp(activNames[i], activity) == 0)
            return i;
        i++;
    }
    return -1;
}

void sort(double sortedAct[], char sortedname[][MAX_NAME_LEN + 1], int rec)
{
    double t;
    char s[MAX_NAME_LEN + 1];

    for (int c = 0; c < rec - 1; c++)
    {
        for (int d = 0; d < rec - c - 1; d++)
        {
            if (sortedAct[d] < sortedAct[d + 1])
            {
                t = sortedAct[d];
                sortedAct[d] = sortedAct[d + 1];
                sortedAct[d + 1] = t;

                strcpy(s, sortedname[d]);
                strcpy(sortedname[d], sortedname[d + 1]);
                strcpy(sortedname[d + 1], s);
            }
        }
    }
}

int readActivityFile(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1])
{

    int count = 0, ch, addPerson, actPerson; // addposn , actposn changed
    char activity[16];
    char name[MAX_NAME_LEN + 1];
    int year = 0, month = 0, day = 0;
    double dist = 0.0;
    while (!feof(fp))
    {
        fscanf(fp, "%[^~]s%*c", name);
        ch = fgetc(fp);
        fscanf(fp, "%[^~]s%*c", activity);
        ch = fgetc(fp);
        fscanf(fp, "%d", &year);
        ch = fgetc(fp);
        fscanf(fp, "%d", &month);
        ch = fgetc(fp);
        fscanf(fp, "%d", &day);
        ch = fgetc(fp);
        fscanf(fp, "%lf", &dist);
        ch = fgetc(fp);

        addPerson = findParticipant(participants, count, name);

        if (addPerson < 0)
        {
            addPerson = count;
            count++;
            participants[addPerson].numActivities = 0;
            strcpy(participants[addPerson].name, name);
        }

        actPerson = participants[addPerson].numActivities;
        participants[addPerson].activities[actPerson].activityType = findString(activNames, NUM_ACTIVITY_NAMES, activity);
        participants[addPerson].activities[actPerson].date.year = year;
        participants[addPerson].activities[actPerson].date.month = month;
        participants[addPerson].activities[actPerson].date.day = day;
        participants[addPerson].activities[actPerson].distance = dist;
        participants[addPerson].numActivities++;

        ch = fgetc(fp);
        if (!feof(fp)) ungetc(ch, fp);
    }
    return count;
}



int main()
{
    
  
    FILE* fp;
    struct Participant participants[10];
    
    int selection = 1;
    int personNum = 0;
    double sortedAct[100];
    char sortedname[100][MAX_NAME_LEN + 1];
    char activNames[NUM_ACTIVITY_NAMES][MAX_ACTIVITY_NAME_LEN + 1] = { {'r','u','n','\0'}, {'s','w','i','m','\0'}, {'b','i','k','e','\0'}};
    char* Day[] = { "Sat","Sun","Mon","Tue","Wed","Thu","Fri" };
    char* Month[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
     printf("Error opening file data.txt!");
     exit(1);
    }
    personNum = readActivityFile(fp, participants, activNames);
   

    
    printf("Read %d participants\n", personNum);
    while (1)
    {
        if ((selection > 0) && (selection < 8))//entering menu
        {
            printf("\nSelect one of the following options:\n");
            printf("0 - Exit \n");
            printf("1 - list all participants and events \n");
            printf("2 - list total run distances \n");
            printf("3 - list total swim distances \n");
            printf("4 - list total bike distances \n");
            printf("5 - list best run distances \n");
            printf("6 - list best swim distances \n");
            printf("7 - list best bike distances \n");
        }
        scanf("%d", &selection);

        switch (selection)
        {
        case 0: //exit
            printf("Goodbye\n");
            fclose(fp);
            exit(0);

        case 1: //listing
              for (int i = 0; i < personNum; i++)
            {
                printf("%s\n", participants[i].name);
                printf("----------------------------------------------\n");
                for (int j = 0; j < participants[i].numActivities; j++)
                {
                    printf("%s ", activNames[participants[i].activities[j].activityType]);
                    printf("%s ", Day[zeller(&participants[i].activities[j].date)]);
                    printf("%s ", Month[participants[i].activities[j].date.month - 1]);
                    printf("%d ", participants[i].activities[j].date.day);
                    printf("%.1f", participants[i].activities[j].distance);
                    printf("\n");
                }
                printf("\n");
            }
            break;

        case 2: //total run
            printf("  *** TOTAL RUNS ***\n");
            for (int i = 0; i < personNum; i++)
            {
                strcpy(sortedname[i], participants[i].name);
                double sum = 0;
                for (int j = 0; j < participants[i].numActivities; j++)
                {
                    if (participants[i].activities[j].activityType == 0)
                        sum = sum + participants[i].activities[j].distance;
                }
                sortedAct[i] = sum;
            }
            
            sort(sortedAct, sortedname, personNum); //
            for (int i = 0; i < personNum; i++)
            {printf("%s %.1f\n", sortedname[i], sortedAct[i]);}
            break; 

        case 3: //totla swims
            printf("  *** TOTAL SWIMS ***\n");
            for (int i = 0; i < personNum; i++)
            {
                strcpy(sortedname[i], participants[i].name);
                double sum = 0;
                for (int j = 0; j < participants[i].numActivities; j++)
                {
                    if (participants[i].activities[j].activityType == 1)
                        sum = sum + participants[i].activities[j].distance;
                }
                sortedAct[i] = sum;
            }

            sort(sortedAct, sortedname, personNum);  // 
            for (int i = 0; i < personNum; i++)
            {printf("%s %.1f\n", sortedname[i], sortedAct[i]);}
            break; //

        case 4: //total bike
            printf("  *** TOTAL BIKES ***\n");
            for (int i = 0; i < personNum; i++)
            {
                strcpy(sortedname[i], participants[i].name);
                double sum = 0;
                for (int j = 0; j < participants[i].numActivities; j++)
                {
                    if (participants[i].activities[j].activityType == 2)
                        sum = sum + participants[i].activities[j].distance;
                }
                sortedAct[i] = sum;
            }

            sort(sortedAct, sortedname, personNum); //
            for (int i = 0; i < personNum; i++)
            {printf("%s %.1f\n", sortedname[i], sortedAct[i]);}
            break; 

        case 5: // total run
            printf("  *** TOP RUNS ***\n");
            for (int i = 0; i < personNum; i++)
            {
                strcpy(sortedname[i], participants[i].name);
                double top = 0;
                for (int j = 0; j < participants[i].numActivities; j++)
                {
                    if (participants[i].activities[j].activityType == 0)
                    {
                        if (top < participants[i].activities[j].distance)
                            top = participants[i].activities[j].distance;
                    }

                }
                sortedAct[i] = top;
            }

            sort(sortedAct, sortedname, personNum);   //
            for (int i = 0; i < personNum; i++)
            {printf("%s %.1f\n", sortedname[i], sortedAct[i]);}
            break;

        case 6: // toatal swims
            printf("  *** TOP SWIMS ***\n");
            for (int i = 0; i < personNum; i++)
            {
                strcpy(sortedname[i], participants[i].name);
                double top = 0;
                for (int j = 0; j < participants[i].numActivities; j++)
                {
                    if (participants[i].activities[j].activityType == 1)
                    {
                        if (top < participants[i].activities[j].distance)
                            top = participants[i].activities[j].distance;
                    }

                }
                sortedAct[i] = top;
            }
            
            sort(sortedAct, sortedname, personNum);   //
            for (int i = 0; i < personNum; i++)
            {printf("%s %.1f\n", sortedname[i], sortedAct[i]);}
            break;

        case 7: // total bikes
            printf("  *** TOP BIKES ***\n");
            for (int i = 0; i < personNum; i++)
            {
                strcpy(sortedname[i], participants[i].name);
                double top = 0;
                for (int j = 0; j < participants[i].numActivities; j++)
                {
                    if (participants[i].activities[j].activityType == 2)
                    {
                        if (top < participants[i].activities[j].distance)
                            top = participants[i].activities[j].distance;
                    }

                }
                sortedAct[i] = top;
            }
           
            sort(sortedAct, sortedname, personNum);   // 
            for (int i = 0; i < personNum; i++)
            {printf("%s %.1f\n", sortedname[i], sortedAct[i]);} 
            break;

        default:
            printf("Enter a number between 0 and 7: ");
            break;
        }
    }
}

