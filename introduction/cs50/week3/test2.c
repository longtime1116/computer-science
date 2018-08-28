#include <stdio.h>
#include <string.h>

int main(void)
{
    int hoge[4] = {10, 20, 30, 40};
    int *geho = hoge;

    for (int i = 0, n = 4; i < n; i++)
    {
        printf("============\n");
        printf("%p\n", (hoge + i));
        printf("%i\n", *(hoge + i));
        printf("------------\n");
        printf("%p\n", geho);
        printf("%i\n", *geho);
        geho++;
        printf("============\n");
    }
}
