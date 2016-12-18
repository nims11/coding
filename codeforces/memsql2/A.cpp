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
string cand[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
bool poss(string s1, string s2){
    if(s1.length() != s2.length())return false;
    for(int i = 0;i<s1.length();i++)
        if(s1[i] != '.' && s1[i] != s2[i])
            return false;
    return true;
}
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    for(int i = 0;i<8;i++)
        if(poss(str, cand[i]))
        {cout<<cand[i]<<endl;return 0;}
}
