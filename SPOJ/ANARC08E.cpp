/*
Solution: Find (a+b)C(a)
*/
#include<iostream>
using namespace std;
long facto(int n)
{
    long res=1;
    for(int i=1;i<=n;i++)
    res*=i;
    return res;
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a==-1 && b==-1)
        break;

        if( a+b == (facto(a+b)/facto(a))/facto(b) )
        cout<<a<<"+"<<b<<"="<<a+b<<endl;
        else
        cout<<a<<"+"<<b<<"!="<<a+b<<endl;
    }
    return 0;
}
