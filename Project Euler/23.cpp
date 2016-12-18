#include<iostream>
#include<cmath>
using namespace std;
const int size=28124;
bool isAbuntant[size];
int getProperDivSum(int n)
{
    int limit=sqrt(n);
    int result=1;
    for(int i=2;i<=limit;i++)
    {
        if(n%i==0)
        {
            if(i!=n/i)
            result+=i+n/i;
            else
            result+=i;
        }
    }
    return result;
}
int main()
{
    for(int i=0;i<size;i++)
    {
        isAbuntant[i]=false;
    }
    for(int i=2;i<size;i++)
    {
        if(getProperDivSum(i)>i)
        {
            isAbuntant[i]=true;
            //cout<<i<<endl;
        }
    }
    long long unsigned res=0;
    for(int i=1;i<size;i++)
    {
        bool x=false;
        for(int j=12;j<=i/2;j++)
        {
            if(isAbuntant[j] && isAbuntant[i-j])
            {
                x=true;
                break;
            }
        }
        if(!x)
        res+=i;
    }
    cout<<res<<endl;
    return 0;
}
