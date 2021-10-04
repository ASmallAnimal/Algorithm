//希尔排序是在插入排序的基础上改进的，对原数列，进行间隔为g的插入排序，每轮排序缩小g的范围
//每次排序会使数列整体趋于有序

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long cnt; //移动次数
int l;
int A[1000000];
int n;
vector<int> G;

//间隔插入排序
void insertionSort(int A[], int n, int g)
{
    for (int i = g; i < n; i++)
    {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v)
        {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort(int A[], int n)
{
    //生成数列 三倍的关系
    for (int h = 1;;)
    {
        if (h > n)  //间隔不能超过数列长
            break;
        G.push_back(h);
        h = 3 * h + 1;  
    }

    for (int i = G.size() - 1; i >= 0; i--) //范围从大到小选择
        insertionSort(A, n, G[i]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    cnt = 0;

    shellSort(A, n);

    cout << G.size() << endl;
    for (int i = 0; i < G.size(); i++)
    {
        cout << G[i] << " ";
    }
    cout << endl;
    cout << cnt << endl;

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}