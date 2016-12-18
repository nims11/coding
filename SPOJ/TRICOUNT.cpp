#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int  n,res;
        cin>>n;
        res=(n*(n+2)*(2*n+1))/8;
        cout<<res<<endl;
    }
    return 0;
}
