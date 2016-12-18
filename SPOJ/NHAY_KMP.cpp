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
#include<cmath>
#include<cassert>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d\n",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int n;
char P[1000001];
char ch;
vector<int> pref_f;
void calc_prefix_f()
{
    pref_f.push_back(0);
    int k = 0;
    for(int q=1;q<n;q++)
    {
        while(k && P[k] != P[q])
            k = pref_f[k-1];
        if(P[k] == P[q])k++;
        pref_f.push_back(k);
    }
}
int main()
{
    while(in_I(n) != EOF)
    {
        assert(n<=1000000);
        cin.getline(P, n+1);
        pref_f.clear();
        calc_prefix_f();
        int q = 0;
        int idx = 1;
        int f = 0;
        while(1)
        {
            scanf("%c", &ch);
//            cout<<ch<<endl;
            if(ch == '\n')break;
            while(q && P[q] != ch)
                q = pref_f[q-1];
            if(P[q] == ch)
                q++;
            if(q == n)
            {
                f = 1;
                printf("%d\n", idx-n);
            }
            idx++;
        }
        if(!f)
            newline;

    }
}
