/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
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
int GCD(int a,int b)
{
    while(b>0)
    {
        int temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}


int check(int a,int b,int c)
{
    if(c<0 || (c>a && c>b))
    return -1;
    if(c%GCD(a,b)==0)
    return 1;
    return -1;
}
struct foo
{
    int i,j;
};
int main()
{
    int a,b,c;
    in_T
    {
        in_I(a);in_I(b);in_I(c);
        if(max(a,b)<c || check(a,b,c)==-1)
        {
            printf("-1\n");
            continue;
        }
        int ans1=0,ans2=0;
        int sima=0,simb=0;
        while(1)
        {
            if(sima==c || simb==c)
            break;

            if(sima==0)
            {
                sima=a;
                ans1++;
            }else
            {
                if(simb==b)
                {
                    simb=0;
                    ans1++;
                }else
                {
                    if(b-simb>=sima)
                    {
                        simb+=sima;
                        sima=0;
                        ans1++;
                    }else
                    {
                        sima-=b-simb;
                        simb=b;
                        ans1++;
                    }
                }
            }
        }
        sima=0;simb=0;
        while(1)
        {
            if(sima==c || simb==c)
            break;

            if(simb==0)
            {
                simb=b;
                ans2++;
            }else
            {
                if(sima==a)
                {
                    sima=0;
                    ans2++;
                }else
                {
                    if(a-sima>=simb)
                    {
                        sima+=simb;
                        simb=0;
                        ans2++;
                    }else
                    {
                        simb-=a-sima;
                        sima=a;
                        ans2++;
                    }
                }
            }
        }
        int ans;
        if(ans1==-1 && ans2==-1)ans=-1;
        else if(ans1==-1 && ans2!=-1)ans=ans2;
        else if(ans2==-1 && ans1!=-1)ans=ans1;
        else ans=min(ans1,ans2);
        printf("%d\n",ans);
    }
}

