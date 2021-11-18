#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    map<string,string>M;
    string s1,s2,s;
    char str[23];
    while(gets(str)&&strlen(str))
    {
        s1=s2="\0";
        int i;
        for(i=0;;i++)
            if(str[i]==' ')
            {
                str[i]='\0';
                break;
            }
        s1+=str;
        s2+=str+i+1;
        M[s2]=s1;
    }
    while(cin>>s)
    {
        if(M[s].size())
            cout<<M[s]<<endl;
        else
            cout<<"eh"<<endl;
    }
    return 0;
} 