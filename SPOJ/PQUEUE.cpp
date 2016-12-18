/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>

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
    int priority[101],jobs[101];
    in_T
    {
        int n,m;
        in_I(n);in_I(m);
        for(int i=0;i<n;i++)
        {in_I(priority[i]);jobs[i]=priority[i];}
        sort(priority,priority+n);
        int count=0;
        int curr=0;
        int priority_curr=n-1;

        while(1)
        {
            while(jobs[curr]!=priority[priority_curr]){curr=(curr+1)%n;}
            count++;
            if(curr==m)break;
            priority_curr--;
            curr=(curr+1)%n;
        }
        printf("%d\n",count);
    }
}
