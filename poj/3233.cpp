#include<cstdio>
#include<string.h>
#define N 31
struct Matrix
{
    int a[N][N];
}res,origin,tmp,A,B,C,ans;
int n,m;
Matrix mul(Matrix x,Matrix y)   //矩阵乘法
{
    int i,j,k;
    memset(tmp.a,0,sizeof(tmp.a));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
            {
                tmp.a[i][j]+=(x.a[i][k]*y.a[k][j]);
                tmp.a[i][j]%=m;
            }
    return tmp;
}
Matrix quickpow(Matrix origin,int k)   //矩阵快速幂
{
    int i;
    memset(res.a,0,sizeof(res.a));
    for(i=1;i<=n;i++)
        res.a[i][i]=1;
    while(k)
    {
        if(k&1)
            res=mul(res,origin);
        origin=mul(origin,origin);
        k>>=1;
    }
    return res;
}
Matrix sum(Matrix x,Matrix y)   //矩阵求和
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            tmp.a[i][j]=(x.a[i][j]+y.a[i][j])%m;
    return tmp;
}
Matrix bin(int k)
{
    if(k<=1)
        return A;
    else if(k%2)   //奇数：F[n]=F[n-1]+A^n   
    {
        B=bin(k-1);
        C=quickpow(A,k);   
        return sum(B,C);
    }
    else     //偶数： F[n]=F[n/2]+F[n/2]*A^(n/2)
    {
        B=bin(k/2);
        C=quickpow(A,k/2);
        C=mul(C,B);
        return sum(B,C);
    }
}
int main()
{
    int i,j,k;
    scanf("%d%d%d",&n,&k,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&A.a[i][j]);
    ans=bin(k);   //二分，子问题
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            if(j<n)
                printf("%d ",ans.a[i][j]);
            else
                printf("%d\n",ans.a[i][j]);
    }
    return 0;
}