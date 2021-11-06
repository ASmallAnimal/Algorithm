#include <stdio.h>
#include <string.h>

int judge(char c[], int f1, int l)
{
    int s[100] = {0}, h, p, f[5] = {1}, i;
    for (i = 1; i < 5; i++)
        f[i] = f[i - 1] * 2;
    for (i = 0; i < 5; i++)
    {
        f[i] = f[i] & f1;
        if (f[i] > 0)
            f[i] = 1;
    }
    p = l - 1;
    h = 0;
    while (p >= 0)
    {
        switch (c[p])
        {
        case 'p':
            s[h] = f[0];
            h++;
            break;
        case 'q':
            s[h] = f[1];
            h++;
            break;
        case 'r':
            s[h] = f[2];
            h++;
            break;
        case 's':
            s[h] = f[3];
            h++;
            break;
        case 't':
            s[h] = f[4];
            h++;
            break;
        case 'K':
            h = h - 2;
            if (s[h] == 1 && s[h + 1] == 1)
                h++;
            else
            {
                s[h] = 0;
                h++;
            }
            break;
        case 'A':
            h = h - 2;
            if (s[h] == 0 && s[h + 1] == 0)
                h++;
            else
            {
                s[h] = 1;
                h++;
            }
            break;
        case 'N':
            h = h - 1;
            if (s[h] == 0)
                s[h] = 1;
            else
                s[h] = 0;
            h++;
            break;
        case 'C':
            h = h - 2;
            if (s[h] == 0 && s[h + 1] == 1)
                h++;
            else
            {
                s[h] = 1;
                h++;
            }
            break;
        case 'E':
            h = h - 2;
            if (s[h] == s[h + 1])
                s[h] = 1;
            else
                s[h] = 0;
            h++;
            break;
        }
        p--;
    }
    return s[0];
}

int main()
{
    char c[100];
    int i, l;
    scanf("%s", c);
    while (strcmp(c, "0") != 0)
    {
        l = strlen(c);
        for (i = 0; i < 32; i++)
            if (!judge(c, i, l))
            {
                printf("not\n");
                break;
            }
        if (i == 32)
            printf("tautology\n");
        scanf("%s", c);
    }
    return 0;
}