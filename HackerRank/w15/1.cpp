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
int grid[9][9];
bool valid(){
    set<int> x, y, z;
    int st_x = 0, st_y = 0;
    for(int i = 0;i<9;i++){
        int x[10] = {0}, y[10] = {0}, z[10] = {0};
        int cur_x = 0, cur_y = 0;
        for(int j = 0;j<9;j++){
            x[grid[i][j]]++;
            y[grid[j][i]]++;
            z[grid[st_x+cur_x][st_y+cur_y]]++;
            cur_y++;
            if(cur_y == 3)
                cur_y = 0, cur_x++;
        }
        st_x += 3;
        if(st_x == 9)
            st_x = 0, st_y += 3;
        for(int i = 1;i<=9;i++)
            if(x[i] != 1 || y[i] != 1 || z[i] != 1)return false;
    }
    return true;
}
int main()
{
int z = 0;
    in_T{
        z++;
        for(int i = 0;i<9;i++)
            for(int j = 0;j<9;j++)
                in_I(grid[i][j]);
        printf("Case #%d:\n", z);
        if(valid()){
            printf("Serendipity\n");
        }else{
            vector<pair<pair<int, int>, pair<int, int> > > x;
            for(int x1 = 0;x1 < 9;x1++)
                for(int y1 = 0;y1 < 9;y1++){
                    for(int x2 = 0;x2 < 9;x2++){
                        for(int y2 = 0;y2 < 9;y2++){
                            if(x2 == x1 && y2 == y1)continue;
                            if(x1 > x2 || (x1 == x2 && y1 >= y2))continue;
                            swap(grid[x1][y1], grid[x2][y2]);
                            if(valid())
                                x.push_back(make_pair(make_pair(x1+1, y1+1), make_pair(x2+1, y2+1)));
                            swap(grid[x1][y1], grid[x2][y2]);
                        }
                    }
                }
            sort(BE(x));
            for(int i = 0;i<x.size();i++){
                int x1 = x[i].first.first,
                    y1 = x[i].first.second,
                    x2 = x[i].second.first,
                    y2 = x[i].second.second;
                printf("(%d,%d) <-> (%d,%d)\n", x1, y1, x2, y2);
            }
        }
    }
}
