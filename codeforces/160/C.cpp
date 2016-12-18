/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    int m;
    cin>>m;
    int min_m = 1000000;
    for(int i=0;i<m;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp<min_m)
            min_m = tmp;
    }
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int done[n];
    for(int i=0;i<n;i++)
        done[i] = 0;
    sort(arr, arr+n);
    int ans = 0;
    int tmp = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(!done[i])
        {
            done[i]  =1;
            ans+=arr[i];
            tmp++;
            int foo = 2;
            if(tmp%min_m==0)
            while(i>=0 && foo)
            {
                if(!done[i])
                {
                    done[i] = 1;
                    foo--;
                }
                i--;
            }
            i++;
        }
    }
    cout<<ans<<endl;
}
