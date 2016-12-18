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
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%llu",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
long long unsigned arr[10];
long long unsigned n,m;
int main()
{
    in_T
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        bool flag = false;
        long long unsigned sum = 0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=arr[i];
            if(sum>=m)
            {
                flag = true;
                cout<<n-i<<endl;
                break;
            }
        }
        if(!flag)
            cout<<-1<<endl;
    }
}
