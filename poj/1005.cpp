#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    double x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        double l = sqrt(x * x + y * y);
        double deta_s = M_PI * pow(l, 2) / 2;
        int year = ceil(deta_s / 50);
        printf("Property %d: This property will begin eroding in year %d.\n",i+1,year);
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}