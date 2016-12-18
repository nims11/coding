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
vector<long long> poss_V;
int prime[4] = {2,3,5,7};
void gen_V(int pre, long long val, int p[4])
{
    if((p[0]+1)/2+(p[1]+2)/3+p[2]+p[3] >=18)return;
    if(val>1000000000000000000)
        return;
    poss_V.push_back(val);
    for(int i=pre;i<4;i++)
    {
        p[i]++;
        gen_V(i, val*prime[i], p);
        p[i]--;
    }
}
int main()
{
    int p[4] = {0};
    p[0]++;
    gen_V(0,2,p);
    p[0]--;
    p[1]++;
    gen_V(1,3,p);
    p[1]--;
    p[2]++;
    gen_V(2,5,p);
    p[2]--;
    p[3]++;
    gen_V(3,7,p);
    p[3]--;
    sort(poss_V.begin(), poss_V.end());
    for(int i=0;i<20;i++)
        cout<<poss_V[i]<<endl;
    cout<<poss_V.size()<<endl;
}
