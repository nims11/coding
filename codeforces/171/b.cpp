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
    int x,y;
    cin>>x>>y;
    int cx=0,cy=0;
    int cx_n=0, cy_n=0;
    int cur = 1;
    int cnt=0;
    if(x == 0 && y == 0)
    {
        cout<<0<<endl;
        return 0;
    }
    while(1)
    {
        if(cnt%2 ==0 )
        {
            if(cnt%4==0)
            {
                cx_n = cx+cur;
            }else
                cx_n = cx-cur;
        }else
        {
            if(cnt%4 == 1)
            {
                cy_n = cy+cur;
            }else
                cy_n = cy-cur;
        }
        if(cx<cx_n)
        {
            if(cy_n == y && (cx<x && cx_n>=x))
            {
                cout<<cnt<<endl;
                return 0;
            }
        }else if (cx>cx_n)
        {
            if(cy_n == y && (cx>x && cx_n<=x))
            {
                cout<<cnt<<endl;
                return 0;
            }
        }
        if(cy<cy_n)
        {
            if(cx_n == x && (cy<y && cy_n>=y))
            {
                cout<<cnt<<endl;
                return 0;
            }
        }else if (cy>cy_n)
        {
            if(cx_n == x && (cy>y && cy_n<=y))
            {
                cout<<cnt<<endl;
                return 0;
            }
        }
        cnt++;
        cx = cx_n;
        cy = cy_n;
//        cout<<cx<<" "<<cy<<endl;
//        int n;
//        cin>>n;
        if(cnt%2 == 0)
            cur++;

    }
}
