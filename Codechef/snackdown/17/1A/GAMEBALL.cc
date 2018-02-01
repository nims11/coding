#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()
using namespace std;
int n, m;
char str[12][12];
struct Move{
    int x1, y1, x2, y2;
};

void solve_col(int idx, vector<Move> &moves){
    int rem = 0;
    for(int i = 0;i<n-2;i++){
        if(str[i][idx] == '.' && str[i+1][idx] == '*' && str[i+2][idx] == '*'){
            str[i][idx] = '*';
            str[i+1][idx] = '.';
            str[i+2][idx] = '.';
            moves.push_back({i+2, idx, i, idx});
        }
    }
    if(str[0][idx] == '*' && str[1][idx] == '.'){
        swap(str[0][idx], str[1][idx]);
        moves.push_back({0, idx, 1, idx});
    }

    for(int i = 2;i<n;i++){
        if(str[i][idx] == '.' && str[i-1][idx] == '*' && str[i-2][idx] == '*'){
            str[i][idx] = '*';
            str[i-1][idx] = str[i-2][idx] = '.';
            moves.push_back({i-2, idx, i, idx});
        }
    }
    int st = 0;
    for(int i = 0;i<n;i++){
        if(str[i][idx] == '*'){
            for(int j = i-1;j>=st;j--){
                swap(str[j+1][idx], str[j][idx]);
                moves.push_back({j+1, idx, j, idx});
            }
            st++;
        }
    }
    if(st > 1)
        solve_col(idx, moves);
}
void solve_row(int idx, vector<Move> &moves){
    int rem = 0;
    if(m > 2)
    for(int i = 0;i<m-2;i++){
        if(str[idx][i] == '.' && str[idx][i+1] == '*' && str[idx][i+2] == '*'){
            str[idx][i] = '*';
            str[idx][i+1] = '.';
            str[idx][i+2] = '.';
            moves.push_back({idx, i+2, idx, i});
        }
    }
    if(str[idx][0] == '*' && str[idx][1] == '.'){
        swap(str[idx][0], str[idx][1]);
        moves.push_back({idx, 0, idx, 1});
    }
    if(m > 2)
    for(int i = 2;i<m;i++){
        if(str[idx][i] == '.' && str[idx][i-1] == '*' && str[idx][i-2] == '*'){
            str[idx][i] = '*';
            str[idx][i-1] = str[idx][i-2] = '.';
            moves.push_back({idx, i-2, idx, i});
        }
    }
    int st = 0;
    for(int i = 0;i<m;i++){
        if(str[idx][i] == '*'){
            for(int j = i-1;j>=st;j--){
                swap(str[idx][j+1], str[idx][j]);
                moves.push_back({idx, j+1, idx, j});
            }
            st++;
        }
    }
    if(st > 1)
        solve_row(idx, moves);
}
int main(){
    in_T{
        in_I(n); in_I(m);
        vector<Move> moves;
        for(int i = 0;i<n;i++)
            in_S(str[i]);
        if(n * m == 2){
            printf("0\n");
            continue;
        }
        if(n < 3 && m < 3){
            printf("-1\n");
            continue;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(str[i][j] == '.'){
                    while(i>0){
                        swap(str[i-1][j], str[i][j]);
                        moves.push_back({i-1, j, i, j});
                        i--;
                    }
                    while(j>0){
                        swap(str[0][j-1], str[0][j]);
                        moves.push_back({0, j-1, 0, j});
                        j--;
                    }
                    goto lol;
                }
            }
        }
lol:
        solve_row(0, moves);
        for(int i = min(1, m-1);i<m;i++){
            solve_col(i, moves);
        }

        if(m > 1 && n > 1){
            swap(str[0][1], str[1][1]);
            moves.push_back({0, 1, 1, 1});
            swap(str[0][0], str[0][1]);
            moves.push_back({0, 0, 0, 1});
            solve_row(0, moves);
            swap(str[0][0], str[0][1]);
            moves.push_back({0, 0, 0, 1});
            solve_col(0, moves);

            if(m > 2){
                for(int i = m-2;i>=0;i--){
                    if(str[0][i] == '*' && str[0][i+1] == '.'){
                        swap(str[0][i], str[0][i+1]);
                        moves.push_back({0, i, 0, i+1});
                    }
                }
                solve_row(0, moves);
                swap(str[1][1], str[0][1]);
                moves.push_back({1, 1, 0, 1});
                solve_row(0, moves);
            }else{
                for(int i = n-2;i>=0;i--){
                    if(str[i][0] == '*' && str[i+1][0] == '.'){
                        swap(str[i][0], str[i+1][0]);
                        moves.push_back({i, 0, i+1, 0});
                    }
                }
                solve_col(1, moves);
                swap(str[0][1], str[0][0]);
                moves.push_back({0, 1, 0, 0});
                solve_col(0, moves);
            }
        }

        /* for(int i = 0;i<n;i++) */
        /*     cout<<str[i]<<endl; */
        printf("%d\n", moves.size());
        for(auto move_: moves){
            printf("%d %d %d %d\n", move_.x1+1, move_.y1+1, move_.x2+1, move_.y2+1);
        }
    }
}
