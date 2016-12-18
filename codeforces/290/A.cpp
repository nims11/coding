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
int adj[26][26], root[26];
vector<char> res;
int vis[26];
bool dfs(int idx){
    res.push_back(idx+'a');
    bool ret = true;
    for(int i = 0;i<26;i++){
        if(adj[idx][i]){
            vis[i]--;
            if(vis[i]<0)
                return false;
            if(vis[i] == 0){
                ret &= dfs(i);
                vis[i]--;
            }
            if(!ret)
                return ret;
        }
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    vector<string> arr;
    string str;

    for(int i = 0;i<n;i++){
        cin>>str;
        arr.push_back(str);
    }
    for(int i = 0;i<26;i++)
        for(int j = 0;j<26;j++)
            adj[i][j] = 0;
    int nn = 0;
    for(int i = 1;i<n;i++){
        int idx = 0;
        while(idx < min(arr[i].size(), arr[i-1].size()) && arr[i-1][idx] == arr[i][idx])
            idx++;
        if(idx < min(arr[i].size(), arr[i-1].size())){
            int c1 = arr[i-1][idx]-'a', c2 = arr[i][idx]-'a';
            if(!adj[c1][c2])
            adj[c1][c2] = 1, vis[c2]++;
            nn++;
        }else if(arr[i].size() < arr[i-1].size()){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    for(int i = 0;i<26;i++){
        if(vis[i] != 0)
            continue;
        if(!dfs(i)){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    if(res.size() != 26){
        cout<<"Impossible"<<endl;
        return 0;
    }
    for(int i = 0;i<26;i++)
        cout<<res[i];
    cout<<endl;
}
