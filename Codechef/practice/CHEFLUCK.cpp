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

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
int main()
{
    in_T
    {
        int n;
        in_I(n);
        bool flag=false;
        for(int i=n;i>=0;i--)
        {
            if(i%7==0 && (n-i)%4==0)
            {
                cout<<i<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)cout<<-1<<endl;
    }
}

