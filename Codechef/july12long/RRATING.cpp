/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
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
    int n;
    in_I(n);
    set<int> foo;
    set<int>::iterator it,marker_1=foo.end();
    int marker=-1,size=0;
    int tmp1,tmp2;
    while(n--)
    {
        in_I(tmp1);
        if(tmp1==1)
        {
            size++;
            in_I(tmp2);
            foo.insert(-tmp2);
            if(size==3)marker_1=foo.begin();
            else if(marker_1!=foo.end())
            {
                if(size%3==0)
                marker_1++;
                if(tmp2>-*marker_1)marker_1--;
            }
            if(size%3==0)marker++;
        }else
        {
            if(marker_1==foo.end())printf("No reviews yet\n");
            else
            {
                printf("%d\n",-*marker_1);
            }
        }
    }
}
