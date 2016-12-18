/*
    Nimesh Ghelani (nims11)
    Ad-Hoc
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
    int n;
    in_I(n);
    int sec[3] = {0};
    int scor[3] = {0};
    int secc = 0, min = 0, t;
    int time_elap = 0;
    while(n--)
    {
        scanf("%d %d:%d", &t, &min, &secc);
        int from_st = min*60+secc;
        if(scor[1]>scor[2])
            sec[1]+=from_st-time_elap;
        else if(scor[2]>scor[1])
            sec[2]+=from_st-time_elap;
        scor[t]++;
        time_elap = from_st;
    }
    int from_st = 48*60;
    if(scor[1]>scor[2])
        sec[1]+=from_st-time_elap;
    else if(scor[2]>scor[1])
        sec[2]+=from_st-time_elap;
    time_elap = from_st;
    printf("%.2d:%.2d\n%.2d:%.2d\n", sec[1]/60, sec[1]%60, sec[2]/60, sec[2]%60);
}
