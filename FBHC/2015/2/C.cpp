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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
int trie[2000000][26];
int subSize[2000000][26];
int dp[2000000][101];
int wordEnd[2000000];
int cnt;
void addTrie(string &str){
    int cur = 1;

    for(int i = 0;i<str.size();i++){
        int b = str[i]-'a';
        if(trie[cur][b] == 0){
            subSize[cur][b] = 0;
            trie[cur][b] = ++cnt;
            if(cnt >= 2000000)
                cerr<<"ERROR!!"<<endl;
        }
        subSize[cur][b]++;
        cur = trie[cur][b];
    }
    wordEnd[cur] = true;
}

int N, K;
void computeDP(int idx){
    int tot = 0;
//    cout<<"Entering "<<idx<<endl;
    int x;
//    cin>>x;
    for(int i = 0;i<26;i++){
        if(trie[idx][i]){
//            cout<<idx<<" "<<i<<" "<<trie[idx][i]<<endl;
//            cin>>x;
            computeDP(trie[idx][i]), tot += subSize[idx][i];
        }
    }
//    cout<<"Finished "<<idx<<endl;
//    return;
    dp[idx][1] = 1;
    dp[idx][0] = 0;
    if(!tot)return;
    cout<<idx<<" "<<tot<<endl;
    int prev = -1;
    for(int i = 0;i<26;i++){
        if(trie[idx][i]){
            if(prev == -1){
                prev = trie[idx][i];
                for(int j = 0;j<=K;j++)if(dp[prev][j] != -1)
                    dp[idx][j] = dp[prev][j] + j;
                dp[idx][1] = 1;
            }else{
                int cur = trie[idx][i];
                int DP[101];
                for(int i = 0;i<=100;i++)
                    DP[i] = -1;
                prev = idx;
                for(int j = 0;j<=K;j++)
                    for(int k = 0;k<=K;k++){
                        if(j+k<=100 && dp[prev][j] != -1 && dp[cur][k] != -1){
                            if(DP[j+k] == -1)
                                DP[j+k] = (j==1?1:dp[prev][j]+j) + (k==1?1:dp[cur][k]+k);
                            else
                                DP[j+k] = min(DP[j+k], (j==1?1:dp[prev][j]+j) + (k==1?1:dp[cur][k]+k));
                        }
                    }
                for(int i = 0;i<101;i++)
                    dp[idx][i] = DP[i];
            }
        }
    }
    if(wordEnd[idx]){
        for(int i = K-1;i>=0;i--){
            if(dp[idx][i] != -1){
                if(dp[idx][i+1] == -1)
                    dp[idx][i+1] = dp[idx][i];
                else
                    dp[idx][i+1] = min(dp[idx][i+1], dp[idx][i]);
            } 
        }
    }
    for(int i = 0;i<=10;i++)
        cout<<dp[idx][i]<<" ";
    cout<<endl;
}
int main()
{
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        cnt = 1;
        for(int k = 0;k<2000000;k++)
            for(int i = 0;i<26;i++)
                trie[k][i] = subSize[k][i] = 0;
        for(int i = 0;i<2000000;i++)
            for(int j = 0;j<=100;j++)
                dp[i][j] = -1;
        for(int i = 0;i<2000000;i++)
            wordEnd[i] = 0;

        cin>>N>>K;
        for(int i = 0;i<N;i++){
            string str;
            cin>>str;
            addTrie(str);
        }
        computeDP(1);
        cout<<dp[1][K]<<endl;
    }
}
