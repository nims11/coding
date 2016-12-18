#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

string str1, str2;
int n;
int dp1[100010][27];
int dp2[100010][27];
int getLeft(int idx, int c){
    if(idx < 0)
        return 0;
    if(dp1[idx][c-'A'] != -1)
        return dp1[idx][c-'A'];
    if(str2[idx] == c)
        return dp1[idx][c-'A'] = getLeft(idx-1, c);
    return (dp1[idx][c-'A'] = 1+getLeft(idx-1, str2[idx]));
}
int getLeft(int idx){
    if(idx < 0)
        return 0;
    if(dp1[idx][26] != -1)
        return dp1[idx][26];
    if(str1[idx] == str2[idx])
        return dp1[idx][26] = getLeft(idx-1);
    return (dp1[idx][26] = getLeft(idx-1, str2[idx])+1);
}
int getRight(int idx, int c){
    if(idx >= n)
        return 0;
    if(dp2[idx][c-'A'] != -1)
        return dp2[idx][c-'A'];
    if(str2[idx] == c)
        return dp2[idx][c-'A'] = getRight(idx+1, c);
    return dp2[idx][c-'A'] = 1+getRight(idx+1, str2[idx]);
}
int getRight(int idx){
    if(idx >= n)
        return 0;
    if(dp2[idx][26] != -1)
        return dp2[idx][26];
    if(str1[idx] == str2[idx])
        return dp2[idx][26] = getRight(idx+1);
    return (dp2[idx][26] = getRight(idx+1, str2[idx])+1);
}
int main(){
    int z = 0;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>str1>>str2;
        for(int i = 0;i<=100002;i++)
            for(int j = 0;j<=26;j++)
                dp1[i][j] = dp2[i][j] = -1;
        int ans = 1000000;
        for(int i = -1;i<n;i++){
            int leftAns = 0, rightAns = 0;
                leftAns = getLeft(i);
                rightAns = getRight(i+1);
            ans = min(ans, max(leftAns, rightAns));
        }
        cout<<"Case #"<<(++z)<<": "<<ans<<endl;
    }
}
