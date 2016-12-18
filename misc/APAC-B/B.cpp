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
long long getres(int bal, int op, int close){
    if(bal+op != close)return 0;
    long long dp[op+close+1][op+1+bal];
    for(int i = 0;i<op+close+1;i++)
        for(int j = 0;j<op+bal+1;j++)
            dp[i][j] = 0;
    dp[0][bal] = 1;
    for(int i = 1;i<op+close+1;i++){
        for(int j = 0;j<=op+bal;j++){
            if(j-1>=0)
                dp[i][j] += dp[i-1][j-1];
            if(j+1<=op+bal)
                dp[i][j] += dp[i-1][j+1];
        }
    }
//    cout<<bal<<" "<<op<<" "<<close<<" "<<dp[op+close][0]<<endl;
    return dp[op+close][0];
}
int main()
{
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        int N;
        long long K;
        cin>>N>>K;
        int arr[2*N];
        int bal[2*N];
        for(int i = 0;i<N;i++)
            arr[i] = 0, bal[i] = i+1;
        for(int i = N;i<2*N;i++)
            arr[i] = 1, bal[i] = bal[i-1]-1;
        long long cur = 0;
        for(int i = N;i<2*N;i++){
//            cout<<i<<endl;
            long long prevFoo = 0;
            for(int j = i-1;j>0 && arr[j] != 1;j--){
                long long foo = getres(bal[j], 2*N-j-(2*N-i)-1, 2*N-i);
                cur += foo - prevFoo;

                if(cur > K-1){
                    cur -= foo;
                    cur += prevFoo;

                    break;
                }
                else{
                    swap(arr[j], arr[j+1]);
                    prevFoo = foo;
                }
            }
                    bal[0] = 1;
                    for(int k = 1;k<2*N;k++)
                        bal[k] = bal[k-1] + (arr[k]==0?1:-1);

//            cout<<" "<<cur<<endl;
        }
        bool flag = true;
        for(int i = 0;i<2*N;i++)
            if(bal[i]<0)
                flag = false;
        if(cur != K-1 || !flag)
            cout<<"Doesn't Exist!"<<endl;
        else{
            for(int i = 0;i<2*N;i++)
                cout<<(arr[i]==0?"(":")");
            cout<<endl;
        }
    }
}
