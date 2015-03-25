/**
 * credit.c
 *
 * A. Vigano
 * viga90@gmail.com
 *
 * Prompts the user for a credit card number and then reports whether it is valid
 */

#include <stdio.h>
#include <math.h>
#include "cs50.h"

int main(int argc, char *argv[])
{
    long long number;
    int sizen = 0;
    int sum = 0;
    int i = 0;
    int j;
    int p;

    do
    {
        printf("Number: ");
        number = GetLongLong();
    }
    while (number <= 0);

    long long n = number;
    
    while (n > 0)
    {
	n /= 10;
	sizen += 1;
    }

    sizen -= 1;
    int size = sizen;
    int digits[size];
    int two_digits[size / 2];

    // convert the number in a list of digits
    for ( ; sizen >= 0; sizen--)
    {
	digits[sizen] = number % 10;
	number /= 10;
    }

    for (j = size - 1, p = 0; p <= (size/2); j -= 2, p++)
    {
        two_digits[p] = 2 * digits[j];
    }
    
    for (p = 0; p <= (size/2); p++)
    {
        if (two_digits[p] > 9)
	{
            int x = two_digits[p];
            while (x)
	    {
                sum += x % 10;
                x /= 10;
	    }
	}
        else
	{
            sum += two_digits[p];
	}
    }

    for (i = size; i >= 0; i -= 2)
    {
        sum += digits[i];
    }
    
    if (sum % 10 == 0)
    {
        if (digits[0] == 3 && (digits[1] == 4 || digits[1] == 7))
	{
            printf("AMEX\n");
	}
        else if (digits[0] == 4)
	{
            printf("VISA\n");
	}
        else if (digits[0] == 5 && (digits[1] == 1|| digits[1] == 2 || digits[1] == 3 || digits[1] == 4 || digits[1] == 5))
	{
            printf("MASTERCARD\n");
	}
        else
	{
            printf("INVALID\n");
	}
    }
    else
    {
        printf("INVALID\n");
    }

}
