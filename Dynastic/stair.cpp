#include<bits/stdc++.h>

using namespace std;

class stair
{
private:
    /* data */
    int n;
public:
    stair(/* args */);
    ~stair();
    int solve(int n);
};

stair::stair(/* args */)
{
}

stair::~stair()
{
}

int stair::solve(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    int _1st, _2th, _3rd;
    _1st = 1;
    _2th = 2;
    for(int i = 2; i < n; i++){
        _3rd = _1st + _2th;
        _1st = _2th;
        _2th = _3rd;
    }
    return _3rd;
}

int main(){
    int n;
    cin>>n;
    stair s;
    int d = s.solve(n);
    cout << d;
    return 0;
}