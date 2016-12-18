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
int arr[500];
int main()
{
    int n;
    in_I(n);
    int neg = 0;
    int mini = 1000000;
    int sum = 0;
    for(int i=0;i<2*n-1;i++)
    {
        in_I(arr[i]);
        neg += (arr[i]<0);
        if(mini>abs(arr[i]))
            mini = abs(arr[i]);
        sum += abs(arr[i]);
    }
    if(neg>n)
    {
        if(n%2 == 0)
        printf("%d\n", sum-2*mini);
        else
        {
            printf("%d\n", sum);
        }
    }else if(neg == n || neg == 0)
    {
        printf("%d\n", sum);
    }else //neg<n
    {
        if(n%2 == 1)
        printf("%d\n", sum);
        else
        {
            printf("%d\n", sum-2*mini);
        }
    }

}
