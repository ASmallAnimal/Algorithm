#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

//cpu流水处理
int main()
{
    int n, q, t;
    string name;

    queue<pair<string, int>> Q;  //pair是保存成对数值的结构体模板2

    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> t;
        Q.push(make_pair(name, t));
    }

    pair<string, int> u;
    int elaps = 0, a;

    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        a = min(u.second, q);
        u.second -= a;
        elaps += a;
        if (u.second > 0)
        {
            Q.push(u);
        }
        else
        {
            cout << u.first << " " << elaps << endl;
        }
    }
    return 0;
}