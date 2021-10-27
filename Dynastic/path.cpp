//状态转移 m，n的路径，等一m-1，n多有一步，+ m，n-1多走一步

#include<bits/stdc++.h>
#include<vector>

using namespace std;

class path
{
private:
    /* data */
    int m,n;
public:
    path
(/* args */);
    ~path
();
    int distinct(int m,int n);
};

path::path(/* args */)
{
}

path::~path()
{
}

int path::distinct(int m, int n){
    vector<vector<int>> d(m,vector<int>(n,0)) ;
    for (int i = 0; i < m; i++)
    {
        /* code */
        for (int j = 0; j <n; j++)
        {
            /* code */
            //one row or on coloum path the choice is a singe way
            if(i == 0 || j==0){
                d[i][j] = 1;
            }
            else
                d[i][j] = d[i-1][j] + d[i][j-1];
        }
        
    }
    
    return d[m-1][n-1];
}

int main(){
    int m,n;
    cin>>m>>n;
    path p;
    int num = p.distinct(m,n);
    cout<<num;
    return 0;
}