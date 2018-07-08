#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int change, rest;
    int quarter_count, dime_count, nickel_count, penny_count;

    change = round(get_float("Change owed: ") * 100);

    quarter_count = change / 25;
    rest = change % 25;

    dime_count = rest / 10;
    rest %= 10;

    nickel_count = rest / 5;
    rest %= 5;

    penny_count = rest;

    printf("%i\n", quarter_count + dime_count + nickel_count + penny_count);
}
