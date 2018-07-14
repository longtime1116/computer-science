// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = fraction[0] - 48;
    int denominator = fraction[2] - 48;
    return (8 / denominator) * numerator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int n = 0;
    switch (note[0])
    {
        case 'C':
        case 'D':
        case 'E':
            n = - (('A' + 7 - note[0]) * 2 - 1);
            break;
        case 'F':
        case 'G':
            n = - (('A' + 7 - note[0]) * 2);
            break;
        case 'A':
        case 'B':
            n = (note[0] - 'A') * 2;
            break;
        default:
            break;
    }

    switch (note[1])
    {
        case '#':
            n++;
            n += (note[2] - 48 - 4) * 12;
            break;
        case 'b':
            n--;
            n += (note[2] - 48 - 4) * 12;
            break;
        default:
            n += (note[1] - 48 - 4) * 12;
            break;
    }
    return round(pow(2, n / 12.0) * 440);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) != 0)
    {
        return false;
    }
    return true;
}
