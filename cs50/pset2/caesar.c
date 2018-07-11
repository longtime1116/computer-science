#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // k が 26 以下の整数？
    int shift_amount = strtol(argv[1], NULL, 10) % 26;
    // printf("%i", shift_amount);

    string plain = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        char from = plain[i];
        char to;

        if (from >= 'A' && from <= 'Z')
        {
            to = ((from - 'A') + shift_amount) % 26 + 'A';
        }
        else if (from >= 'a' && from <= 'z')
        {
            to = ((from - 'a') + shift_amount) % 26 + 'a';
        }
        else
        {
            to = from;
        }
        printf("%c", to);
    }
    printf("\n");
}
