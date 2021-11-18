#include <cstdio>

//给定两个序列，一个升序，一个降序，判断是否有两个数的和为10000
int main()
{
    int a[50000];
    int hash[65536] = {0};
    int n1, n2;
    int t;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &t);
        if (t >= 0)
            hash[t] = 1;
        else
            hash[-t] = -1;
    }
    for (int i = 0; i < n1; i++)
    {
        t = 10000 - a[i];
        if (t >=0  && hash[t] == 1){
            printf("YES");
            return 0;
        }
        if(t < 0 && hash[-t] == -1){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}