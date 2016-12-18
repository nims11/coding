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
template <class T>
class POINT
{
    public:
    T P[2];
    POINT(){}
    bool used;
    int t;
    POINT(T x, T y){P[0] = x, P[1] = y;}
    //dot
    T operator*(const POINT &a)
    {
        return a.P[0]*this->P[0] + a.P[1]*this->P[1];
    }
    POINT operator-(const POINT &b)
    {
        return POINT(this->P[0] - b.P[0], this->P[1] - b.P[1]);
    }
    //cross
    T operator^(const POINT &b)
    {
        return this->P[0]*b.P[1] - this->P[1]*b.P[0];
    }
};
POINT<int> foo[300];
bool used[1000];
vector<int> convex_hull(vector<int> &points, bool complete=false)
{
    int n = points.size();
    for(int i=0;i<n;i++)
        used[i]=false, foo[points[i]].used = false;
    int bot_left=0, top_right = 0, bot_right = 0;
    vector<int> pos;
    for(int i=0;i<n;i++)
    {
        if(foo[points[bot_left]].P[0]>foo[points[i]].P[0])
        {
            bot_left = i;
        }else if(foo[points[bot_left]].P[0]==foo[points[i]].P[0] && foo[points[bot_left]].P[1]>foo[points[i]].P[1])
            bot_left = i;

        if(foo[points[top_right]].P[0]<foo[points[i]].P[0])
        {
            top_right = i;
        }else if(foo[points[top_right]].P[0]==foo[points[i]].P[0] && foo[points[top_right]].P[1]<foo[points[i]].P[1])
            top_right = i;

    }
    if(!complete){
    pos.push_back(points[bot_left]);
    foo[points[bot_left]].used = true;
    used[bot_left] = true;
    }
    int start = bot_left;
    do
    {
        if(!complete && pos[pos.size()-1]==points[top_right])return pos;
        int n2=-1;
        int dis = 1<<29;

        for(int i=0;i<n;i++)
        {
            if(i==bot_left)continue;
            if(used[i])continue;
            if(n2==-1)n2=i;
            int cross = (foo[points[i]]-foo[points[bot_left]])^(foo[points[n2]]-foo[points[bot_left]]);
            int d = (foo[points[i]]-foo[points[bot_left]])*(foo[points[i]]-foo[points[bot_left]]);
            if(cross>0)n2=i,dis=d;
            else if(cross==0)
            {
                if(d<dis)dis=d,n2=i;
            }
        }
        bot_left = n2;
        used[n2]=true;
        foo[points[n2]].used = true;
//        if(n2!=start)
        pos.push_back(points[n2]);
    }while(start!=bot_left);
    return pos;
}
vector<int> vert[1002], vert2[1002];
    vector<POINT<int> > foo1, foo2;
    POINT<int> tmp;


bool cmp(int a, int b)
{
    if(foo[a].P[0]!=foo[b].P[0])
        return foo[a].P[0]<foo[b].P[0];
    return foo[a].P[1]<foo[b].P[1];
}
vector<int> make_poly(vector<int> pts)
{
    vector<int> lower = convex_hull(pts, false);
    vector<int > ans;
    for(int i=0;i<lower.size();i++)
        ans.push_back(lower[i]);
    int tmp[pts.size()];
    for(int i=1;i<=pts.size();i++)
        tmp[i-1] = i;
    sort(tmp, tmp+pts.size(), cmp);
    for(int i=pts.size();i>=1;i--)
    {
        if(!foo[tmp[i-1]].used)
            ans.push_back(tmp[i-1]);
    }
    return ans;
}
int main()
{
    int n;
    int a,b,c;
    in_I(n);
    int type0 = 0, type1 = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>foo[i].P[0]>>foo[i].P[1]>>c;
        if(c==1000)
            foo[i].t = 0, type0++;
        else foo[i].t = 1, type1++;
    }
    vector<int> tt;
    if(type0<type1)
    {
        for(int i=1;i<=n;i++)
            if(foo[i].t==0)
            tt.push_back(i);
    }else
    {
        for(int i=1;i<=n;i++)
            if(foo[i].t==1)
            tt.push_back(i);
    }

    vector<int> pts;
    for(int i=1;i<=n;i++)
        pts.push_back(i);
    vector<int> ans = make_poly(pts);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<foo[ans[i]].P[0]<<" "<<foo[ans[i]].P[1]<<endl;
}
