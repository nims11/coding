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
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
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

using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int grid[n][m];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            grid[i][j] = 0;
    vector<vector<pair<int, int> > > res;
    int rem = n*m;
    int curI = 0, curJ = 0;
    pair<int, int> dir = make_pair(0, 1);
    while(k){
        int sz = (k==1)?rem:2;
        vector<pair<int, int> > cur;
        while(sz){
            grid[curI][curJ] = 1;
            rem--;
            sz--;
            cur.push_back(make_pair(curI, curJ));
            curI += dir.first;
            curJ += dir.second;
            if(curJ == m){
                curJ = m-1;
                curI++;
                dir = make_pair(1, 0);
            }else if(curI == n){
                curI = n-1;
                curJ--;
                dir = make_pair(0, -1);
            }else if(curJ == -1){
                curJ = 0;
                curI--;
                dir = make_pair(-1, 0);
            }else if(curI == -1){
                curI = 0;
                curJ++;
                dir = make_pair(0, 1);
            }else if(grid[curI][curJ]){
                if(dir.first == 1){
                    curI--;
                    curJ--;
                    dir = make_pair(0, -1);
                }else if(dir.first == -1){
                    curI++;
                    curJ++;
                    dir = make_pair(0, 1);
                }else if(dir.second == 1){
                    curI++;
                    curJ--;
                    dir = make_pair(1, 0);
                }else if(dir.second == -1){
                    curI--;
                    curJ++;
                    dir = make_pair(-1, 0);
                }
            }
        }
        res.push_back(cur);
        k--;
    }
    for(int i = 0;i<res.size();i++){
        cout<<res[i].size()<<" ";
        for(int j = 0;j<res[i].size();j++){
            cout<<res[i][j].first+1<<" "<<res[i][j].second+1<<" ";
        }
        cout<<endl;
    }
}
