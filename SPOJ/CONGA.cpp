/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int n,tmp;
    vector<int> foo;
    while(1)
    {
        in_I(n);
        if(n==0)return 0;
        foo.clear();
        for(int i=0;i<n;i++)
        {
            in_I(tmp);
            foo.push_back(tmp);
        }
        if(n==1){printf("0\n");continue;}
        int median;
        if(n%2==0)median=(foo[n/2]+foo[n/2-1])/2;
        else median=foo[n/2];
        int i=1;
        long long ans=0;
        for(;i<foo.size() && foo[i]<=median;i++)
        {
            ans+=(i)*(foo[i]-foo[i-1]-1);
        }
        ans+=i*(median-foo[i-1]);
        int j;
        for(j=foo.size()-2;foo[j]>median;j--)
        {
            ans+=(foo.size()-1-j)*(foo[j+1]-foo[j]-1);
        }
        ans+=(foo.size()-j-1)*(foo[j+1]-median-1);
        printf("%lld\n",ans);
    }
}
