#include <stdio.h>

int main(void)
{
    int height, i = 2;
    do {
        printf("Height: ");
        scanf("%d", &height);
    }
    while (height < 0 || height > 23);

    while (i < height + 2)
    {
        for (int j = height + 2 - i; j > 0; j--)
	{
            printf(" ");
        }

        for (int p = i; p > 0; p--)
        {
            printf("#");
        }

        printf("\n");
 
        i++;
    }
}
