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
template <class T>
double dist(const POINT<T> &a, const POINT<T> &b)
{
    T d1 = a.P[0]-b.P[0];
    T d2 = a.P[1]-b.P[1];
    return sqrt(d1*d1 + d2*d2);
}
template <class T>
vector<int> convex_hull(POINT<T> points[],int n)
{
    points[0].P[0]=20000;
    points[0].P[1]=20000;
    bool used[n+1];
    for(int i=1;i<=n;i++)
        used[i]=false;
    int bot_left=0;
    vector<int> pos;
    for(int i=1;i<=n;i++)
    {
        if(points[bot_left].P[1]>points[i].P[1])
        {
            bot_left = i;
        }else if(points[bot_left].P[1]==points[i].P[1] && points[bot_left].P[0]>points[i].P[0])
            bot_left = i;
    }
    pos.push_back(bot_left);
    int start = bot_left;
    do
    {
        int n2=-1;
        int dis = 0;

        for(int i=1;i<=n;i++)
        {
            if(i==bot_left)continue;
            if(used[i])continue;
            if(n2==-1)n2=i;
            T cross = (points[i]-points[bot_left])^(points[n2]-points[bot_left]);
            T d = (points[i]-points[bot_left])*(points[i]-points[bot_left]);
            if(cross>0)n2=i,dis=d;
            else if(cross==0)
            {
                if(d>dis)dis=d,n2=i;
            }
        }
        bot_left = n2;
        used[n2]=true;
//        if(n2!=start)
        pos.push_back(n2);
    }while(start!=bot_left);
    return pos;
}
POINT<int> points[100003];
int main()
{
    in_T
    {
        int n;
        in_I(n);
        double ans=0;

        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&points[i].P[0], &points[i].P[1]);
        }
        if(n==1)
        {
            printf("0.00\n1\n\n");continue;
        }
        vector<int> pos = convex_hull<int>(points,n);
        ans += dist(points[pos[0]],points[pos[pos.size()-1]]);
        for(int i=1;i<pos.size();i++)
            ans+=dist(points[pos[i]],points[pos[i-1]]);
        printf("%.2lf\n",ans);
        for(int i=0;i<pos.size()-1;i++)
            printf("%d ",pos[i]);
        printf("\n\n");
    }
}
