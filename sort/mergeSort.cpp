//将原数组 分开 对每一部分进行排序整合
//还是拿牌堆举例子，把排队分成两部分，每一部分都是已经排好序的，最后将两个排好序的排队整合成一个牌即可
//实现过程采用递归--》容易理解
//也会给出迭代的方式

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define MAXSIZE 10

//递归
void Merge(vector<int> &Array, int front, int mid, int end)
{
    vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
    vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);
    int idxLeft = 0, idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
    // Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into Array[i]
    for (int i = front; i <= end; i++)
    {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight])
        {
            Array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        }
        else
        {
            Array[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(vector<int> &Array, int front, int end)
{
    if (front >= end)
        return;
    int mid = (front + end) / 2;
    MergeSort(Array, front, mid);
    MergeSort(Array, mid + 1, end);
    Merge(Array, front, mid, end);
}

void MergeSort(int k[], int n)
{
    // i 用于 for 循环迭代,temp 用来存储临时数组，所以要给他分配内存
    int i, next, left_min, left_max, right_min, right_max;
    int *temp = (int *)malloc(n * sizeof(int));

    // i 是步长，第一次是1个元素与1个元素相比，第2个是两个元素与2个元素相比
    for (i = 1; i < n; i = i<<1)
    {
        // left_min 最后是要小于 n-i 的，这一点可以通过画图得到
        // left_min = right_max 是指上一组排序完成之后，将上一组的 right 赋值给下一组的 left_min
        for (left_min = 0; left_min < n - i; left_min = right_max)
        {
            right_min = left_max = left_min + i;
            right_max = left_max + i;

            // 因为奇数的数组最后很有可能 right_max > n，所以将它限制到最大为 n
            if (right_max > n)
            {
                right_max = n;
            }

            next = 0;

            // 在这里跟递归中的归并操是一样的，从两个数组中取小的出来放入临时数组
            while (left_min < left_max && right_min < right_max)
            {
                if (k[left_min] < k[right_min])
                {
                    temp[next++] = k[left_min++];
                }
                else
                {
                    temp[next++] = k[right_min++];
                }
            }

            // 但是上面的过程并不会同时将左右两个数组的元素都放入临时存储数组 temp 中
            // 要么左边会剩一点，要么右边会剩一点，所以这个时候要对剩余的进行操作
            // 如果左边剩了，说明这些应该是最大的，应该放在数组的右边
            // 如果右边剩了保持原有的大小顺序即可
            while (left_min < left_max)
            {
                k[--right_min] = k[--left_max];
            }

            // 将临时存储的元素放入数组中得到最后的结果
            while (next > 0)
            {
                k[--right_min] = temp[--next];
            }
        }
    }
}

int main()
{
    int i, a[] = {5, 3, 2, 4, 1};

    MergeSort(a, 5);

    printf("排序后的结果是：");
    for (i = 0; i < 5; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n\n");

    return 0;
}