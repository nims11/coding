/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int getlen(int x){
    int res = 0;
    while(x){
        res++;
        x/=10;
    }
    return res;
}
long long getans(int x){
    if(x == 0)return 0;
    int len = getlen(x);
    int nxt = 1;
    for(int i = 0;i<len-1;i++)
        nxt *= 10;
    long long res = (x-nxt+1)*1LL*len;
    return res+getans(nxt-1);
}
int main()
{
    int n;
    in_I(n);
    cout<<getans(n)<<endl;
}
