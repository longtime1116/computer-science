//#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define N(c) c - '0'

bool check_by_luhn(char *str);
bool is_amex(char *str);
bool is_mastercard(char *str);
bool is_visa(char *str);

int main(void)
{
    // long long number = get_long_long("Number: ");
    long long number = 378282246310005;
    char str[256];
    char *card_type;

    snprintf(str, sizeof(str), "%lld", number);

    if (is_amex(str))
    {
        card_type = "AMEX";
    }
    else if (is_mastercard(str))
    {
        card_type = "MASTERCARD";
    }
    else if (is_visa(str))
    {
        card_type = "VISA";
    }
    else
    {
        card_type = "INVALID";
    }

    printf("%s\n", card_type);
    return 0;
}

bool check_by_luhn(char *s)
{
    int sum_1 = 0;
    int sum_2 = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        int n = N(s[i]);
        if ((strlen(s) % 2 == 0 && i % 2 == 0) ||
            (strlen(s) % 2 == 1 && i % 2 == 1))
        {
            if (n * 2 > 9)
            {
                sum_1 += n * 2 / 10;
                sum_1 += n * 2 % 10;
            }
            else
            {
                sum_1 += n * 2;
            }
        }
        else
        {
            sum_2 += n;
        }
    }
    return (sum_1 + sum_2) % 10 == 0 ? true : false;
}

bool is_amex(char *str)
{
    if (!(str[0] == '3' &&
          (str[1] == '4' || str[1] == '7')))
    {
        return false;
    }

    if (strlen(str) != 15)
    {
        return false;
    }

    return check_by_luhn(str);
}

bool is_mastercard(char *str)
{
    if (!(str[0] == '5' &&
          (str[1] == '1' || str[1] == '2' ||
           str[1] == '3' || str[1] == '4' ||
           str[1] == '5')))
    {
        return false;
    }

    if (strlen(str) != 16)
    {
        return false;
    }

    return check_by_luhn(str);
}

bool is_visa(char *str)
{
    int len = strlen(str);

    if (str[0] != '4')
    {
        return false;
    }

    if (len != 13 && len != 16)
    {
        return false;
    }

    return check_by_luhn(str);
}
