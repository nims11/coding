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
#include<utility>
#define in_T int t;for(scanf("%d\n",&t);t--;)
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
    int c = 0;
    in_T
    {
        c++;
        string str;
        getline(cin, str);
        vector<int> paren;
        bool flag  = true;
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == '(')
            {
                paren.push_back(0);
            }else if(str[i] == ')')
                paren.push_back(2);
            else if(str[i] == ':' && i!=str.size()-1)
            {
                if(str[i+1] == ')')
                    {paren.push_back(3);i++;}
                else if(str[i+1] == '(')
                    {paren.push_back(1);i++;}
            }else if(!(str[i]>='a' && str[i]<='z') && str[i]!=' ' && str[i]!=':')
            {
                flag = false;
                break;
            }
        }
        if(!flag)
        {
            printf("Case #%d: NO\n", c);
            continue;
        }
        if(paren.size()==0)
        {
            printf("Case #%d: YES\n", c);
            continue;
        }
        bool dp[paren.size()][101];
        for(int i=0;i<paren.size();i++)
        {
            for(int j=0;j<=100;j++)
                dp[i][j] = false;
        }
        switch(paren[0])
        {
            case 0:
                dp[0][1] = true;
            break;

            case 1:
                dp[0][1] = dp[0][0] = true;
            break;

            case 2:
                flag = false;
            break;

            case 3:
                dp[0][0] = true;
            break;
        }
        if(flag)
        {
            for(int i=1;i<paren.size();i++)
            {
                int cnt = 0;
                for(int j=0;j<=100;j++)
                {
                    if(dp[i-1][j])
                    {
                        switch(paren[i])
                        {
                            case 0:
                                dp[i][j+1] = true;
                                cnt++;
                            break;

                            case 1:
                                dp[i][j] = dp[i][j+1] = true;
                                cnt+=2;
                            break;

                            case 2:
                                if(j-1>=0)
                                {
                                    dp[i][j-1] = true;
                                    cnt++;
                                }
                            break;

                            case 3:
                                dp[i][j] = true;
                                cnt++;
                                if(j-1>=0)
                                {
                                    dp[i][j-1] = true;
                                    cnt++;
                                }
                            break;
                        }
                    }
                }
                if(cnt == 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(!flag)
        {
            printf("Case #%d: NO\n", c);
        }else
        {
            if(dp[paren.size()-1][0])
            {
                printf("Case #%d: YES\n", c);
            }else
                printf("Case #%d: NO\n", c);
        }
    }
}
