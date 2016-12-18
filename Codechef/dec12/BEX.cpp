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
int arr[1000001];
char str[1000001][16];
int bar[1000001];
int main()
{
    int n, A;
    in_I(n);
    arr[0] = 1<<29;
    int curr=1;
    bar[0] = 0;
    while(n--)
    {
        in_I(A);
        if(A==-1)
        {
            curr--;
            printf("%d %s\n", curr-bar[curr], str[bar[curr]]);
            curr = bar[curr]-1;
            curr++;
        }else
        {
            in_S(str[curr]);
            if(A==0)continue;
            if(A<=arr[bar[curr-1]])
            bar[curr] = curr;
            else
            bar[curr] = bar[curr-1];
            arr[curr] = A;
//            cout<<curr<<" "<<arr[curr]<<" "<<bar[curr]<<endl;
            curr++;
        }
    }
}
