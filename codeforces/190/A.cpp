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
pair<int, int> net;
pair<int, int> dest;
string comm;
set<pair<int, int> > poss;
int main()
{
    cin>>dest.first>>dest.second;
    cin>>comm;
    net.first = 0;
    net.second = 0;
    for(int i=0;i<comm.length();i++)
    {
        poss.insert(net);
        switch(comm[i])
        {
        case 'R':
            net.first++;
            break;
        case 'L':
            net.first--;
            break;
        case 'U':
            net.second++;
            break;
        case 'D':
            net.second--;
            break;
        }
    }
    for(set<pair<int, int> >::iterator it = poss.begin(); it!=poss.end(); it++)
    {
        pair<int, int> xx = *it;
        xx.first = dest.first - xx.first;
        xx.second = dest.second - xx.second;
        bool flag1, flag2;
        if(net.first == 0)
        {
            flag1 = (xx.first == 0);
        }else
        {
            flag1 = (xx.first%net.first==0 && 1LL*net.first*xx.first>=0);
        }

        if(net.second == 0)
        {
            flag2 = (xx.second== 0);
        }else
        {
            flag2 = (xx.second%net.second==0 && 1LL*net.second*xx.second>=0);
        }
        if(flag1 && flag2)
        {
            int x, y;
            if(net.first && net.second)
            {
                x = xx.first/net.first;
                y = xx.second/net.second;
                if(x == y)
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }else
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}
