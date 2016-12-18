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
#include<set>
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
int m;
string k1, k2;
string getans(const string &str1, const string &str2)
{
    string ret = "";
    for(int i=0;i<str1.length();i++)
    {
        char a = str1[i], b = str2[i];
        if(isalpha(a) && isalpha(b))
        {
            if(a!=b)
                return "";
            else
                ret.push_back(a);
        }else if(isalpha(a))
        {
            ret.push_back(a);
        }else if(isalpha(b))
            ret.push_back(b);
        else if(a == b && a == '?')
            ret.push_back('a');
    }
    return ret;
}
int get_q(string &str)
{
    int ret = 0;
    for(int i=0;i<str.length();i++)
        ret += (str[i]=='?');
    return ret;
}
int main()
{
    int cc =0;
    in_T
    {
        cc++;
        in_I(m);
        cin>>k1>>k2;
        m = k1.length()/m;
        string sections1[k1.length()/m], sections2[k1.length()/m];
        for(int i=0;i<k1.length();i++)
        {
            sections1[i/m].push_back(k1[i]);
            sections2[i/m].push_back(k2[i]);
        }
        multiset<pair<string, int> > sec1[m+1], sec2[m+1];
        multiset<pair<string, int> >::iterator it1, it2;
        for(int i=0;i<k1.length()/m;i++)
        {
            sec1[get_q(sections1[i])].insert(make_pair(sections1[i],i));
        }
        for(int i=0;i<k1.length()/m;i++)
        {
            sec2[get_q(sections2[i])].insert(make_pair(sections2[i],i));
        }
        for(int i=0;i<=m;i++)
        {
            for(it1=sec1[i].begin();it1!=sec1[i].end();it1++)
            {
                for(int j=0;j<=m;j++)
                {
                    for(it2=sec2[j].begin();it2!=sec2[j].end();it2++)
                    {
                        string foo = getans(it1->first, it2->first);
//                        cout<<it1->first<<" "<<it2->first<<endl;
                        if(foo!= "")
                        {
                            sections1[it1->second] = foo;
                            sec2[j].erase(it2);
//                            cout<<sec2[j].size()<<endl;
                            j=m+1;
//                            cout<<"  "<<foo<<endl;
                            break;
                        }
                    }
                }
            }
        }
        int tot = 0;
        for(int i=0;i<=m;i++)
        {
            tot+=sec2[i].size();
        }
        cout<<"Case #"<<cc<<": ";
        if(tot!=0)
            cout<<"IMPOSSIBLE"<<endl;
        else
        {
            for(int i=0;i<k1.length()/m;i++)
                cout<<sections1[i];
            cout<<endl;
        }
    }
}
