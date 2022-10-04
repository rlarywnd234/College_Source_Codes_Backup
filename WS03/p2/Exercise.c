/*==================================================

==================================================
Name   :KYOJUNG KIM
ID : kkim107
Email : kkim107@myseneca.ca
Section : IPC144 ZAA*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>//string.h includes strlen() which returns 

//the index of the null byte of the C string passed in as an argument

#define SZ 31
int main(void)

{

    char entered[] = "Programming Logic 101 Course";

    char result[SZ] = { 0 };

    int i;

    for (i = strlen(entered) - 1; i > -1; i--)

    {

        if (isdigit(entered[i]))

        {

            result[strlen(entered) - i] = 'n';

        }

        else if (isspace(entered[i]))

        {

            result[strlen(entered) - i] = 's';

        }

        else if (isupper(entered[i]))

        {

            result[strlen(entered) - i] = 'U';

        }

        else

        {

            result[strlen(entered) - i] = 'l';

        }

    }

    result[strlen(entered) + 1] = '\0';

    result[0] = 'l';

    printf("%s\n", result);

    return 0;

}