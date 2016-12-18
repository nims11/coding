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
int N, K;
char P[10];
char T[6000000];
int st[1000001];
int P_size;
vector<int> pref_f;
void calc_prefix_f()
{
    pref_f.push_back(0);
    int k = 0;
    for(int q=1;q<P_size;q++)
    {
        while(k && P[k] != P[q])
            k = pref_f[k-1];
        if(P[k] == P[q])k++;
        pref_f.push_back(k);
    }
}
int main()
{
    int idx = 0;
    for(int i = 1000000;i>=0;i--)
    {
        st[i] = idx;
        int j = i;
        while(j)
        {
            T[idx++] = j%10+'0';
            j/=10;
        }
    }
    in_T
    {
        pref_f.clear();
        in_I(N);
        in_I(K);
        P_size = 0;
        while(K)
        {
            P[P_size++] = K%10 + '0';
            K/=10;
        }
        P[P_size] = 0;
        int res = 0;
        calc_prefix_f();
        int q = 0;
        for(int i = st[N]; i<st[0];i++)
        {
            while(q && P[q] != T[i])
                q = pref_f[q-1];
            if(P[q] == T[i])
                q++;
            if(q == P_size)
                res++;
        }
        printf("%d\n", res);
    }
}
