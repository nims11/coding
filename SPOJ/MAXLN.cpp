#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        long long r;
        cin>>r;
        double ans=(1+16*r*r)/double(4);
        printf("Case %d: %.2lf\n",z,ans);
    }
    return 0;
}
