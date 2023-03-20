#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[20], str2[20];

    printf("Enter the string:\n");
    gets(str2);

    printf("Enter the substring to be searched:\n");
    gets(str1);

    int opcount = 0;
    int m = strlen(str1); // To be searched
    int n = strlen(str2);
    int j;

    for (int i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            opcount++;
            if (str2[i + j] != str1[j])
            {
                break;
            }
        }

        if (j == m)
        {
            printf("String found at index %d.\n", i);
            printf("Opcount = %d\n", opcount);
            printf("M+N = %d\n", m + n);
            return 1;
        }
    }
    printf("String not found.\n");
    printf("Opcount = %d\n", opcount);
    printf("M+N = %d\n", m + n);
    return 0;
}