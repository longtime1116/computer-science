#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    while (true)
    {
        height = get_int("Height: ");
        if (height >= 0 && height < 24)
        {
            break;
        }
    }

    for (int i = 0; i < height; i++)
    {
        int space_length = height - (i + 1);
        for (int j = 0; j < space_length; j++)
        {
            printf(" ");
        }

        int hash_length = i + 2;
        for (int k = 0; k < hash_length; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
