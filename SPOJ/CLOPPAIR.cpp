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
struct point
{
       int x,y,i;
};
long long DIST(int x1, int y1, int x2, int y2) 
{
return (x1-x2)*(long long)(x1-x2) + (y1-y2)*(long long)(y1-y2);
}
bool cmp(const point &a, const point &b)
{
     if(a.x!=b.x)
     return a.x<b.x;
     return a.y<b.y;
}
int main()
{
    int n;
    in_I(n);
    point points[n];
    long long mini = 10000000000000000LL;pair<int, int> pt;
    for(int i=0;i<n;i++)
    {
        in_I(points[i].x);
        in_I(points[i].y);
        points[i].i = i;
    }
    sort(points, points+n, cmp);
    for(int i=0;i<n-1;i++)
    {
            for(int j=i+1;j<n && (points[j].x-points[i].x)*(long long)(points[j].x-points[i].x)<mini;j++)
            {
                    long long tmp = DIST(points[i].x, points[i].y, points[j].x, points[j].y);
                    if(tmp<mini)
                    {
                        mini = tmp;
                        pt.first = points[i].i;
                        pt.second = points[j].i;
                    }
            }
    }
    
    printf("%d %d %.6lf\n", min(pt.first, pt.second), max(pt.first, pt.second), sqrt(mini));
}



