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
#include<cstring>
using namespace std;
char str[1000003];
int n;
int pref_f[1000003];
void calc_pref_f()
{
    pref_f[0] = 0;
    int k = 0;
    for(int q=1;q<n;q++)
    {
        while(k && str[k] != str[q])
            k = pref_f[k-1];
        if(str[k] == str[q])
            k++;
        pref_f[q] = k;
//        cout<<k<<endl;
        if(k != 0 && (q+1)%(q+1-k) == 0)
            printf("%d %d\n", q+1, (q+1)/(q+1-k));
    }
}
int main()
{
    int c = 0;
    in_T
    {
        c++;
        in_I(n);
        in_S(str);
        printf("Test case #%d\n", c);
        calc_pref_f();
        newline;
    }
}
