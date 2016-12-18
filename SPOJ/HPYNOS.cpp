/*
 * recursion+DP
 */
#include<iostream>
using namespace std;
int isHPY[811];
int isHappy(long long n)
{
    long long n2=n;
    if(n<811)
    {
        if(isHPY[n]>=-1)
        {
            return isHPY[n];
        }

        if(isHPY[n]==-2)
        return -1;

        isHPY[n]=-1;
    }
    int k=0;
    while(n2>0)
    {
        int x=n2%10;
        k+=x*x;
        n2/=10;
    }
    int ans=isHappy(k);
    if(ans>=0)
    ans++;
    if(n<811)
    isHPY[n]=ans;
    return ans;
}
int main()
{
    for(int i=0;i<811;isHPY[i++]=-3);
    isHPY[1]=0;
    long long n;
    cin>>n;
        cout<<isHappy(n)<<endl;
}

