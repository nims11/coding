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

using namespace std;
map<string, int> foo;
string str;
int main()
{
    in_T
    {
        cin>>str;
        foo[str]++;
        getline(cin, str);
    }
    vector<pair<int, string> > bar;
    for(map<string, int>::iterator it = foo.begin(); it != foo.end(); it++)
    {
        printf("%s %d\n", it->first.c_str(), it->second);
    }
}
