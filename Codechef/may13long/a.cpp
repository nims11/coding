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
int main()
{
    std::string s0;
    std::string s1;
    int n = 1;
    std::stringstream ss;
    ss << n;
    ss >> s0;
    cout << "S0:" << s0 << endl;
//    ss.clear();
    n = 2;
    ss << n;
    ss >> s1;
    cout << "S1:" << s1 << endl;
    ss << n;
    ss >> s0;
    cout << "S0_2:" << s0 << endl;
 }
