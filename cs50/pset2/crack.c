#define _XOPEN_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>

# define LIST "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

int check_by_crypt(char *str1, char *str2);
int check(char *str1, char *str2);

int main(int argc, char *argv[])
{
    int i, j, k, l, m, n;
    char pass[6] = {0};

    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    for (i = 0, n = strlen(LIST); i < n; i++)
    {
        pass[0] = LIST[i];
        pass[1] = '\0';
        if (check_by_crypt(argv[1], pass) == 0)
        {
            goto SUCCESS;
        }
        for (j = 0; j < n; j++)
        {
            pass[1] = LIST[j];
            pass[2] = '\0';
            if (check_by_crypt(argv[1], pass) == 0)
            {
                goto SUCCESS;
            }
            for (k = 0; k < n; k++)
            {
                pass[2] = LIST[k];
                pass[3] = '\0';
                if (check_by_crypt(argv[1], pass) == 0)
                {
                    goto SUCCESS;
                }
                for (l = 0; l < n; l++)
                {
                    pass[3] = LIST[l];
                    pass[4] = '\0';
                    if (check_by_crypt(argv[1], pass) == 0)
                    {
                        goto SUCCESS;
                    }
                    for (m = 0; m < n; m++)
                    {
                        pass[4] = LIST[m];
                        pass[5] = '\0';
                        if (check_by_crypt(argv[1], pass) == 0)
                        {
                            goto SUCCESS;
                        }
                    }
                }
            }
        }
    }

    return 1;

SUCCESS:
    printf("%s\n", pass);
    return 0;
}

int check_by_crypt(char *str1, char *str2)
{
    int i, j, n;
    char salt[3] = {0};

    for (i = 0, n = strlen(LIST); i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            salt[0] = LIST[i];
            salt[1] = LIST[j];
            if (check(str1, crypt(str2, salt)) == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int check(char *str1, char *str2)
{
    int length = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);

    for (int i = 0; i < length; i++)
    {
        if (str1[i] != str2[i])
        {
            return 1;
        }
    }
    return 0;
}
