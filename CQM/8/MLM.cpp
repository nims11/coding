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
    bool flag = false;
    int n = strlen(str);
    for(int q=1;q<n;q++)
    {
        while(k && str[k] != str[q])
            k = pref_f[k-1];
        if(str[k] == str[q])
            k++;
        pref_f[q] = k;
//        cout<<k<<endl;
//            printf("%d %d\n", q+1, (q+1)/(q+1-k));
    }
    int res = n;
    for(int q=1;q<n;q++){
        k = pref_f[q];
        if(k != 0 && (q+1)%(q+1-k) == 0){
            int ans = (q+1-k);
//            cout<<ans<<endl;
            if(ans > n-q-1 && pref_f[n-1] > n-q-1)
            {
                res = min(res, ans);
            }
        }else{
            int ans = q+1;
//            cout<<ans<<endl;
            if(ans > n-q-1 && pref_f[n-1] >= n-q-1)
            {
                res = min(res, ans);
            }
        }
    }
    printf("%d\n", res);
}
int main()
{
    int c = 0;
    in_T
    {
        in_S(str);
        calc_pref_f();
    }
}
