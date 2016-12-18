/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#include<sstream>
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
pair<double, double> foo(string str)
{
    int i;
    int open, close, mid;
    for(i = str.length()-1; str[i]!='(';i--)
    {
        if(str[i] == ')')
            close = i;
        else if(str[i] == ',')
            mid = i;
    }
    open = i;
    return make_pair(atof(str.substr(open+1, mid-open-1).c_str()), atof(str.substr(mid+2, close-mid-2).c_str()));
}
int main()
{
    double ans = 0;
    pair<double, double> curr,prev;
    string tmp;
    getline(cin, tmp);
    prev = foo(tmp);
    while(getline(cin, tmp))
    {
        curr = foo(tmp);
        ans += sqrt((curr.first-prev.first)*(curr.first-prev.first) + (curr.second-prev.second)*(curr.second-prev.second));
        printf("The salesman has traveled a total of %.3lf kilometers.\n", ans);
        prev = curr;
    }
}
