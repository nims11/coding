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
int n, k;
int arr[1000];
int poss[2][1003];
int main()
{
    int z = 0;
    in_T
    {
        z++;

        in_I(n);
        in_I(k);
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        for(int i=0;i<=k;i++)
            poss[0][i] = poss[1][i] = 0;
        int ans = 0;
        poss[0][0] = poss[1][0] = 1;
        for(int i=0;i<n;i++)
        {
            int prev = i%2;
            for(int j=0;j<=k;j++)
            {
                if(poss[prev][j] == 1)
                    if(j + arr[i]<=k && poss[prev][j+arr[i]] == 0)
                    {
                        poss[prev][j+arr[i]] = -1;
                        ans = max(ans, j+arr[i]);
                    }
                if(poss[prev][j] == -1)
                    poss[prev][j] = 1;
            }
            for(int j=0;j<=k;j++)
                if(poss[!prev][j])poss[prev][j] = 1;
        }
        printf("Scenario #%d: %d\n", z, ans);
    }
}
