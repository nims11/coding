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
char str[10001];
pair<int, int> dispEnd[10001];
pair<int, int> dirs[4] = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};
int main()
{
    while(in_S(str) != EOF){
        int len = strlen(str);
        pair<int, int> cur = make_pair(0, 0);
        for(int i = len-1;i>=0;i--){
            if(str[i] == 'L'){
                swap(cur.first, cur.second);
                cur.first = -cur.first;
            }else if(str[i] == 'R'){
                swap(cur.first, cur.second);
                cur.second = -cur.second;
            }else if(str[i] == 'F'){
                cur.first++;
            }
//            cout<<cur.first<<" "<<cur.second<<endl;
            dispEnd[i] = cur;
        }
        dispEnd[len] = make_pair(0, 0);
        set<pair<int, int> > res;
        cur = make_pair(0, 0);
        int dir = 0;
//        cout<<endl;
        for(int i = 0;i<len;i++){
            pair<int, int> tmp;
            int dirNxt = (dir+1)%4, dirPrev = (dir-1+4)%4, dirCur = dir;
            if(str[i] == 'L'){
                dir = dirNxt;
                // F
                tmp = cur;
                tmp.first += dirs[dirCur].first+dispEnd[i+1].first*dirs[dirCur].first+dispEnd[i+1].second*(!dirs[dirCur].first);
                tmp.second += dirs[dirCur].second+dispEnd[i+1].second*(!dirs[dirCur].second)+dispEnd[i+1].first*dirs[dirCur].second;
                res.insert(tmp);
//                cout<<tmp.first<<" "<<tmp.second<<endl;
                // R
                tmp = cur;
                tmp.first += dispEnd[i+1].first*dirs[dirPrev].first+dispEnd[i+1].second*(!dirs[dirPrev].first);
                tmp.second += dispEnd[i+1].second*(!dirs[dirPrev].second)+dispEnd[i+1].first*dirs[dirPrev].second;
                res.insert(tmp);
//                cout<<tmp.first<<" "<<tmp.second<<endl;
            }else if(str[i] == 'R'){
                dir = dirPrev;
                // F
                tmp = cur;
                tmp.first += dirs[dirCur].first+dispEnd[i+1].first*dirs[dirCur].first+dispEnd[i+1].second*(!dirs[dirCur].first);
                tmp.second += dirs[dirCur].second+dispEnd[i+1].second*(!dirs[dirCur].second)+dispEnd[i+1].first*dirs[dirCur].second;
                res.insert(tmp);
//                cout<<tmp.first<<" "<<tmp.second<<endl;
                // L
                tmp = cur;
                tmp.first += dispEnd[i+1].first*dirs[dirNxt].first+dispEnd[i+1].second*(!dirs[dirNxt].first);
                tmp.second +=dispEnd[i+1].second*(!dirs[dirNxt].second)+dispEnd[i+1].first*dirs[dirNxt].second;
                res.insert(tmp);
//                cout<<tmp.first<<" "<<tmp.second<<endl;
            }else if(str[i] == 'F'){
                // L
                tmp = cur;
                tmp.first += dispEnd[i+1].first*dirs[dirNxt].first+dispEnd[i+1].second*(!dirs[dirNxt].first);
                tmp.second +=dispEnd[i+1].second*(!dirs[dirNxt].second)+dispEnd[i+1].first*dirs[dirNxt].second;
                res.insert(tmp);
//                cout<<tmp.first<<" "<<tmp.second<<endl;
                // R
                tmp = cur;
                tmp.first += dispEnd[i+1].first*dirs[dirPrev].first+dispEnd[i+1].second*(!dirs[dirPrev].first);
                tmp.second += dispEnd[i+1].second*(!dirs[dirPrev].second)+dispEnd[i+1].first*dirs[dirPrev].second;
                res.insert(tmp);

                cur.first += dirs[dir].first;
                cur.second += dirs[dir].second;
            }
        }
        printf("%d\n", res.size());
    }
}
