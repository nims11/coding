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
#include<cstring>
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
char str1[100003],str2[100003];
int main()
{
    int t;
    in_I(t);
    for(int i=0;i<t;i++)
    {
        in_S(str1);
        in_S(str2);
        int len1 = strlen(str1), len2 = strlen(str2);

        vector<int> ans;
        for(int i=0;i<len1-len2+1;i++)
        {
            int mis = 0;
            for(int j=0;j<len2 && mis<2;j++)
            {
                mis += (str1[i+j]!=str2[j]);
            }
            if(mis<2)
                ans.push_back(i);
        }

        for(int i=0;i<ans.size();i++)
        {
            printf("%d", ans[i]);
            (i==ans.size()-1?:printf(" "));
        }
        newline;
    }
}
