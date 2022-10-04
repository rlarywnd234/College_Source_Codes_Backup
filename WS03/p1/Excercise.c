#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "function.h"
int main()
{
	readData();
	menu();
}
void readData()
{
	int i = 0;
	const char filename[] = "phoneln.txt";
	FILE* fp = fopen(filename, "r");
	if (fp != NULL)
	{
		while (i < 10 && fscanf(fp, "%[^|]|%lld|%lf|%d|%lf\n",
			original[i].name, &original[i].callNumber, &original[i].callDuration,
			&original[i].dataBytes, &original[i].screenTime) == 5)

		{
		i++;
		}
		fclose(fp);
	}
}
void menuheader()
{
	printf("Select one of the following options:\n");
	printf("0 - Exit\n1 - Show name by call duration\n2 - Show name by data 
		usage\n3 - Show name by screen time\n4 - Show all user data\n");
}
void menu()
{
	sortingnames();
	addingdata();
	int selection = -3;
	do
	{
		sortingnames();
		menuheader();
		scanf("%d", &selection);
		if (selection == 1)
		{
			menuOption1();
		}
		else if (selection == 2)
		{
			menuOption2();
		}
		else if (selection == 3)
		{
			menuOption3();
		}
		else if (selection == 4)
		{
			menuOption4();
		}
		else if (selection == 0)
		{
			printf("\nGoodbye\n");
		}
		else
		{
			printf("Select from 0 - 4 only\n");
		}
	} while (selection != 0);
}
void sortingnames()
{
	int i, j, k = 0, m = 0;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (strcmp(original[i].name, sorted[j].name) == 0 && j != i)
			{
				i++;
				k = 2;
	
			}
			else
				k = 0;
		}
		if (k == 0)
		{
			strcpy(sorted[m].name, original[i].name);
			m++;
		}
		else
			i++;
	}
}
void addingdata()
{
	int i = 0, j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = i; j < 7; j++)
		{
			if (strcmp(sorted[i].name, original[j].name) == 0)
			{
				sorted[i].callDuration = sorted[i].callDuration +
					original[j].callDuration;
				sorted[i].screenTime = sorted[i].screenTime +
					original[j].screenTime;
				sorted[i].dataBytes = sorted[i].dataBytes +
					original[j].dataBytes;
			}
		}
	}
}
void menuOption1()
{
	double minimum;
	char minimumuser[30];
	int i = 0, j = 0;
	printf(" User Call Duration\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < (3 - i); j++)
		{
			if (sorted[j].callDuration > sorted[j + 1].callDuration)
			{
				minimum = sorted[j].callDuration;
				strcpy(minimumuser, sorted[j].name);
				sorted[j].callDuration = sorted[j + 1].callDuration;
				strcpy(sorted[j].name, sorted[j + 1].name);
				sorted[j + 1].callDuration = minimum;
				strcpy(sorted[j + 1].name, minimumuser);
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		int totalsec = (sorted[i].callDuration + 0.01) * 60;
		int min = totalsec / 60;
		int sec = (totalsec) % 60;
		printf(" %s %02d:%02d\n",
			sorted[i].name, min, sec);
	}

		printf("\n");
}
void menuOption2()
{
	int minimum = 0;
	char minimumuser[30];
	int i = 0, j = 0;
	printf(" User Data Usage\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < (3 - i); j++)
		{
			if (sorted[j].dataBytes > sorted[j + 1].dataBytes)
			{
				minimum = sorted[j].dataBytes;
				strcpy(minimumuser, sorted[j].name);
				sorted[j].dataBytes = sorted[j + 1].dataBytes;
				strcpy(sorted[j].name, sorted[j + 1].name);
				sorted[j + 1].dataBytes = minimum;
				strcpy(sorted[j + 1].name, minimumuser);
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		printf(" %s %5d\n", sorted[i].name,
			sorted[i].dataBytes);
	}
	printf("\n");
}
void menuOption3()
{
	double minimum = 0;
	char minimumuser[30];
	int i = 0, j = 0;
	printf(" User Screen Time\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < (3 - i); j++)
		{
			if (sorted[j].screenTime > sorted[j + 1].screenTime)
			{
				minimum = sorted[j].screenTime;
				strcpy(minimumuser, sorted[j].name);
				sorted[j].screenTime = sorted[j + 1].screenTime;
				strcpy(sorted[j].name, sorted[j + 1].name);
				sorted[j + 1].screenTime = minimum;
				strcpy(sorted[j + 1].name, minimumuser);
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		int totalsec = (sorted[i].screenTime + 0.01) * 60;
		int min = totalsec / 60;
		int sec = (totalsec) % 60;
		printf(" %s %3d:%02d\n",
			sorted[i].name, min, sec);
	}
	printf("\n");
}

	void menuOption4()
{
	int i = 0, j = 0, m = 0, k = 0, l = 0;
	for (i = 0; i < 4; i++)
	{
		printf("---------------------------------------------\nUser: %s\n",
			sorted[i].name);
		printf(" Number Called Duration\n");
		for (j = 0; j < 7; j++)
		{
			if (strcmp(sorted[i].name, original[j].name) == 0 &&
				original[j].callNumber > 0)
			{
				int totalsec = (original[j].callDuration + 0.01) * 60;
				int min = totalsec / 60;
				int sec = (totalsec) % 60;
				printf(" %lld %2d:%02d\n",
					original[j].callNumber, min, sec);
			}
		}
		if (original[i].dataBytes > 0)
		{
			printf("dataBytes Transferred\n");
			for (j = 0; j < 7; j++)
			{
				if (strcmp(sorted[i].name, original[j].name) == 0 &&
					original[j].dataBytes > 0)
				{
					printf(" %17d\n", original[j].dataBytes);
				}
			}
		}
		printf("Screen Minutes\n");
		for (j = 0; j < 7; j++)
		{
			if (strcmp(sorted[i].name, original[j].name) == 0 &&
				original[j].screenTime > 0)
			{
				int totalsec = (original[j].screenTime + 0.01) * 60;
				int min = totalsec / 60;
				int sec = (totalsec) % 60;
				printf(" %11d:%02d\n", min, sec);
			}
		}
	}
	printf("\n");
}