// 伪代码

/*

选择排序非常直观，每次循环从未排序的序列中找到最小值添加到已经排序之后的序列之后

完成整体的遍历之后完成整个排序

selectionSort(A,N)
    for i : 0 to N-1
        minj = i
        for j : i to N-1
            if A[j] < A[minj]
            minj = j
        exchange A[i] and A[minj]

时间复杂度O(n^2)
稳定性：由于交换操作，会打乱原有顺序，所以属于不稳定排序算法
冒泡，选择，插入比较：冒泡排序和选择排序，一个从局部入手，逐渐改变整体，另一个从整体入手选择小值，思路大不相同。但都是利用每次外层循环找到第i个最小值。插入排序则是外层循环后重新对原数组的第i个元素进行重新排序

*/

#include <cstdio>

int selectionSort(int A[], int N)
{
    int i, j, t, sw = 0, minj;
    //sw 交换次数
    for (i = 0; i < N - 1; i++)
    {
        minj = i;
        for (j = i; j < N; j++)
        {
            if (A[j] < A[minj])
                minj = j;
        }
        t = A[i];
        A[i] = A[minj];
        A[minj] = t;
        if (i != minj)
            sw++;
    }
    return sw;
}

int main()
{
    int A[100], N, i, sw;

    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d", &A[i]);

    sw=selectionSort(A,N);

    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    
    printf("\n%d\n", sw);
    
}