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
#include<cmath>
#include<stack>
#include<utility>
#include<sstream>
#define in_T int t;for(scanf("%d\n\n",&t);t--;)
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
vector<int> blank;
int main()
{
    in_T
    {
        string str;
        vector< vector<int> > adj;
        map<string, int> str_int;
        map<string, int>::iterator it1;
        map<int, string> int_str;
        int cnt = 0;
        while(getline(cin, str))
        {
            if(str=="")break;
            stringstream ss(str);
            string str1;
            ss>>str1;
            it1 = str_int.find(str1);
            int id;
            if(it1 == str_int.end())
            {
                str_int[str1] = cnt;
                int_str[cnt] = str1;
                id = cnt;
                cnt++;
                adj.push_back(blank);
            }else
                id = it1->second;
            while(ss>>str1)
            {
                it1 = str_int.find(str1);
                int id2;
                if(it1 == str_int.end())
                {
                    str_int[str1] = cnt;
                    int_str[cnt] = str1;
                    id2 = cnt;
                    cnt++;
                }else
                    id2 = it1->second;
                adj[id].push_back(id2);
            }
        }
        int done[cnt];
        for(int i=0;i<cnt;i++)
            done[i] = 0;
        vector<pair<int, string> > ans;
        vector<int> adj2[cnt];
        for(int i=0;i<cnt;i++)
        {
            for(int j=0;j<adj[i].size();j++)
                adj2[adj[i][j]].push_back(i);
        }
        queue<pair<int, int> > BFS;
        for(int i=0;i<cnt;i++)
        {
            if(adj[i].size() == 0)
                BFS.push(make_pair(i,1));
        }
        pair<int, int> tmp;
        while(!BFS.empty())
        {
            tmp = BFS.front();
            BFS.pop();
            done[tmp.first]  = 1;
            ans.push_back(make_pair(tmp.second, int_str[tmp.first]));
            for(int i=0;i<adj2[tmp.first].size();i++)
            {
                bool flag = true;
                for(int j=0;j<adj[adj2[tmp.first][i]].size();j++)
                {
                    if(!done[adj[adj2[tmp.first][i]][j]])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    BFS.push(make_pair(adj2[tmp.first][i], tmp.second+1));
            }
        }
        sort(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i].second<<" ";
        newline;
    }
}
