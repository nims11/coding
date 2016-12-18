/*
    Nimesh Ghelani (nims11)
    dp[i][j] -> for position i, the string to the left has longest suffix common to prefix of pattern equal to j
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
char X[10002], Y[1002];
int dp[10002][1002];
int t[1002][26];
int pi[1002], k;
const int INF = 1e9;
int main()
{
    while(in_S(X+1) != EOF)
    {
        in_S(Y+1);
        int lX = strlen(X+1)+1, lY = strlen(Y+1);

        pi[1] = k = 0;

        for(int i=2; i<=lY; i++)
        {
            while(k>0 && Y[i] != Y[k+1])
                k = pi[k];
            if(Y[i] == Y[k+1])
                k++;
            pi[i] = k;
        }

        for(int i=0;i<lY;i++)
        {
            for(char j='a';j<='z';j++)
            {
                int k = i;
                while(k>0 && j != Y[k+1])
                    k = pi[k];
                if(j == Y[k+1])
                    k++;
                t[i][j-'a'] = k;
            }
        }
        for(int i = 0; i<= lX; i++)
            dp[i][lY] = INF;
        for(int i = 0; i<lY; i++)
            dp[lX][i] = 0;
//            cout<<dp[lX][0]<<" "<<dp[lX][1]<<endl;
        for(int i = lX-1; i>0; i--)
        {
            for(int j = 0; j<lY; j++)
            {
                dp[i][j] = min(1+dp[i+1][j], dp[i+1][t[j][X[i]-'a']]);
//                cout<<dp[i][j]<<" ";
            }
//            newline;
        }
        printf("%d\n", dp[1][0]);
    }
}
