#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXN 100
int a[MAXN];
int counts = 0;
int f = -1;

bool test(int square[][4]);
int comb(int m, int k, int square[4][4]);

int main()
{
    //case 1
    int square[4][4];
    char element;
    bool flag;
    for (int i = 0; i < 16; i++)
    {
        cin >> element;
        if (element == 'b')
            square[i / 4][i % 4] = 1;
        else
            square[i / 4][i % 4] = 0;
    }

    flag = test(square);
    if (flag == true)
    {
        cout << 0;
        return 0;
    }

    for (int t = 1; t <= 16; t++)
    {
        //choose element
        counts = 0;
        a[0] = t;
        int im = comb(16, t, square);
        if (im != 0)
        {
            cout << im;
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}

bool test(int square[][4])
{
    int count = 0;
    for (int i = 0; i < 16; i++)
        count += square[i / 4][i % 4];
    if (count == 0 || count == 16)
        return true;
    return false;
}

int comb(int m, int k, int squareOrigin[4][4])
{
    int i, j;
    int square[4][4];
    memcpy(square, squareOrigin, 64);
    for (i = m; i >= k; i--)
    {
        a[k] = i;
        if (k > 1)
        {
            f = 0;
            int back = comb(i - 1, k - 1, square);
            if(back != 0) return back;
        }
        else
        {
            counts = 0;
            for (j = a[0]; j > 0; j--)
            {
                counts++;
                int t = a[j] - 1;
                square[t / 4][t % 4] ^= 1;
                if (t == 5 || t == 6 || t == 9 || t == 10)
                {
                    square[t / 4 - 1][t % 4] ^= 1;
                    square[t / 4 + 1][t % 4] ^= 1;
                    square[t / 4][t % 4 + 1] ^= 1;
                    square[t / 4][t % 4 - 1] ^= 1;
                }
                else if (t == 1 || t == 2)
                {
                    square[t / 4 + 1][t % 4] ^= 1;
                    square[t / 4][t % 4 + 1] ^= 1;
                    square[t / 4][t % 4 - 1] ^= 1;
                }
                else if (t == 4 || t == 8)
                {
                    square[t / 4 - 1][t % 4] ^= 1;
                    square[t / 4 + 1][t % 4] ^= 1;
                    square[t / 4][t % 4 + 1] ^= 1;
                }
                else if (t == 7 || t == 11)
                {
                    square[t / 4 - 1][t % 4] ^= 1;
                    square[t / 4 + 1][t % 4] ^= 1;
                    square[t / 4][t % 4 - 1] ^= 1;
                }
                else if (t == 13 || t == 14)
                {
                    square[t / 4 - 1][t % 4] ^= 1;
                    square[t / 4][t % 4 + 1] ^= 1;
                    square[t / 4][t % 4 - 1] ^= 1;
                }
                else if (t == 0)
                {
                    square[t / 4 + 1][t % 4] ^= 1;
                    square[t / 4][t % 4 + 1] ^= 1;
                }
                else if (t == 3)
                {
                    square[t / 4 + 1][t % 4] ^= 1;
                    square[t / 4][t % 4 - 1] ^= 1;
                }
                else if (t == 12)
                {
                    square[t / 4 - 1][t % 4] ^= 1;
                    square[t / 4][t % 4 + 1] ^= 1;
                }
                else
                {
                    square[t / 4 - 1][t % 4] ^= 1;
                    square[t / 4][t % 4 - 1] ^= 1;
                }
                if (f == -1)
                {
                    bool flag = test(square);
                    if (flag == true)
                        return j;
                    memcpy(square, squareOrigin, 64);
                }
            }
            bool flag = test(square);
            if (flag == true)
                return counts;
            memcpy(square, squareOrigin, 64);
        }
    }
    return 0;
}