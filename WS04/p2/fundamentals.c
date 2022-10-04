#include"fundamentals.h"
#include "stdio.h"


void fundamentals()
{
	printf("*** Start of Indexing Strings Demo ***\n");
	char buffer1[80]; // array for string 
	char num_input[10]; // array for user input
	int position; // charater position which it  will be determined by a user

	while (TRUE)
	{
		printf("Type a string (q - to quit):\n");
		gets(buffer1); // prompt get user input to bufferl
		if (strcmp(buffer1, "q") == 0) break; // sorting user input
		while (TRUE)
		{
			printf("Type the character position within the string:\n");
			gets(num_input); // get charater position input from user.
			position = atoi(num_input); // if you type 3, choosen charater position would be 3 
			if (position >= strlen(buffer1))// vaildation for input variable 
			{
				printf("Wrong position... type again, please\n");
				continue;
			}
			printf("The Character found at %d position is \'%c\'\n", position, buffer1[position]); //print out user selection and exit.
			break;
		}
	}
	printf("*** Strat of Measuring Strings Demo ***\n"); //measuring function start
	char buffer2[80]; //array for Measuring string 
	while (TRUE)
	{
		printf("Type a string (q - to quit) : \n"); 
		gets(buffer2); //prompt to get user input for string 
		if (strcmp(buffer2, "q") == 0) break; // "q" for break while loop, if user type "q", exit from measuring function
		printf("The lenth is %lu\n", strlen(buffer2)); //show the length of typed string
	}
	printf("*** End of Measureing Strings Demo ***\n\n"); 

	printf("*** Start of Copying String Demo ***\n");
	char destination[80];
	char source[80];
	while (TRUE)
	{
		destination[0] = '\0';
		printf("Destination string is reset to empty\n");
		printf("Type a source string (q - to quit);\n");
		gets(source);// prompt put user input to source(origin)
		if (strcmp(source, "q") == 0) // if user typed "q", this will shut down the program.
		{
			break;
		}
		strcpy(destination, source); //copy from source string, and paste it into destination.
		printf("New destination string is \'%s\':\n", destination); // destination string set up
	}
	printf("*** End of Copying String Demo ***\n\n"); // function exit message 

}



int main()
{
	fundamentals();
	return 0;
}
