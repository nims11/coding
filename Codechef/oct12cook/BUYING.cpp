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
    in_T
    {
        int n,x,tot=0;
        in_I(n);
        in_I(x);
        int arr[n];
        for(int i=0;i<n;i++)
        {
            in_I(arr[i]);
            tot += arr[i];
        }
        int wanted = tot/x;
        int rem = tot%x;
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=rem)
            {
                flag=false;break;
            }
        }
        if(flag)
            cout<<wanted<<endl;
        else
            cout<<-1<<endl;
    }
}
