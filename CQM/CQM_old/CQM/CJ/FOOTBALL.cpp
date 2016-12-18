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
struct foo
{
    int h,w;
    int id;
    friend bool operator<(const foo &a, const foo &b)
    {
        if(a.h!=b.h)
        return a.h>b.h;
        return a.w>b.w;
    }
}tmp;
int act[10003];
set<foo> bar;
set<foo>::iterator it;
int main()
{
    in_T
    {
        bar.clear();
        int n;
        in_I(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d", &tmp.h, &tmp.w);
            tmp.id = i;
            bar.insert(tmp);
        }
        for(int i=0;i<n;i++)
            act[i] = 1;
        int rem = n;
        vector<int> ans;
        while(rem)
        {
            int cur = 1;
            rem--;
            int baz;
            for(it = bar.begin();it!=bar.end();it++)
            {
                if(act[it->id])
                {
                    act[it->id] = 0;
                    baz = it->w;
//                    cout<<" "<<it->id<<" "<<baz<<endl;
                    break;
                }
            }
            for(;it!=bar.end();it++)
            {
                if(act[it->id] && it->w > baz)
                {
                    cur++;
                    rem--;
                    act[it->id] = 0;
                }
            }
            ans.push_back(cur);
        }
        printf("%d\n", ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d ", ans[i]);
        newline;
    }
}
