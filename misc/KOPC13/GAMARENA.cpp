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
    int n,L,k,W;
    in_T
    {
        scanf("%d%d%d%d", &n,&k,&L,&W);
        if(n==1)
        {
            printf("0\n");continue;
        }
        int foo = 100000000;
        if(n%k==1)
        {
            foo = L;
        }
        else if(n%k==2%k)
        {
            foo = min(W+L,2*L);
        }
        else if(n%k == 0 && k>2)
        {
            foo = W+L;
        }
        else if(n%k>2)
        {
            foo = (W+L);
        }

        if(n==2)
        {
            printf("%d\n", min(L,W));
            continue;
        }else if(n<k)
        {
            printf("%d\n", W);
            continue;
        }
        int bar;
        if(n%k==0)
        {
            bar = W*(n/k-1)+(L*(n/k-2));
            if(bar<0)
                bar = 0;
            if(W*(n/k)+(L*(n/k-1))<bar+foo || bar==0)
            {
                bar = W*(n/k)+(L*(n/k-1));
            }else
            bar+=foo;
        }else
        bar = W*(n/k)+(L*(n/k-1))+foo;
        cout<<bar<<endl;
//        int a1=0,a2=0, a3 = 0, tmp1=0, tmp2=0;
//        for(int i=2;i<=n;i++)
//        {
//            if(a3==0)
//            {
//                a1 = tmp2+W;
//                a3+=2;
//            }else
//            {
//                if(a3==k)
//                {
//                    a3 = 0;
//                    a1 = tmp2+W;
//                    a3+=2;
//                }else
//                {
//                    a1 = tmp1;
//                    a3++;
//                }
//            }
//            a2 = tmp1+L;
//            cout<<a1<<" "<<a2<<" "<<a3<<endl;
//            tmp1 = a1;
//            tmp2 = a2;
//        }
//        printf("%d\n", min(a1,a2));
    }
}
