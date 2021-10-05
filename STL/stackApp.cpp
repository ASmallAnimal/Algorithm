//利用stack实现逆波兰数的求解

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    stack<int> S;
    int a, b, x;

    string s;

    while (cin >> s)
    {
        if (s[0] == '+')
        {
            a = S.top(), S.pop();
            b = S.top(), S.pop();
            S.push(a + b);
        }
        else if (s[0] == '-')
        {
            a = S.top(), S.pop();
            b = S.top(), S.pop();
            S.push(a - b);
        }
        else if (s[0] == '*')
        {
            a = S.top(), S.pop();
            b = S.top(), S.pop();
            S.push(a * b);
        }
        else if (s[1] == '/')
        {
            a = S.top(), S.pop();
            b = S.top(), S.pop();
            S.push(a / b);
        }
        else
            S.push(atoi(s.c_str()));
    }

    cout << S.top() << endl;

    return 0;
}
