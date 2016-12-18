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
int main()
{
    int n,m;
    cin>>n>>m;
    set<int> lang[n];
    set<int>::iterator it;
    set<int> langs;
    for(int i=0;i<n;i++)
    {
        int t,l;
        cin>>t;
        for(int j=0;j<t;j++)
        {
            cin>>l;
            lang[i].insert(l);
            langs.insert(l);
        }
    }
    if(langs.size() == 0)
    {
        cout<<n<<endl;
        return 0;
    }
    int id[n];
    for(int i=0;i<n;i++)id[i]=i;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j && id[i]!=id[j])
            for(it=lang[i].begin();it!=lang[i].end();it++)
            {
                if(lang[j].find(*it) != lang[j].end())
                {
                    int tmp1 = min(id[i], id[j]), tmp;
                    if(id[i] == tmp1)
                    {
                        tmp = id[j];
                        for(int k=0;k<n;k++)
                            if(id[k]==tmp)id[k]=tmp1;
                    }else
                    {
                        tmp = id[i];
                        for(int k=0;k<n;k++)
                            if(id[k]==tmp)id[k]=tmp1;
                    }
                }
            }
        }
    }
    set<int> foo;
    for(int i=0;i<n;i++)
        foo.insert(id[i]);
    cout<<foo.size()-1<<endl;
}
