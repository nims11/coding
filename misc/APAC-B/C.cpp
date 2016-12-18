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
int arr[1000];
int n, K;
int dp[200][200];
int getans(int st, int end){
    if(end-st+1 <3)return max(0, end-st+1);
    if(dp[st][end] != -1)return dp[st][end];
    int &ret = dp[st][end];
    ret = end-st+1;
    for(int i = st;i<=end;i++){
        for(int j = i+1;j<=end;j++)
            for(int k = j+1;k<=end;k++)
                if(arr[i]+K == arr[j] && arr[j]+K == arr[k]){
                    int q1 = getans(st, i-1),
                        q2 = getans(i+1, j-1),
                        q3 = getans(j+1, k-1),
                        q4 = getans(k+1, end);

                    cout<<i<<","<<j<<","<<k<<endl;
//                    cout<<q1<<" "<<q2<<" "<<q3<<" "<<q4<<endl;
                    if(q2 ==0 && q3 == 0)
                        ret = min(ret, q1+q4);
                    else
                        ret = min(ret, q1+q2+q3+q4+3);
                }
    }
//    cout<<st<<" "<<end<<" "<<ret<<endl;
    return ret;
}
int main()
{
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        cin>>n>>K;
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        for(int i = 0;i<200;i++)for(int j = 0;j<200;j++)
            dp[i][j] = -1;
        cout<<getans(0, n-1)<<endl;
        
}
}
