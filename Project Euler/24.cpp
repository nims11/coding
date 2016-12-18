#include<iostream>
#include<string>
using namespace std;
int used[10];
long facto(int n)
{
    if(n==0)
    return 1;
    return n*facto(n-1);
}
int getIndex(long &n,int curr)
{
    long x=facto(curr-1);
    cout<<n<< " "<<x<<endl;
    int res=(n-1)/x+1;
    n-=x*(res-1);
    return res;
}
int main()
{
    for(int i=0;i<10;i++)used[i]=0;
    //long n=1;
    string str;
    int curr=10;
    long n=1000000;
    while(curr!=0)
    {
        int index=getIndex(n,curr);
        //cout<<index<<endl;
        for(int j=0,count=0;j<10;j++)
        {
            if(used[j]==0)
            count++;
            if(count==index)
            {
                str.push_back('0'+j);
                used[j]=1;
                break;
            }
        }
        curr--;
    }
    cout<<str<<endl;
    return 0;
}
