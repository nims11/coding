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
int main()
{
    int N;
    in_I(N);
    int foo[26] = {0};

    for(int i = 0;i<N;i++){
        int tmp[26] = {0};
        string str;
        cin>>str;
        for(int j = 0;j<str.length();j++)
            tmp[str[j]-'a'] |= 1;
        for(int k = 0;k<26;k++)
            foo[k] += tmp[k];
    }
    int x = 0;
    for(int i = 0;i<26;i++)
        x += (foo[i] == N);
    cout<<x<<endl;
}
