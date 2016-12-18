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

int R, C;
char grid[101][101];
int vis[101][101][2];
int id_to_side[500];
pair<int, int> getPosFromId(int x){
    pair<int, int> curPos;
    int side_id = id_to_side[x];
    switch(side_id){
        case 0:
            curPos.first = -1;
            curPos.second = x-1;
            break;
        case 1:
            curPos.second = C;
            curPos.first = x-C-1;
            break;
        case 2:
            curPos.first = R;
            curPos.second = C-(x-R+C);
            break;
        case 3:
            curPos.second = -1;
            curPos.first = 2*(C+R)-x;
            break;
    }
    return curPos;
}
int dx[4] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int join(int x, int y){
    pair<int, int> curPos = getPosFromId(x);
    pair<int, int> finalPos = getPosFromId(y);
    int side_id = (x-1/4);
    int dir = -1;
    while(curPos != finalPos){
        for(int i = 0;i<4;i++){
            int nx = curPos.first+dx[i];
            int ny = curPos.second+dy[i];
            if(possible)
        }
    }
}
int main(){
   int z = 0; 
   int t;
   cin>>t;
   for(int z = 1;z<=t;z++){
       cin>>R>>C;
       int total = 2*(R+C);
       int mapping[total+1];
       for(int i = 1;i<=C;i++)
           id_to_side[i] = 0;
       for(int i = C+1;i<=C+R;i++)
           id_to_side[i] = 1;
       for(int i = C+R+1;i<=C+R+R;i++)
           id_to_side[i] = 2;
       for(int i = C+R+R+1;i<=2*(R+C);i++)
           id_to_side[i] = 3;
       vector<int> foo(total);
       memset(grid, 0, sizeof(grid));
       memset(vis, 0, sizeof(vis));
       for(int i = 0;i<total;i++){
           cin>>foo[i];
       }
       for(int i = 1;i<total;i+=2){
        mapping[foo[i]] = mapping[foo[i-1]];
        mapping[foo[i-1]] = mapping[foo[i]];
       }
       for(int i = 0;i<(1<<R*C);i++){
           if(check(i)){
            for(int j = 0;j<R*C;j++){
                if(i&(1<<j)){
                    cout<<grid[j/R][j%C];
                }
            }
           }
       }
       
       int done[total+1];
       memset(done, 0, sizeof(done));
       int rem = total;
       while(1){
           int prev = -1;
           bool flag = false;
           for(int i = 1;i<=total;i++){
               if(prev == -1){
                   if(!done[i])
                       prev = i;
               }else if(!done[i]){
                    if(mapping[i] == prev){
                        int resp = join(i, prev);
                        if(resp == -1){
                            break;
                        }else{
                            flag = true;
                            rem-=2;
                        }
                    }
               }
           }
           if(flag == false){
            cout<<"IMPOSSIBLE"<<endl;
            break;
           }else if(rem == 0){
            for(int i = 0;i<R;i++){
                for(int j = 0;j<C;j++)
                    cout<<char(grid[i][j]);
                cout<<endl;
            }
            break;
           }
       }
   }
}
