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
char A[20002],B[20002];
int main()
{
    in_T
    {
        int a[10]={0},b[10]={0};
        scanf("%s%s",A,B);
        for(int i=0;A[i];i++)
            a[A[i]-'0']++,b[B[i]-'0']++;
        int sevens=0,fours=0;
        for(int i=5;i<7;i++)
        {
            while(a[i] && b[7])
                sevens++,a[i]--,b[7]--;
            while(b[i] && a[7])
                sevens++,b[i]--,a[7]--;
        }
        for(int i=0;i<5;i++)
        {
            while(a[i] && b[7])
                sevens++,a[i]--,b[7]--;
            while(b[i] && a[7])
                sevens++,b[i]--,a[7]--;
        }
        while(a[7] && b[7])
            sevens++,a[7]--,b[7]--;
        while(b[7] && a[7])
            sevens++,b[7]--,a[7]--;
//        cout<<sevens<<endl;
//        cout<<a[7]<<" "<<b[7]<<endl;
        for(int i=0;i<5;i++)
        {
            while(a[i] && b[4])
                fours++,a[i]--,b[4]--;
            while(b[i] && a[4])
                fours++,b[i]--,a[4]--;
        }
        while(sevens--)
            printf("7");
        while(fours--)
            printf("4");
        newline;
    }
}
