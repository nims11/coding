/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int dp[101][101][5];
int main()
{
    string str;
    int n;
    cin>>n;
    cin>>str;
    for(int i = 0;i<str.length();i++){
        if(str[i] == '*'){
            for(int j = 0;j<=100;j++)
                dp[i+1][j][0] = 1;
        }
    }
    bool res = false;
    for(int i = 0;i<str.length();i++){
        if(str[i] == '*'){
            for(int j = 1;j<=4;j++){
                for(int k = 1;k<=i;k++){
                    int diff = i-k+1;
                    if(dp[k][diff][j-1]){
                        dp[i+1][diff][j] = 1;
                        if(j == 4)
                            res = true;
                    }
                }
            }
        }
    }
    cout<<(res?"yes":"no")<<endl;
}
