#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct recipe
{
    string str;
    int priority;
    friend bool operator<(const struct recipe &a,const struct recipe &b)
    {
        return a.priority>b.priority;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<struct recipe> RECIPES;
    struct recipe tmp;
    for(int i=0;i<n;i++)
    {
        cin>>tmp.str>>tmp.priority;
        RECIPES.push_back(tmp);
    }
    sort(RECIPES.begin(),RECIPES.end());
    int q;
    cin>>q;
    string query;
    for(int i=0;i<q;i++)
    {
        string ans="NO";
        cin>>query;
        for(int j=0;j<n;j++)
        {
            bool flag=true;
            if(query.size()<=RECIPES[j].str.size())
            for(int k=0;k<query.size();k++)
            {
                if(RECIPES[j].str[k]!=query[k])
                {
                    flag=false;
                    break;
                }
            }else
            flag=false;
            if(flag)
            {
                ans=RECIPES[j].str;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
