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
int n,m,x;
char str[10];
int atk[100], def[100];
int s[100];
int a_cnt, d_cnt;
int case1()
{
    sort(atk, atk+a_cnt);
    sort(s, s+m);
    int ret = 0;
    for(int i=0;i<a_cnt;i++)
    {
        if(s[m-i-1]>=atk[i])
            ret += s[m-i-1]-atk[i];
        else
            break;
    }
//    cout<<ret<<endl;
    return ret;
}
int case2()
{
    int ret = 0;
    multiset<int> ss;
    multiset<int>::iterator it;
    for(int i=0;i<m;i++)
        ss.insert(s[i]);
    for(int i=0;i<d_cnt;i++)
    {
        it = ss.upper_bound(def[i]);
        if(it == ss.end())
            return -1;
        ss.erase(it);
    }

    for(int i=0;i<a_cnt;i++)
    {
        it = ss.lower_bound(atk[i]);
        if(it == ss.end())
            return ret;
        ret += *it-atk[i];
        ss.erase(it);
    }
    for(it=ss.begin();it!=ss.end();it++)
        ret += *it;
    return ret;
}
int main()
{
    in_I(n);in_I(m);
    for(int i=0;i<n;i++)
    {
        in_S(str);
        if(str[0] == 'A')in_I(atk[a_cnt++]);
        else             in_I(def[d_cnt++]);
    }
    for(int i=0;i<m;i++)
        in_I(s[i]);
    int res = max(case1(), case2());
    cout<<res<<endl;

}
