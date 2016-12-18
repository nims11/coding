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
int N, T;
int arr[110];
int pref[110];
int dp[110][110];
int C;
int getans(int x, int y){
    if(dp[x][y] != -1)
        return dp[x][y];
    int & ans = dp[x][y];
    if(x == y){
        return (ans = 0);
    }
    else if (x>y)
        return -1;
    
    ans = 1e9;
    for(int i = x; i<y;i++){
        int left = getans(x, i),
            right = getans(i+1, y);
        int leftSize = i-x+1,
            rightSize = y-i;
        int leftWeight = pref[i+1]-pref[x],
            rightWeight = pref[y+1]-pref[i+1];
        
        ans = min(ans, left + right + 
                max(0, leftSize*leftWeight + rightSize*rightWeight - C));
/*        ans = min(ans, left + right + leftSize*leftWeight + 
                arr[i] + (leftSize+1)*(leftWeight+arr[i]) + rightSize*rightWeight);
        ans = min(ans, left + right + rightSize*rightWeight +
                arr[i] + (rightSize+1)*(rightWeight+arr[i]) + leftSize*leftWeight);
                */
    }
    return ans;
}
int main()
{
    in_I(N);
    in_I(T);
    for(int i = 0;i<N;i++)
        in_I(arr[i]);
    pref[0] = 0;
    for(int i = 1;i<=N;i++)
        pref[i] = pref[i-1]+arr[i-1];
    int st = 0, end = 1000000000;
    while(st < end){
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++)
                dp[i][j] = -1;
        C = (st + end)/2;
        int res = max(0, getans(0, N-1));
        if(res <= T)
            end = C;
        else
            st = C+1;
    }
    cout<<end<<endl;
}
