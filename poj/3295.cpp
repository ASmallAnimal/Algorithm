#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstring>
#include <stack>

using namespace std;

bool judge(char s[]);

int main()
{
    char s[100];
    cin >> s;
    while (strcmp(s, "0") != 0)
    {
        bool flag = judge(s);
        if (flag == true)
            cout << "tautology" << endl;
        else
            cout << "not" << endl;
        cin >> s;
    }
    return 0;
}

bool judge(char s[])
{
    int l = strlen(s);
    for (int i = 0; i < 32; i++)
    {
        stack<int> S;
        int p = l - 1;
        int a, b;
        int f[5] = {1, 2, 4, 8, 16};
        for (int j = 0; j < 5; j++)
        {
            f[j] = f[j] & i;
            if (f[j] > 0)
                f[j] = 1;
        }
        while (p >= 0)
        {
            switch (s[p])
            {
            case 'p':
                S.push(f[0]);
                break;
            case 'q':
                S.push(f[1]);
                break;
            case 'r':
                S.push(f[2]);
                break;
            case 's':
                S.push(f[3]);
                break;
            case 't':
                S.push(f[4]);
                break;
            case 'K':
                a = S.top(); S.pop();
                b = S.top(); S.pop();
                if (a == 1 && b == 1)
                    S.push(1);
                else
                    S.push(0);
                break;
            case 'A':
                a = S.top(); S.pop();
                b = S.top(); S.pop();
                if (a == 1 || b == 1)
                    S.push(1);
                else
                    S.push(0);
                break;
            case 'N':
                a = S.top(); S.pop();
                if (a == 0)
                    S.push(1);
                else
                    S.push(0);
                break;
            case 'C':
                a = S.top(); S.pop();
                b = S.top(); S.pop();
                if (a == 0 && b == 1)
                   S.push(0);
                else
                    S.push(1);
                break;
            case 'E':
                a = S.top(); S.pop();
                b = S.top(); S.pop();
                if (a == b)
                    S.push(1);
                else
                    S.push(0);
                break;
            }
            p--;
        }
        if (!S.top())
            return false;
    }
    return true;
}