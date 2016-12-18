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
vector<pair<int, string> > w[3];
vector<int> strs[3];
map<string, int> w_str[3];
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
vector<pair<int, int> > flag_w12[3000000];
int main()
{
    for(int i = 0;i<3;i++){
        int m;
        cin>>m;
        for(int j = 0;j<m;j++){
            string str;int stren;
            cin>>str>>stren;
            w_str[i][str] = stren;
            w[i].push_back(make_pair(stren, str));
        }
        sort(BE(w[i]));
        for(int j = 0;j<m;j++)
            strs[i].push_back(w[i][j].first);
    }
    cerr<<"Precomputing Stuffs"<<endl;
    for(int i = 0;i<w[1].size();i++)
        for(int j = 0;j<w[0].size();j++)
            flag_w12[w[1][i].first+w[0][j].first].push_back(make_pair(j, i));
    int t;
    cin>>t;
    vector<pair<int, int> > q;
    for(int i = 0;i<t;i++){
        string str[3];
        int tmp = 0;
        for(int j = 0;j<3;j++){
            cin>>str[j];
            tmp += w_str[j][str[j]];
        }
        q.push_back(make_pair(i, tmp+1));
    }
    cerr<<"Processing Query"<<endl;
    sort(BE(q), cmp);
    vector< pair<int, string> > ans;
    for(int i = 0;i<q.size();i++){
        cerr<<"Query "<<i<<endl;
        // cout<<q[i].first<<" "<<q[i].second<<endl;
        for(int j = 0;j<w[2].size();j++){
            int req = q[i].second - w[2][j].first;
            if(req < 0 || flag_w12[req].size() == 0)continue;
            for(int k = 0;k<flag_w12[req].size();k++){
                ans.push_back( make_pair(q[i].first, w[0][flag_w12[req][k].first].second + " " +
                        w[1][flag_w12[req][k].second].second + " " +
                        w[2][j].second));
                assert(q[i].second == w[0][flag_w12[req][k].first].first+w[1][flag_w12[req][k].second].first+w[2][j].first);
                if(i < q.size()-1 && q[i+1].second == q[i].second){
                    i++;
                }else{
                    j = w[2].size();
                    break;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0;i<ans.size();i++)
        cout<<ans[i].second<<endl;
}
