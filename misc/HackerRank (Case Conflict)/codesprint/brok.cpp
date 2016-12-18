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
    in_T{
        string str1, str2;
        cin>>str1>>str2;
        int brok[26] = {0};
        int br[26] = {0};
        for(int i = 0;i<str1.size();i++)
            brok[str1[i]-'a'] |= 1;
        for(int i = 0;i<str2.size();i++)
            br[str2[i]-'a'] = brok[str2[i]-'a']&1;
        int res = 0;
        for(int i = 0;i<26;i++)
            res += br[i];
        cout<<res<<endl;
    }
}
