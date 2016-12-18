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
char grid[3001][3001];
int cnt_alpha[2][3001][26];
int cnt[2][3001];
int vis[2][3001];
vector<tuple<char, int, char>> answer;
int main(){
    int n;
    in_I(n);
    for(int i = 0;i<n;i++){
        in_S(grid[i]);
        for(int j = 0;j<n;j++){
            if(grid[i][j]== '?')continue;

            if(cnt_alpha[0][i][grid[i][j]-'a'] == 0)
                cnt[0][i]++;
            cnt_alpha[0][i][grid[i][j]-'a']++;

            if(cnt_alpha[1][j][grid[i][j]-'a'] == 0)
                cnt[1][j]++;
            cnt_alpha[1][j][grid[i][j]-'a']++;
        }
    }

    stack<pair<int, int>> q;

    for(int z = 0;z<2;z++){
        for(int i = 0;i<n;i++){
            q.push({z, i});
        }
    }
    while(!q.empty()){
        pair<int, int> cur = q.top();
        q.pop();
        int z = cur.first;
        int i = cur.second;
        if(vis[z][i] || cnt[z][i] > 1)
            continue;

        if(cnt[z][i] == 0){
            answer.push_back(make_tuple(z==0?'h':'v', i+1, 'x'));
            vis[z][i] = 1;
            continue;
        }

        vis[z][i] = 1;
        cnt[z][i] = 0;
        char paint_c = -1;
        for(int j = 0;j<n;j++){
            char &ch = z==0?grid[i][j]:grid[j][i];
            if(ch !='?'){
                paint_c = ch;
                cnt_alpha[z][i][ch-'a'] = 0;
                cnt_alpha[!z][j][ch-'a']--;
                if(cnt_alpha[!z][j][ch-'a'] == 0){
                    cnt[!z][j]--;
                    if(cnt[!z][j] == 1 || (cnt[!z][j] == 0 && !vis[!z][j])){
                        q.push({!z, j});
                    }
                }
                ch = '?';
            }
        }
        answer.push_back(make_tuple(z==0?'h':'v', i+1, paint_c));
    }

    reverse(answer.begin(), answer.end());
    for(auto ans: answer)
        printf("%c %d %c\n", get<0>(ans), get<1>(ans), get<2>(ans));
}
