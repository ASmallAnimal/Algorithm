#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

typedef struct point
{
    int x, y;
} point;

void Merge(point arr[], int low, int mid, int high)
{
    //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i = low, j = mid + 1, k = 0;     //mid+1为第2有序区第1个元素，j指向第1个元素
    int *temp = new int[high - low + 1]; //temp数组暂存合并的有序序列
    while (i <= mid && j <= high)
    {
        if (arr[i].x <= arr[j].x) //较小的先存入temp中
            temp[k++] = arr[i++].x;
        else
            temp[k++] = arr[j++].x;
    }
    while (i <= mid) //若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++] = arr[i++].x;
    while (j <= high) //同上
        temp[k++] = arr[j++].x;
    for (i = low, k = 0; i <= high; i++, k++) //将排好序的存回arr中low到high这区间
        arr[i].x = temp[k];
    delete[] temp; //释放内存，由于指向的是数组，必须用delete []
}

void sort(point a[], int N)
{
    for (int size = 1; size < N; size *= 2)
    {
        //  low+size=mid+1,为第二个分区第一个元素，它 < N，确保最后一次合并有2个区间
        for (int low = 0; low + size < N; low += 2 * size)
        {
            int mid = low + size - 1;
            int high = low + 2 * size - 1;
            if (high > N - 1)
                high = N - 1;
            Merge(a, low, mid, high);
        }
    }
}

double dis(point a, point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

point station[100000];
point agent[100000];
int main()
{
    int testNum, N;
    cin >> testNum;
    for (int i = 0; i < testNum; i++)
    {
        memset(station, -1, sizeof(station));
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> station[j].x >> station[j].y;
        }
        sort(station, N);
        for (int j = 0; j < N; j++)
        {
            cin >> agent[j].x >> agent[j].y;
        }
        double min = dis(station[0], agent[0]);
        for (int j = 1; j < N; j++)
        {
            int t = dis(station[j], agent[0]);
                min = min > t ? t : min;
        }

        for (int j = 1; j < N; j++){
            
        }
    }
    return 0;
}

/*

1
4
0 0
1 1
3 0
2 1
4 2
2 3
3 2
3 3
*/