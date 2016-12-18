/*
    Nimesh Ghelani (nims11)
    word by word, find valid ways to complete the abbreviation till any letter.
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
#include<cstdlib>
#include<cstring>
#include<set>
#include<utility>
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
set<string> excl;
char str[200];
int **dp1, **dp2;
void solve(string str1)
{
    stringstream ss(str1);
    string abbr;
    ss>>abbr;
    for(int i=0;i<abbr.size();i++)
        abbr[i] = 'a'+abbr[i]-'A';
    vector<string> full;
    full.push_back("");
    string foo;
    while(ss>>foo)
    {
        if(excl.find(foo) == excl.end())
            full.push_back(foo);
    }
    int **pre = dp1, **curr = dp2;
    pre[0][0] = 1;
    for(int i=1;i<=abbr.size();i++)
        pre[0][i] = 0;
    for(int i=1;i<full.size();i++)
    {
        for(int j=1;j<=full[i].size();j++)
        {
            curr[j-1][0] = 0;
            for(int k=1;k<=abbr.size();k++)
            {
                if(j == 1)
                    curr[j][k] = 0;
                else
                    curr[j][k] = curr[j-1][k];
                curr[j][k] += (abbr[k-1] == full[i][j-1])*(curr[j-1][k-1] + pre[full[i-1].size()][k-1]);
            }
        }
        swap(pre, curr);
    }
    transform(abbr.begin(), abbr.end(),abbr.begin(), ::toupper);
    if(pre[full[full.size()-1].size()][abbr.size()])
        printf("%s can be formed in %d ways\n", abbr.c_str(), pre[full[full.size()-1].size()][abbr.size()]);
    else
        printf("%s is not a valid abbreviation\n", abbr.c_str());
}
int main()
{
    dp1 = new int*[200];
    dp2 = new int*[200];
    for(int i=0;i<200;i++)
    {
        dp1[i] = new int[200];
        dp2[i] = new int[200];
    }
    while(1)
    {
        excl.clear();
        int n;
        in_I(n);
        if(n == 0)
            return 0;
        while(n--)
        {
            in_S(str);
            excl.insert(str);
        }
        cin.ignore(1);
        while(1)
        {
            cin.getline(str, 199);
            if(strcmp(str, "LAST CASE") == 0)
                break;
            solve(str);
        }
    }
}
