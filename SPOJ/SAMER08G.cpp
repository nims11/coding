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
    int n;
    int arr[2000];
    while(1)
    {
        in_I(n);
        if(n==0)
            return 0;
        for(int i=0;i<=n;i++)
            arr[i] = 0;
        int a,b;
        int flag = 1;
        for(int i=1;i<=n;i++)
        {
            in_I(a);in_I(b);
            int pos = i+b;
            if(flag && pos>0 && pos<=n && arr[pos] == 0)
            {
                arr[pos] = a;
            }else
            {
                flag = 0;
            }
        }
        if(flag)
        {
            for(int i=1;i<=n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }else
        cout<<-1<<endl;
    }
}
