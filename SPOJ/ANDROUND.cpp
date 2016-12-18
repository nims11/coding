//GQ
/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
    int arr[20000],ans[20000];
    in_T
    {
        int n,k;
        in_I(n);in_I(k);
        for(int i=0;i<n;i++)
        in_I(arr[i]);
        int a = ~(1<<31);
        for(int i=0;i<n;i++)
        {
            ans[i]=0;
        }
        if(k>=n/2)
        {
            int l = ~0;
            for(int i=0;i<n;i++)
            l&=arr[i];
            for(int i=0;i<n;i++)
            ans[i]=l;
        }else{
            int foo[32]={0};
            for(int i=0;i<31;i++)
            {
                for(int j=0;j<=k;j++)
                {
                    if(!(arr[j]&(1<<i)))foo[i]++;
                }
                for(int j=n-1;j>=n-k;j--)
                {
                    if(!(arr[j]&(1<<i)))foo[i]++;
                }
            }
            for(int i=0;i<n;i++)
            {
//                for(int q=0;q<31;q++)
//            cout<<"-"<<foo[q];
//            cout<<endl;
                for(int j=0;j<31;j++)
                {
                    if(!foo[j])ans[i]|=1<<j;

                    if(!(arr[(i+k+1)%n]&(1<<j)))foo[j]++;
                    if(!(arr[(i-k+n)%n]&(1<<j)))foo[j]--;
                }
            }
        }
        for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
        newline;
    }
}
