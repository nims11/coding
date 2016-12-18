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
int arr[3001];
int visited[3001];
vector<pair<int, int> > res;
int dfs(int cur, int len=0){
    if(visited[cur] == 1)
        return len;
    visited[cur] = 1;
    return dfs(arr[cur]-1, len+1);
}
vector<pair<int, int> > sets;
int calcM(){
    int ret = 0;
    for(int i = 0;i<n;i++){
        if(!visited[i])
        {
            int tmp = dfs(i)-1;
            sets.push_back(make_pair(tmp, i));
            ret += tmp;
        }
//        cout<<endl;
    }
    return ret;
}
void getItems(int i, vector<int> &items, int tar){
    if(items.size() == tar)
        return;
    items.push_back(i);
    getItems(arr[i]-1, items, tar);
}
void deleteEdges(int X){
    int cur = 0;
    while(X>1 && cur<n){
        if(cur == arr[arr[cur]-1]-1){
            swap(arr[cur], arr[arr[cur]-1]);
            res.push_back(make_pair(cur+1, arr[cur]));
            X-=2;
        }
        cur++;
    }
    if(X){
        for(int i = 0;i<sets.size();i++){
            if(sets[i].first > 1){
                vector<int> items;
                getItems(sets[i].second, items, sets[i].first);
                int cnt = sets[i].second;
                int cur = items.size()-1;
                while(X){
                    if(cnt == 1){
                        if(X>1)
                            X--;
                        else
                            break;
                    }else
                    X--;
                    cnt--;
                    res.push_back(make_pair(items[0], items[cur--]));
                }
            }
        }
    }
}
void addEdges(int X){

}
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cin>>m;
    int curM = calcM();
    sort(sets.begin(), sets.end());
    if(curM>m){
        deleteEdges(curM-m);
    }else if(curM<m){
        addEdges(m-curM);
    }
    cout<<res.size()<<endl;
    for(int i = 0;i<res.size();i++)
        cout<<res[i].first<<" "<<res[i].second<<" ";
}
