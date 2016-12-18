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
int n, m;
vector<int> shop[100001];
int start[100001];
int crcnt[100001];
vector<int> endst[100001];
int main()
{
    in_T{
        in_I(n);in_I(m);
        for(int i = 0;i<=m;i++)
            crcnt[i] = 0;
        for(int i = 0;i<n;i++){
            int x, y;
            endst[i].clear();
            in_I(x);
            shop[i].clear();
            for(int j = 0;j<x;j++){
                in_I(y);
                shop[i].push_back(y);
            }
        }
        int curcnt = 0;
        int curend = 0;
        while(curcnt < m){
            for(int i = 0;i<shop[curend].size();i++){
                int x = shop[curend][i];
                crcnt[x]++;
                if(crcnt[x] == 1)
                    curcnt++;
            }
            curend++;
        }
        start[0] = curend;
        endst[curend].push_back(curend);
        for(int i = 1;i<n;i++){
            for(int j = 0;j<shop[i-1].size();j++){
                int x = shop[i-1][j];
                crcnt[x]--;
                if(crcnt[x] == 0)
                    curcnt--;
            }
            bool flag = true;
            while(curcnt < m){
                if(curend == n){
                    flag = false;
                    break;
                }
                for(int j = 0;j<shop[curend].size();j++){
                    int x = shop[curend][j];
                    crcnt[x]++;
                    if(crcnt[x] == 1)
                        curcnt++;
                }
                curend++;
            }
            if(!flag)
                start[i] = -1;
            else{
                start[i] = curend; endst[curend].push_back(curend-i);
            }
        }
/*        for(int i = 0;i<n;i++)
            cout<<start[i]<<" ";
        cout<<endl;*/
        map<int, set<int> > foo;
        map<int, set<int> >::iterator it;
        set<int> bar;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<endst[i].size();j++){
                it = foo.find(endst[i][j]);
                it->second.erase(i-endst[i][j]);
                if(it->second.size() == 0)
                    foo.erase(it);
                bar.insert(endst[i][j]-i);
            }
            if(start[i] != -1){
                it = foo.find(start[i]-i);
                if(it != foo.end())
                    it->second.insert(i);
                else{
                    foo[start[i]-i] = set<int> () ;
                    foo[start[i]-i].insert(i);
                }
            }
            int res = n;
            pair<int, int> ress = make_pair(0, n-1);
            if(foo.size() > 0){
                if(foo.begin()->first < res){
                    res = foo.begin()->first;
                    ress = make_pair(*(foo.begin()->second.begin()), 0);
                    ress.second = res+ress.first-1;
                }
            }
            if(bar.size() > 0){
                int x = i-(-(*bar.begin()))+1;
                if(x <= res){
                    res = x;
                    ress = make_pair(i-res+1, i);
                }
            }
            printf("%d %d\n", ress.first+1, ress.second+1);
        }
    }
}
