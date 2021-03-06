/**
 * vigenere.c
 * 
 * A. Vigano
 * viga90@gmail.com
 *
 * Encrypts messages using the Vigenere's cipher algorithm. It takes one argument, a keyword,
 * for the number of positions for the rotation of each letter.
 */

#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>

void vigenere(string str, string k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You need to supply one argument for this program.\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
	{
	    printf("The argument has to be a keyword composed entirely of alphabetical characters.\n");
            return 1;
	}
    }

    string s = GetString();
    vigenere(s, argv[1]);

}

void vigenere(string str, string k)
{
    int keylen = strlen(k);
    for (int i = 0, n = strlen(str), j = 0; i < n; i++)
    {
        if (isalpha(str[i]))
	{    
            if (islower(str[i]) && islower(k[j % keylen]))
                printf("%c", ((int) str[i] - 'a' + ((int) k[j % keylen] - 'a')) % 26 + 'a');
            else if(islower(str[i]) && isupper(k[j % keylen]))
                printf("%c", ((int) str[i] - 'a' + ((int) k[j % keylen] - 'A')) % 26 + 'a');
            else if(isupper(str[i]) && islower(k[j % keylen]))
	        printf("%c", ((int) str[i] - 'A' + ((int) k[j % keylen] - 'a')) % 26 + 'A');
            else
	        printf("%c", ((int) str[i] - 'A' + ((int) k[j % keylen] - 'A')) % 26 + 'A');
            j++;
	}
        else
	    printf("%c", str[i]);
    }

    printf("\n");

}
