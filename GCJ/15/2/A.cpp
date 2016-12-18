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
int r, c;
map<char, int> D;
string grid[200];
int foo[200][200];
int main()
{
    D['^'] = 1;
    D['>'] = 2;
    D['<'] = 3;
    D['v'] = 4;
    int z = 0;
    in_T{
        z++;
        cin>>r>>c;
        memset(foo, 0, sizeof(foo));
        for(int i = 0;i<r;i++){
            cin>>grid[i];
        }
        for(int i = 0;i<r;i++){
            pair<int, int> first_left, last_right;
            first_left = last_right = make_pair(-1, -1);
            for(int j = 0;j<c;j++){
                if(grid[i][j] != '.' && first_left.first == -1)
                    first_left = make_pair(i, j);
                if(grid[i][j] != '.')
                    last_right = make_pair(i, j);
            }
            if(first_left.first >= 0 && grid[first_left.first][first_left.second] == '<')
                foo[first_left.first][first_left.second] = 1;
            if(last_right.first >= 0 && grid[last_right.first][last_right.second] == '>')
                foo[last_right.first][last_right.second] = 1;
        }
        for(int i = 0;i<c;i++){
            pair<int, int> first_left, last_right;
            first_left = last_right = make_pair(-1, -1);
            for(int j = 0;j<r;j++){
                if(grid[j][i] != '.' && first_left.first == -1)
                    first_left = make_pair(j, i);
                if(grid[j][i] != '.')
                    last_right = make_pair(j, i);
            }
            if(first_left.first >= 0 && grid[first_left.first][first_left.second] == '^')
                foo[first_left.first][first_left.second] = 1;
            if(last_right.first >= 0 && grid[last_right.first][last_right.second] == 'v')
                foo[last_right.first][last_right.second] = 1;
        }
        int cnt_row[200] = {0}, cnt_col[200] = {0};
        for(int i = 0;i<r;i++)
            for(int j = 0;j<c;j++)
                if(grid[i][j] != '.')
                    cnt_col[j]++, cnt_row[i]++;
        bool flag = true;
        int res = 0;
        for(int i = 0;i<r;i++)
            for(int j = 0;j<c;j++)
                if(foo[i][j]){
                    if(cnt_row[i] > 1|| cnt_col[j] > 1)
                        res++;
                    else
                        flag = false;
                }
        if(!flag)
            res = -1;
        cout<<"Case #"<<z<<": ";
        if(res == -1)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<res<<endl;
    }
}
