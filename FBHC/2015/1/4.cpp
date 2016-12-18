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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
vector<int> neigh[200001];
pair<long long, long long> mini[200001][2];
int N;
void getans(int idx){
    for(int i = 0;i<neigh[idx].size();i++)
        getans(neigh[idx][i]);
    int non = 0;
    int curGift = 1;
    mini[idx][0] = mini[idx][1] = make_pair(1e18, 1e18);
    long long tot = 0;
    map<int, long long> diffMap;
    for(int i = 0;i<neigh[idx].size();i++){
        int v = neigh[idx][i];
        tot += mini[v][0].first;
        if(diffMap.find(mini[v][0].second) == diffMap.end())
            diffMap[mini[v][0].second] = 0;
        diffMap[mini[v][0].second] += mini[v][1].first-mini[v][0].first;
    }
    while(curGift <= N && non < 2){
        pair<long long, long long> curRes;
        if(diffMap.find(curGift) != diffMap.end()){
            curRes = make_pair(tot+diffMap[curGift]+curGift, curGift);
        }else{
            non++;
            curRes = make_pair(tot+curGift, curGift);
        } 
        if(curRes < mini[idx][1])
            mini[idx][1] = curRes;
        if(mini[idx][1]<mini[idx][0])
            swap(mini[idx][0], mini[idx][1]);
        curGift++;
    }
}
int main()
{
    int z = 0;
    in_T{
        z++;
        cout<<"Case #"<<z<<": ";
        cin>>N;
        for(int i = 0;i<=N;i++)
            neigh[i].clear();
        for(int i = 0;i<N;i++){
            int x;
            cin>>x;
            neigh[x].push_back(i+1);
        }
        getans(1);
        cout<<mini[1][0].first<<endl;;
    }
}
