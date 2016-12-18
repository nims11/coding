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

int n;
bool cmp(int a, int b)
{
    if(foo[a].P[0]!=foo[b].P[0])
        return foo[a].P[0]<foo[b].P[0];
    return foo[a].P[1]<foo[b].P[1];
}

double dist(const POINT<int> &a, const POINT<int> &b)
{
    int d1 = a.P[0]-b.P[0];
    int d2 = a.P[1]-b.P[1];
    return sqrt(d1*d1 + d2*d2);
}
double linedist(POINT<int> &a, POINT<int> &b, POINT<int> &c)
{
    double d = ((b-a)^(c-a))/dist(a,b);
    int dot1 = (b-a)*(c-b);
    if(dot1>0)return dist(b,c);
    int dot2 = (a-b)*(c-a);
    if(dot2>0)return dist(a,c);
    return abs(d);
}
class line{
public:
    int a,b,c;
    int x1,x2,y1,y2;
    void compute()
    {
        a = y2-y1;
        b = x1-x2;
        c = (x2*y1-x1*y2);
    }
    line(int a, int b)
    {
        this->x1 = foo[a].P[0];
        this->x2 = foo[b].P[0];
        this->y1 = foo[a].P[1];
        this->y2 = foo[b].P[1];
        compute();
    }
};
bool intersects(line &line1, line &line2)
{
    if(line1.a*line2.b == line1.b*line2.a)
    {
        if(line1.b*line2.c == line2.b*line1.c)
            return false;
        else
            return true;
    }
    int c = line1.a*line2.b-line2.a*line1.b;
    double xx = (line1.b*line2.c - line2.b*line1.c)/c;
    double yy = -(line1.a*line2.c-line2.a*line1.c)/c;
    if(xx<max(line1.x1, line1.x2) && xx>min(line1.x1, line1.x2) && yy<max(line1.y1, line1.y2) && yy>min(line1.y1, line1.y2))
        return true;
    return false;
}
bool include_pt(vector<int> &poly, int pt)
{
//    cout<<foo[pt].P[0]<<" "<<foo[pt].P[1]<<endl;
//    for(int i=0;i<poly.size();i++)
//        cout<<foo[poly[i]].P[0]<<"++"<<foo[poly[i]].P[1]<<endl;
    double min_dist;
    int min_dist_i = -1;
    for(int i=0;i<poly.size();i++)
    {
        line line1(pt, poly[i]);
        line line2(pt, poly[(i+1)%poly.size()]);
        bool flag = true;
        for(int j=0;j<poly.size();j++)
        {
            if(i!=j)
            {
                line line3(poly[j], poly[(j+1)%poly.size()]);
                if(intersects(line1, line3) || intersects(line2,line3))
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            double tmp = dist(foo[poly[i]], foo[pt]) + dist(foo[poly[(i+1)%poly.size()]], foo[pt]) - dist(foo[poly[(i+1)%poly.size()]], foo[poly[i]]);
            if(min_dist_i == -1)
            {
                min_dist = tmp;
                min_dist_i = i;
            }else
            {
                if(min_dist>tmp)
                {
                    min_dist = tmp;
                    min_dist_i = i;
                }
            }
        }
    }
    if(min_dist_i==poly.size()-1)
    {
        poly.push_back(pt);
    }else
    {
//        if(min_dist_i == -1)
//        cout<<"asas"<<endl;
//    else
        if(min_dist_i == -1)
            return false;
        poly.insert(poly.begin()+min_dist_i, pt);
    }
    foo[pt].used = true;
    return true;
}

int getans(POINT<int> &a, int b, vector<int> &points)
{
    int cnt = 0;
    double mab = double(foo[b].P[1]-a.P[1])/(foo[b].P[0]-a.P[0]);
    for(int i=0;i<points.size();i++)
    {
        int j = (i+1)%points.size();
        if(foo[points[i]].P[0] == foo[points[j]].P[0])
        {
            double y = mab*(foo[points[i]].P[0]-a.P[0]) + a.P[1];
            if(y>min(foo[points[i]].P[1],foo[points[j]].P[1]) && y<max(foo[points[i]].P[1],foo[points[j]].P[1]) && y>min(a.P[1],foo[b].P[1]) && y<max(a.P[1], foo[b].P[1]))
            {
                cnt++;
            }
        }else if(foo[points[i]].P[1] == foo[points[j]].P[1])
        {
            double x = (foo[points[i]].P[1] - a.P[1])/mab + a.P[0];
            if(x>min(foo[points[i]].P[0],foo[points[j]].P[0]) && x<max(foo[points[i]].P[0],foo[points[j]].P[0]) && x>min(a.P[0],foo[b].P[0]) && x<max(a.P[0], foo[b].P[0]))
            {
                cnt++;
            }
        }else
        {
            double m1 = double(foo[points[j]].P[1]-foo[points[i]].P[1])/(foo[points[j]].P[0]-foo[points[i]].P[0]);
            double m2 = double(a.P[1]-foo[b].P[1])/(a.P[0]-foo[b].P[0]);
            double c1 = foo[points[i]].P[1] - foo[points[i]].P[0]*m1;
            double c2 = foo[b].P[1] - foo[b].P[0]*m2;
            double x = (-c1+c2)/(m1-m2), y = (c2*m1-c1*m2)/(m1-m2);
            if(y>min(foo[points[i]].P[1],foo[points[j]].P[1]) && y<max(foo[points[i]].P[1],foo[points[j]].P[1]) && y>min(a.P[1],foo[b].P[1]) && y<max(a.P[1], foo[b].P[1])
               &&
               x>min(foo[points[i]].P[0],foo[points[j]].P[0]) && x<max(foo[points[i]].P[0],foo[points[j]].P[0]) && x>min(a.P[0],foo[b].P[0]) && x<max(a.P[0], foo[b].P[0]))
                cnt++;
        }
    }
    return cnt;
}
bool is_inside(vector<int> &pts, int pt, int xmin, int xmax, int ymin, int ymax)
{
    if(foo[pt].P[0]<xmin || foo[pt].P[0]>xmax || foo[pt].P[1]<ymin || foo[pt].P[1]>ymax)
        return false;
    POINT<int> coord;
    for(int i=0;i<pts.size();i++)
    {
        if(linedist(foo[pts[i]], foo[pts[(i+1)%pts.size()]], foo[pt]) == 0)
        {
            return false;
        }
    }
    while(1)
    {
        POINT<int> candi;
        candi.P[0] = rand()%10000 + 10000;
        candi.P[1] = rand()%10000 + 10000;
        bool flag = true;
        for(int i=0;i<pts.size();i++)
        {
            if(linedist(candi, foo[pt], foo[pts[i]])==0)
            {
                flag = false;
                break;
            }
        }
        if(!flag)continue;
//        if(foo[pt].P[1]==1 && foo[pt].P[0]==2)
//            cout<<candi.P[0]<<" "<<candi.P[1]<<endl;
        return getans(candi, pt, pts)%2;
    }
}
vector<int> make_poly2(vector<int> pts)
{
    for(int i=1;i<=n;i++)
    foo[i].used = false;
    vector<int> lower = convex_hull(pts, false);
    vector<int > ans;
    for(int i=0;i<lower.size();i++)
        ans.push_back(lower[i]);
    int tmp[pts.size()];
    for(int i=0;i<pts.size();i++)
        tmp[i] = pts[i];
    sort(tmp, tmp+pts.size(), cmp);
    for(int i=pts.size();i>=1;i--)
    {
        if(!foo[tmp[i-1]].used)
        ans.push_back(tmp[i-1]);
    }
return ans;
}
bool make_poly(vector<int> pts, vector<int> &convex_t, int xmin, int xmax, int ymin, int ymax)
{
//    for(int i=0;i<pts.size();i++)
//        cout<<foo[pts[i]].P[0]<<"--"<<foo[pts[i]].P[1]<<endl;
    int type = foo[convex_t[0]].t;
    bool flag = true;
    bool fallback = false;
    while(flag)
    {
        flag = false;
        for(int i=0;i<pts.size();i++)
        {
            if(foo[pts[i]].t == type)
            {
                if(!foo[pts[i]].used && !is_inside(convex_t, pts[i], xmin, xmax, ymin, ymax))
                {
                    bool qwe = include_pt(convex_t, pts[i]);
                    if(!qwe)
                    {
                        fallback = true;
                        flag = false;
                        break;
                    }
                    flag = true;
                    break;
                }
            }else
            {
                if(!foo[pts[i]].used && is_inside(convex_t, pts[i], xmin, xmax, ymin, ymax))
                {
                    bool qwe = include_pt(convex_t, pts[i]);
//                    for(int j=0;j<convex_t.size();j++)
//        cout<<foo[convex_t[j]].P[0]<<"++"<<foo[convex_t[j]].P[1]<<endl;
                    if(!qwe)
                    {
                        fallback = true;
                        flag = false;
                        break;
                    }
                    flag = true;
                    break;
                }
            }
        }
    }
    return fallback;
}
double perimeter(vector<int> &pts)
{
    double ret = 0;
    for(int i=0;i<pts.size();i++)
    {
        ret+=dist(foo[pts[i]], foo[pts[(i+1)%pts.size()]]);
    }
    return ret;
}
int main()
{

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
    vector<int> tt, tt1;
    if(type0<=type1)
    {
        for(int i=1;i<=n;i++)
            if(foo[i].t==0)
            tt.push_back(i);
            else
            tt1.push_back(i);
    }else
    {
        for(int i=1;i<=n;i++)
            if(foo[i].t==1)
            tt.push_back(i);
            else
            tt1.push_back(i);
    }
vector<int> ans1, ans2;
{
    vector<int> convex_t = convex_hull(tt, true);
//    for(int i=0;i<convex_t.size();i++)
//        cout<<foo[convex_t[i]].P[0]<<" "<<foo[convex_t[i]].P[1]<<endl;
//    cout<<endl;
    vector<int> pts;

    int x_min, x_max, y_min, y_max;
    x_min = x_max = foo[convex_t[0]].P[0];
    y_min = y_max = foo[convex_t[0]].P[1];
    for(int i=0;i<convex_t.size();i++)
    {
        x_min = min(x_min, foo[convex_t[i]].P[0]);
        x_max = max(x_max, foo[convex_t[i]].P[0]);
        y_min = min(y_min, foo[convex_t[i]].P[1]);
        y_max = max(y_max, foo[convex_t[i]].P[1]);
    }
    for(int i=1;i<=n;i++)
    {
//        if(foo[i].t!=foo[tt[0]].t)
        {
            if(is_inside(convex_t, i, x_min, x_max, y_min, y_max))
                {
                    pts.push_back(i);
//                    cout<<foo[i].P[0]<<" +0+ "<<foo[i].P[1]<<endl;
                }
        }
    }
    bool fallback = make_poly(pts, convex_t, x_min, x_max, y_min, y_max);
    if(!fallback)
    ans1 = convex_t;
    else
    {
        vector<int> pts;
        for(int i=0;i<tt.size();i++)
        pts.push_back(tt[i]);
        for(int i=1;i<=n;i++)
        {
            if(foo[i].t!=foo[tt[0]].t)
            {
                if(is_inside(convex_t, i, x_min, x_max, y_min, y_max))
                {
                    pts.push_back(i);
                // cout<<foo[i].P[0]<<" +0+ "<<foo[i].P[1]<<endl;
                }
            }
        }
        ans1 = make_poly2(pts);
    }
}
{
    vector<int> convex_t = convex_hull(tt1, true);
//    for(int i=0;i<convex_t.size();i++)
//        cout<<foo[convex_t[i]].P[0]<<" "<<foo[convex_t[i]].P[1]<<endl;
//    cout<<endl;
    vector<int> pts;
//    for(int i=0;i<tt1.size();i++)
//        pts.push_back(tt1[i]);

    int x_min, x_max, y_min, y_max;
    x_min = x_max = foo[convex_t[0]].P[0];
    y_min = y_max = foo[convex_t[0]].P[1];
    for(int i=0;i<convex_t.size();i++)
    {
        x_min = min(x_min, foo[convex_t[i]].P[0]);
        x_max = max(x_max, foo[convex_t[i]].P[0]);
        y_min = min(y_min, foo[convex_t[i]].P[1]);
        y_max = max(y_max, foo[convex_t[i]].P[1]);
    }
    for(int i=1;i<=n;i++)
    {
        if(foo[i].t!=foo[tt1[0]].t)
        {
            if(is_inside(convex_t, i, x_min, x_max, y_min, y_max))
                {
                    pts.push_back(i);
//                    cout<<foo[i].P[0]<<" +0+ "<<foo[i].P[1]<<endl;
                }
        }
    }
    bool fallback = make_poly(pts, convex_t, x_min, x_max, y_min, y_max);
    if(!fallback)ans2 = convex_t;
    else
    {
        vector<int> pts;
        for(int i=0;i<tt.size();i++)
        pts.push_back(tt[i]);
        for(int i=1;i<=n;i++)
        {
            if(foo[i].t!=foo[tt[0]].t)
            {
                if(is_inside(convex_t, i, x_min, x_max, y_min, y_max))
                {
                    pts.push_back(i);
                // cout<<foo[i].P[0]<<" +0+ "<<foo[i].P[1]<<endl;
                }
            }
        }
        ans2 = make_poly2(pts);
    }
}
vector<int> ans;
    if(perimeter(ans1)>perimeter(ans2))
        ans=ans2;
    else
        ans = ans1;
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<foo[ans[i]].P[0]<<" "<<foo[ans[i]].P[1]<<endl;
}
