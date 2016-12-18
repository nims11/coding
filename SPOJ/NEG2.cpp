#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector <int> ans;
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    while(n!=0)
    {
        if(n>0)
        ans.push_back(n%2);
        else ans.push_back((-n)%2);
        if(n<0 && n%2!=0)
        n=n/(-2)+1;
        else
        n/=-2;
    }
    for(long long i=ans.size()-1;i>=0;i--)
    printf("%d",ans[i]);
    printf("\n");
    return 0;
}
