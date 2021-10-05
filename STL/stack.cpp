#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> S;

    S.push(3);
    S.push(7);
    S.push(1);

    cout << "size of S is " << S.size() << endl;
    cout << "top of S is " << S.top() << endl;

    S.pop();

    cout << "after 1st pop, the top of S is " << S.top() << endl;

    S.pop();

    cout << "after 2nd pop, the top of S is " << S.top() << endl;

    S.push(5);

    cout << "after push one element, the top of S is " << S.top() << endl;

    S.pop();

    cout << "after 3rd pop, the top of S is " << S.top() << endl;

    cout << "at the moment, is S empty? " << S.empty() << endl;

    return 0;
}
