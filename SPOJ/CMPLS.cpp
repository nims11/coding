/*
 * pen and paper for understanding the approach
 * just filter the difference till you get a sequence(of differences) which can be represented by -1 degree polynomial or when the length is 1.
 * Then find the way up to the original sequence.
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
#define LL long long
using namespace std;
bool is_all_eq(LL *foo,int s)
{
    bool flag=true;
    for(int i=1;i<s;i++)
    if(foo[i]!=foo[i-1])
    {
        flag=false;break;
    }
    return flag;
}
int main()
{
    int s,c;
    LL foo[1000],bar[1000],seq[102];
    int count;
    in_T
    {
        count=0;
        in_I(s);in_I(c);
        for(int i=0;i<s;i++)
        {in_L(seq[i]);foo[i]=seq[i];}

        bool flag=true;
        for(int i=1;i<s;i++)
        if(seq[i]!=seq[i-1]){flag=false;break;}

        if(flag)
        {
            for(int i=0;i<c;i++)
            printf("%lld ",seq[0]);
            printf("\n");
            continue;
        }

        int len=s;
        while(1)
        {
            if(is_all_eq(foo,len))
            break;
            for(int i=1;i<len;i++)
            foo[i-1]=foo[i]-foo[i-1];
            len--;
        }
        int depth=s-len+1;
        LL k=foo[0];
        LL tmp1,tmp2;
        for(int i=len;i<len+c;i++)
        {
            tmp1=foo[i];tmp2=k;
            for(int j=0;j<depth;j++)
            {
                foo[j+i]=tmp2;
                tmp2=tmp2+tmp1;
                tmp1=foo[j+i+1];
            }
            printf("%lld ",foo[i+depth-1]);
        }
        printf("\n");
    }
}
