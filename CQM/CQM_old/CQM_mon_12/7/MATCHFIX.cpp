/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<stack>
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
int n,m;
pair<int, int> matches[1002];
int dp[1002][100][3];
int main()
{
    matches[0] = make_pair(0,0);
    while(1)
    {
        in_I(n);if(n==-1)return 0;
        in_I(m);
        int match_count=1;
        int max_L;
        for(int i=0;i<n;i++)
        in_I(dp[0][i][0]);
        for(int i=0;i<n;i++)
        {
            dp[0][i][1] = dp[0][i][2] =dp[0][i][0];
        }
        for(int i =0 ;i<m;i++)
        {
            scanf("%d%d",&matches[match_count].first,&matches[match_count].second);
            if(matches[match_count].first != n && matches[match_count].second != n)
            match_count++;
        }
        match_count--;
        max_L = dp[0][n-1][0] + (m-match_count)*2;
//        cout<<max_L<<endl;
        int team[2];
        for(int i=1;i<=match_count;i++)
        {
            int min_set,max0[3] = {0};
            for(int j=0;j<n-1;j++)
            {
                for(int k=0;k<3;k++)
                max0[k] = max(dp[i-1][j][k],max0[k]);
            }
            int max1[3];
            //**//
            for(int j=0;j<3;j++)
            {
                max1[j] = max(max0[j],dp[i-1][matches[i].first-1][j]+2);
            }
            if(max1[0]<max1[1])
            {
                if(max1[0]<max1[2])
                    min_set = 0;
                else
                    min_set = 2;
            }else
            {
                if(max1[1]<max1[2])
                    min_set = 1;
                else
                    min_set = 2;
            }
            for(int j=0;j<n-1;j++)
                dp[i][j][0] = dp[i-1][j][min_set];
            dp[i][matches[i].first-1][0] += 2;

            //**//
            for(int j=0;j<3;j++)
            {
                max1[j] = max(max0[j],dp[i-1][matches[i].second-1][j]+2);
            }
            if(max1[0]<max1[1])
            {
                if(max1[0]<max1[2])
                    min_set = 0;
                else
                    min_set = 2;
            }else
            {
                if(max1[1]<max1[2])
                    min_set = 1;
                else
                    min_set = 2;
            }
            for(int j=0;j<n-1;j++)
                dp[i][j][1] = dp[i-1][j][min_set];
            dp[i][matches[i].second-1][1] += 2;

            //**//
            for(int j=0;j<3;j++)
            {
                max1[j] = max(max0[j],max(dp[i-1][matches[i].first-1][j]+1,dp[i-1][matches[i].second-1][j]+1));
            }
            if(max1[0]<max1[1])
            {
                if(max1[0]<max1[2])
                    min_set = 0;
                else
                    min_set = 2;
            }else
            {
                if(max1[1]<max1[2])
                    min_set = 1;
                else
                    min_set = 2;
            }
            for(int j=0;j<n-1;j++)
                dp[i][j][2] = dp[i-1][j][min_set];
            dp[i][matches[i].first-1][2]++;
            dp[i][matches[i].second-1][2]++;

//            for(int j=0;j<3;j++)
//            {
//                for(int k=0;k<n-1;k++)
//                cout<<dp[i][k][j]<<" ";
//                cout<<endl;
//            }
//            cout<<endl;
        }
        int min_set,max0[3] = {0};
        for(int j=0;j<n-1;j++)
        {
            for(int k=0;k<3;k++)
            max0[k] = max(dp[match_count][j][k],max0[k]);
        }
        min_set = min(max0[0],min(max0[1],max0[2]));
        if(min_set<max_L)
            cout<<"ACM United Wins\n";
        else
            cout<<"ACM United Loses\n";
    }
}
