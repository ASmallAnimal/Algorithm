# 稳定排序

对于冒泡排序来说，是稳定排序，对于选择排序来说，是不稳定排序
可以将选择排序的结果和冒泡排序的结果相比较，只需要O(n)复杂度就可以完成判断。

```c++
//另设一个结构体，设置标志和值
//借助扑克牌的思想，有梅花4，方块4
#include<iostream>

using namespace std;


struct Card
{
    char suit, value;
};

void bubble(struct Card A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= i + 1; j--)
        {
            if (A[j].value < A[j - 1].value)
            {
                Card t = A[j];
                A[j] = A[j - 1];
                A[j - 1] = t;
            }
        }
    }
}

void selection(struct Card A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int minj = i;
        for (int j = i; j < N; j++)
        {
            if (A[j].value < A[minj].value)
            {
                minj = j;
            }
            Card t = A[i];
            A[i] = A[minj];
            A[minj] = t;
        }
    }
}

void print(struct Card A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            cout << " ";
            cout << A[i].suit << A[i].value;
        }
        cout << endl;
    }
}

bool isStable(struct Card C1[], struct Card C2[], int N){
    for(int i = 0; i < N;i++){
        if(C1[i].suit != C2[i].suit) return false;
    }
    return true;
}

int main(){
    Card C1[100], C2[100];
    int N;
    char ch;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>C1[i].suit>>C1[i].value;
        C2[i] = C1[i];
    }

    bubble(C1, N);
    selection(C2,N);

    print(C1,N);
    cout<<"Stable"<<endl;
    print(C2,N);
    if(isStable(C1,C2,N)){
        cout<<"Stable"<<endl;
    }
    else cout<<"Not Stable"<<endl;

    return 0;
}
```
