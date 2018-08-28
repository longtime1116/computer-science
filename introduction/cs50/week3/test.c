#include <stdio.h>
#include <string.h>

int main(void)
{
    char foo[256] = "FOO";
    char bar[256] = "BARBAR";


    printf("foo: %s\n", foo);
    printf("bar: %s\n", bar);

    for (int i = 0, n = strlen(foo); i < n; i++)
    {
        bar[i] = foo[i];
    }

    printf("bar: %s\n", bar);
    printf("strlen: %lu\n", strlen(bar));

    for (int i = 0, n = strlen(foo) + 1; i < n; i++)
    {
        bar[i] = foo[i];
    }

    printf("bar: %s\n", bar);
    printf("strlen: %lu\n", strlen(bar));
}
