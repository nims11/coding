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
int main()
{
    in_T{
        string str;
        cin>>str;
        vector<pair<int, int> > foo;
        int bar[26] = {0};
        for(int i = 0;i<str.size();i++)
            bar[str[i]-'a']++;
        for(int i = 0;i<26;i++)
            foo.push_back(make_pair(bar[i], i));
        sort(BE(foo));
        sort(BE(str));
        vector<vector<int> > fox(foo[25].first);
        int cur = 0;
        for(int i = 0;i<25;i++){
            for(int j = 0;j<foo[i].first;j++){
                fox[cur++].push_back(foo[i].second);
                cur %= fox.size();
            }
        }
        bool flag = true;
        string newstr;
        for(int i = 0;i<fox.size();i++){
            newstr.push_back(foo[25].second+'a');
            if(i < fox.size()-1 && fox[i].size() == 0)flag = false;
            for(int j = 0;j<fox[i].size();j++)
                newstr.push_back(fox[i][j]+'a');
        }
        if(flag)
            cout<<newstr<<endl;
        else
            cout<<-1<<endl;
    }
}
