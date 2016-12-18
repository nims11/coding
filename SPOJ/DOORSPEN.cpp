/*
    Nimesh Ghelani (nims11)
    Create two convex hulls depending on the type
    Partition cannot be created if
    	- hulls intersect
    	- one hull is inside another
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
    long long operator^(const POINT &b)
    {
        return this->P[0]*(long long)b.P[1] - this->P[1]*(long long)b.P[0];
    }
};
POINT<int> points1[3000], points2[3000];
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
int linedist(POINT<int> &a, POINT<int> &b, POINT<int> &c)
{
    int dot1 = (b-a)*(c-b);
    if(dot1>0)return 1;
    int dot2 = (a-b)*(c-a);
    if(dot2>0)return 1;
    return (b-a)^(c-a);
}
int ccw(POINT<int> a, POINT<int> b, POINT<int> c)
{
    long long foo = ((b-a)^(c-a));
    return foo > 0?1:(foo<0?-1:0);
}
bool intersect(POINT<int> a, POINT<int> b, POINT<int> c, POINT<int> d)
{
    if(ccw(a,b,c) == 0 && ccw(a,b,d) == 0)
    {
        if((((b-a)*(c-b))>0 && ((b-a)*(d-b))>0) || (((a-b)*(c-a))>0 && ((a-b)*(d-a))>0))
            return false;
        else
            return true;
    }
    return ccw(a,c,d) != ccw(b,c,d) && ccw(a,b,c) != ccw(a,b,d);
}
int getans(POINT<int> &a, int b, POINT<int> points1[], POINT<int> points2[], vector<int> &points)
{
    int cnt = 0;
    for(int i=0;i<-1+points.size();i++)
    {
        if(intersect(a, points2[b], points1[points[i]], points1[points[i+1]]))
        {
            cnt++;
        }
    }
    return cnt;
}
bool is_inside(vector<int> &pts, int pt, POINT<int> points1[], POINT<int> points2[], int xmin, int xmax, int ymin, int ymax)
{
    if(points2[pt].P[0]<xmin || points2[pt].P[0]>xmax || points2[pt].P[1]<ymin || points2[pt].P[1]>ymax)
        return false;
    POINT<int> coord;
    for(int i=0;i<pts.size()-1;i++)
    {
        if(linedist(points1[pts[i]], points1[pts[i+1]], points2[pt]) == 0)
        {
            return true;
        }
    }
    while(1)
    {
        POINT<int> candi;
        candi.P[0] = rand()%200000 + 200000;
        candi.P[1] = rand()%200000 + 200000;
        bool flag = true;
        for(int i=0;i<pts.size()-1;i++)
        {
            if(linedist(candi, points2[pt], points1[pts[i]])==0)
            {
                flag = false;
                break;
            }
        }
        if(!flag)continue;
//        if(foo[pt].P[1]==1 && foo[pt].P[0]==2)
//            cout<<candi.P[0]<<" "<<candi.P[1]<<endl;
        return getans(candi, pt, points1, points2, pts)%2;
    }
}

int main()
{
    int ccc = 0;
//    POINT<int> a(0,0),b(10,10),c(-5,-5),d(-1,-1);
//    cout<<intersect(a,b,c,d)<<endl;
    while(1)
    {
        ccc++;
        int d,p;
        scanf("%d%d", &d, &p);
        if(d == 0)return 0;
        vector<int> type1, type2;
        int cnt1 = 1, cnt2 = 1;
        for(int i=0;i<d;i++)
        {
            in_I(points1[cnt1].P[0]);
            in_I(points1[cnt1].P[1]);
            cnt1++;
            in_I(points1[cnt1].P[0]);
            in_I(points1[cnt1].P[1]);
            cnt1++;
            points1[cnt1].P[0] = points1[cnt1-2].P[0];
            points1[cnt1].P[1] = points1[cnt1-1].P[1];
            cnt1++;
            points1[cnt1].P[1] = points1[cnt1-3].P[1];
            points1[cnt1].P[0] = points1[cnt1-2].P[0];
            cnt1++;
        }
        for(int i=0;i<p;i++)
        {
            in_I(points2[cnt2].P[0]);
            in_I(points2[cnt2].P[1]);
            cnt2++;
            in_I(points2[cnt2].P[0]);
            in_I(points2[cnt2].P[1]);
            cnt2++;
            points2[cnt2].P[0] = points2[cnt2-2].P[0];
            points2[cnt2].P[1] = points2[cnt2-1].P[1];
            cnt2++;
            points2[cnt2].P[1] = points2[cnt2-3].P[1];
            points2[cnt2].P[0] = points2[cnt2-2].P[0];
            cnt2++;
        }
        cnt1--;
        cnt2--;
        vector<int> hull = convex_hull(points1, cnt1);
        vector<int> hull2 = convex_hull(points2, cnt2);
        int xmin1 = -200000, xmax1 = 200000, ymin1 = -200000, ymax1 = 200000;
        int xmin2 = -200000, xmax2 = 200000, ymin2 = -200000, ymax2 = 200000;
        for(int i=0;i<hull.size()-1;i++)
        {
            if(points1[hull[i]].P[0]<xmin1)
                xmin1 = points1[hull[i]].P[0];
            if(points1[hull[i]].P[0]>xmax1)
                xmax1 = points1[hull[i]].P[0];
            if(points1[hull[i]].P[1]<ymin1)
                ymin1 = points1[hull[i]].P[1];
            if(points1[hull[i]].P[1]>ymax1)
                ymax1 = points1[hull[i]].P[1];
        }
        for(int i=0;i<hull2.size()-1;i++)
        {
            if(points2[hull2[i]].P[0]<xmin2)
                xmin2 = points2[hull2[i]].P[0];
            if(points2[hull2[i]].P[0]>xmax2)
                xmax2 = points2[hull2[i]].P[0];
            if(points2[hull2[i]].P[1]<ymin2)
                ymin2 = points2[hull2[i]].P[1];
            if(points2[hull2[i]].P[1]>ymax2)
                ymax2 = points2[hull2[i]].P[1];
        }
        bool flag = true;
        for(int i=0;i<hull.size()-1;i++)
        {
            for(int j=0;j<hull2.size()-1;j++)
            {
//                printf("%d,%d %d,%d %d,%d %d,%d\n", points1[hull[i]].P[0], points1[hull[i]].P[1], points1[hull[i+1]].P[0], points1[hull[i+1]].P[1], points2[hull2[j]].P[0], points2[hull2[j]].P[1], points2[hull2[j+1]].P[0], points2[hull2[j+1]].P[1]);
                if(intersect(points1[hull[i]], points1[hull[i+1]], points2[hull2[j]], points2[hull2[j+1]]))
                {
                    flag = false;
                    break;
                }
            }
            if(!flag)
                break;
        }
        if(flag)
        {
            if(is_inside(hull, hull2[0], points1, points2, xmin1, xmax1, ymin1, ymax1) ||
               is_inside(hull2, hull[0], points2, points1, xmin2, xmax2, ymin2, ymax2))
                flag = false;
        }
//        for(int i=1;i<=cnt1;i++)
//        {
//            if(is_inside(hull2, i,points2, points1, xmin2, xmax2, ymin2, xmax2))
//            {
////                cout<<points2[i].P[0]<<" "<<points2[i].P[1]<<endl;
//                flag = false;
//                break;
//            }
//        }
        printf("Case %d: ", ccc);
        if(flag)
        {
            printf("It is possible to separate the two groups of vendors.\n\n");
        }else
            printf("It is not possible to separate the two groups of vendors.\n\n");

//        for(int i=1;i<=cnt1;i++)
//        {
//            cout<<points1[i].P[0]<<" "<<points1[i].P[1]<<endl;
//        }
//        cout<<endl;
//        for(int i=0;i<hull.size();i++)
//        {
//            cout<<points2[hull2[i]].P[0]<<" "<<points2[hull2[i]].P[1]<<endl;
//        }
    }
}
