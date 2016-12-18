/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<sstream>
#define in_T int t;for(scanf("%d",&t),cin.ignore(1);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
map <int,string> id_str;
int prio[3003]={0};
struct kkk{
 int d;
friend bool operator<(const kkk &a,const kkk &b)
{
    if(prio[a.d]!=prio[b.d])return prio[a.d]>prio[b.d];
    return id_str[a.d]<id_str[b.d];
}
}lll;
int main()
{
    string tmp1,tmp2;
    in_T
    {
        id_str.clear();
        map <string,int> str_id;
        map <string,int>::iterator it2;
        getline(cin,tmp1);
        getline(cin,tmp2);
        stringstream ss1(tmp1),ss2(tmp2);
        int n=0,id1,id2;
        vector < vector<int> > friends(3003);
        while(ss1>>tmp1)
        {
            ss2>>tmp2;
            it2=str_id.find(tmp1);
            if(it2==str_id.end())
            {
                str_id[tmp1]=n;
                id_str[n]=tmp1;
                id1=n;
                n++;
            }else
            id1=it2->second;

            it2=str_id.find(tmp2);
            if(it2==str_id.end())
            {
                str_id[tmp2]=n;
                id_str[n]=tmp2;
                id2=n;
                n++;
            }else
            id2=it2->second;

            friends[id1].push_back(id2);
            friends[id2].push_back(id1);
        }
        getline(cin,tmp1);
        stringstream bar(tmp1);
        while(bar>>tmp1)
        {
            vector <kkk> ans;
            int id=str_id[tmp1];
            for(int i=0;i<=3002;i++)
            prio[i]=0;
            for(int i=0;i<friends[id].size();i++)
            prio[friends[id][i]]=-1;
            prio[id]=-1;
            for(int i=0;i<friends[id].size();i++)
            {
                    for(int j=0;j<friends[friends[id][i]].size();j++)
                    {
                        if(prio[friends[friends[id][i]][j]]!=-1)
                        {
                            if(prio[friends[friends[id][i]][j]]==0)
                            {
                                lll.d=friends[friends[id][i]][j];
                                ans.push_back(lll);
                            }
                            prio[friends[friends[id][i]][j]]++;
                        }
                    }
            }
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)
            {
                cout<<id_str[ans[i].d]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

