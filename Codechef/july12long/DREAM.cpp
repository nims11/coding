/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<string>
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
    int n,k;
    in_I(n);in_I(k);
    int arr[100000];
    set<int> foo;
    set<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        in_I(arr[i]);
        foo.insert(arr[i]);
    }
    int ans=0;
    for(it=foo.begin();it!=foo.end();it++)
    {
        int i=0;
        while(i<n)
        {
            if(arr[i]==*it)
            {
                i+=k;
                ans++;
            }
            else i++;
        }
    }
    cout<<ans<<endl;
}
