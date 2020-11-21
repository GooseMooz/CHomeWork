#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    char a[MAX];
    int numa[MAX];
    gets(a);
    char b[MAX];
    int numb[MAX];
    gets(b);
    int lenNUMA = 0;
    int lenNUMB = 0;
    int lenghtSTRA = strlen(a);
    int lenghtSTRB = strlen(b);
    int tmp;
    int noSwap;

    if(lenghtSTRA != lenghtSTRB){
        printf("N O");
        return 0;
    }

    for (int i = 0; i < MAX; i++)
    {
        numa[i] = 0;
        numb[i] = 0;
    }

    for (int i = 0; a[i] != '\0' && a[i] != '\n'; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            numa[i] = (a[i] - 'a' + '0');
            lenNUMA++;
        }
        else if (a[i] >= 'A' && a[i] <= 'Z')
        {
            numa[i] = (a[i] - 'A' + '0');
            lenNUMA++;
        }
    }

    for (int i = 0; b[i] != '\0' && b[i] != '\n'; i++)
    {
        if (b[i] >= 'a' && b[i] <= 'z')
        {
            numb[i] = (b[i] - 'a' + '0');
            lenNUMB++;
        }
        else if (b[i] >= 'A' && b[i] <= 'Z')
        {
            numb[i] = (b[i] - 'A' + '0');
            lenNUMB++;
        }
    }

    for (int i = lenNUMA - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (numa[j] > numa[j + 1])
            {
                tmp = numa[j];
                numa[j] = numa[j + 1];
                numa[j + 1] = tmp;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }

    for (int i = lenNUMB - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (numb[j] > numb[j + 1])
            {
                tmp = numb[j];
                numb[j] = numb[j + 1];
                numb[j + 1] = tmp;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }

    for (int i = 0; i < lenNUMA; i++)
    {
        if (numa[i] != numb[i])
        {
            printf("N O");
            return 0;
        }
    }
    printf("Y E S");
    return 0;
}