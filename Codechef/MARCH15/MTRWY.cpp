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
struct query
{
    int type, x1, x2, y1, y2;
};
int grid[1001][1001];
int wallVert[1001][1001], wallHori[1001][1001];
int N, M, Q;
map<int, int> sizeToComp, compToSize;

int set_parent[1000101];
void set_union(int s1, int s2){
    if(s2 < s1)
        set_union(s2, s1);
    else{
        set_parent[s2] = s1;
    }
}
int set_find(int x){
    if(set_parent[x] == x)
        return x;
    return (set_parent[x]=set_find(set_parent[x]));
}

int bfs(int x, int y){
    grid[x][y] = (x-1)*M+y;
    queue<pair<int, int> > qq;
    qq.push(make_pair(x, y));
    int ret = 0;
    while(!qq.empty()){
        pair<int, int> cur = qq.front();
        qq.pop();
        ret++;
        int x = cur.first, y = cur.second;
        set_parent[(x-1)*M+y] = grid[x][y];
        if(y - 1 > 0 && !wallVert[x][y-1] && !grid[x][y-1])
            grid[x][y-1] = grid[x][y], qq.push(make_pair(x, y-1));
        if(x - 1 > 0 && !wallHori[x-1][y] && !grid[x-1][y])
            grid[x-1][y] = grid[x][y], qq.push(make_pair(x-1, y));
        if(y + 1 <= M && !wallVert[x][y] && !grid[x][y+1])
            grid[x][y+1] = grid[x][y], qq.push(make_pair(x, y+1));
        if(x + 1 <= N && !wallHori[x][y] && !grid[x+1][y])
            grid[x+1][y] = grid[x][y], qq.push(make_pair(x+1, y));
    }
    compToSize[grid[x][y]] = ret;
    if(sizeToComp.find(ret) == sizeToComp.end())
        sizeToComp[ret] = 0;
    sizeToComp[ret]++;
    return ret;
}
int main()
{
    in_T{
        sizeToComp.clear(), compToSize.clear();
        scanf("%d%d%d", &N, &M, &Q);
        std::vector<query> queries(Q);
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=M;j++)
                grid[i][j] = wallHori[i][j] = wallVert[i][j] = set_parent[(i-1)*M+j] = 0;

        for (int i = 0; i < Q; ++i)
        {
            in_I(queries[i].type);
            if(queries[i].type < 4){
                in_I(queries[i].x1);
                in_I(queries[i].y1);
            }
            if(queries[i].type == 3){
                in_I(queries[i].x2);
                in_I(queries[i].y2);
            }
            if(queries[i].type == 1){
                wallVert[queries[i].x1][queries[i].y1]++;
            }else if(queries[i].type == 2){
                wallHori[queries[i].x1][queries[i].y1]++;
            }
        }
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=M;j++)
                if(grid[i][j] == 0)
                    bfs(i, j);
        long long ans = 0;
        int prevAns = 0;
        for (int i = Q-1; i >= 0; --i)
        {
            query &q = queries[i];
            if(q.type == 4){
                ans += (--sizeToComp.end())->first;
            }else if(q.type == 3){
                int c1 = grid[q.x1][q.y1],
                    c2 = grid[q.x2][q.y2];
                // cout<<c1<<" "<<set_find(c1)<<", "<<c2<<" "<<set_find(c2)<<endl;
                ans += (set_find(c1) == set_find(c2));
            }else {
                if(q.type == 1){
                    wallVert[q.x1][q.y1]--;
                    if(wallVert[q.x1][q.y1])
                        continue;
                }else{
                    wallHori[q.x1][q.y1]--;
                    if(wallHori[q.x1][q.y1])
                        continue;
                }
                int c1 = grid[q.x1][q.y1], c2;
                if(q.type == 1)
                    c2 = grid[q.x1][q.y1+1];
                else
                    c2 = grid[q.x1+1][q.y1];
                c1 = set_find(c1);
                c2 = set_find(c2);
                if(c1 == c2)continue;
                if(c1 > c2)
                    swap(c1, c2);
                set_union(c1, c2);
                int s1 = compToSize[c1], s2 = compToSize[c2];
                int newSize = s1+s2;
                sizeToComp[s1]--, sizeToComp[s2]--;
                if(sizeToComp[s1] == 0)
                    sizeToComp.erase(s1);
                if(sizeToComp[s2] == 0)
                    sizeToComp.erase(s2);
                if(sizeToComp.find(newSize) == sizeToComp.end())
                    sizeToComp[newSize] = 0;
                sizeToComp[newSize]++;
                compToSize.erase(c2);
                compToSize[c1] = newSize;
            }
            // cout<<i<<" "<<ans-prevAns<<endl;
            // prevAns =  ans;
        }
        printf("%lld\n", ans);
    }
}
