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
int first[10], second[10];
int first_rev[10], second_rev[10], foo;
int n;
int main()
{
    in_T
    {
        in_I(n);

        int n2 = n;
        while(n2%10 == 0)
        n2/=10;
        int end = n2%10;
        int len = 0;
        while(n2)
            n2/=10, len++;
        int stup = 2*len - (end == 5);
        int x = ceil(0.95*n), y = floor(1.05*n);
        int len1 = 0, len2 = 0;
        while(x%10==0)
        {
            x/=10;
        }
        while(y%10==0)
        {
            y/=10;
        }
        while(x)
        {
            first[len1++] = x%10;
            x/=10;
        }
        while(y)
        {
            second[len2++] = y%10;
            y/=10;
        }
        for(int i=0;i<len1;i++)
            first_rev[len1-i-1] = first[i];
        for(int i=0;i<len2;i++)
            second_rev[len2-i-1] = second[i];

        foo = 0;
        while(foo<min(len1,len2) && first_rev[foo]==second_rev[foo])foo++;
        int flag;
        if(foo==min(len1,len2))
        {
            foo--;
            flag = (first_rev[foo]==5 && second_rev[foo]==5);
        }else
            flag = (first_rev[foo]<5 && second_rev[foo]>=5) || (first_rev[foo]==5 && foo==len1-1 && len1 == min(len1, len2));
//        cout<<foo<<endl;
//        int tmp = foo+1;
//        while(first_rev[foo]==0)foo--;
//        cout<<foo<<endl;
        int bar = 2*(foo+1) - flag;
        if(bar<stup)
            printf("absurd\n");
        else
            printf("not absurd\n");
    }
}


