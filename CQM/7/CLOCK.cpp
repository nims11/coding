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
#include<cstring>
#include<cstdlib>
#include<cassert>
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
int pre[24*60];
int main()
{
    int cur = 0;
    for(int i = 0;i<24;i++){
        double thistime = 12*5*(i%12)/double(11);
//            cout<<thistime<<endl;
        for(int j = 0;j<60;j++){
            if(j<thistime)
                pre[i*60+j] = cur;
            else
                pre[i*60+j] = cur+1;
        }
        if(thistime<60)
            cur++;
    }
    in_T{
        int h1, h2,m1,m2;
        scanf("%d:%d%d:%d", &h1, &m1, &h2, &m2);
        int st = h1*60+m1, end = h2*60+m2;
        int res = pre[end]-pre[st];
        printf("%d\n", res);
    }
}
