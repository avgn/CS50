/**
 * baseChange.c
 * 
 * A. Vigano
 * viga90@gmail.com
 *
 * Converts a positive integer to another base
 */

#include <stdio.h>

int convertedNumber[64];
long int n;
int base;
int digit = 0;

void getNumberAndBase (void);
void convertNumber (void);
void displayConvertedNumber(void);

int main (int argc, char *argv[ ])
{
  getNumberAndBase();
  convertNumber();
  displayConvertedNumber();
}


void getNumberAndBase (void)
{
  printf("Number to be converted? ");
  scanf("%li", &n);
  
  do
  {
    printf("Base? (must be between 2 and 16): ");
    scanf("%i", &base);
  }
  while (base < 2 || base > 16);
}

void convertNumber (void)
{
  do
  {
    convertedNumber[digit] = n % base;
    digit++;
    n /= base;
  }
  while (n != 0);
}

void displayConvertedNumber (void)
{
  const char baseDigits[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  int nextDigit;

  printf("Converted number = ");

  for (digit--; digit >= 0; digit--)
  {
    nextDigit = convertedNumber[digit];
    printf("%c", baseDigits[nextDigit]);
  }

  printf("\n");
}
