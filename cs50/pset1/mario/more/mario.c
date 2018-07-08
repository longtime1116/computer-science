#include <cs50.h>
#include <stdio.h>

void dump_char(int length, char c);

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
        dump_char(height - (i + 1), ' ');
        dump_char(i + 1, '#');
        dump_char(2, ' ');
        dump_char(i + 1, '#');
        printf("\n");
    }
}

void dump_char(int length, char c)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", c);
    }
}
