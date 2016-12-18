/*
    Nimesh Ghelani (nims11)
    After some observation, it becomes clear how the lines should be joined.
    Also for a particular line x=a, there will be even number of points in that line
    same for y.
    Sort the original list into two separate list. One having points sorted vertically and other horizontally.
    Draw a line between 2*i and 2*i+1 points in both the list and you have your rectangle ready.
    Now, to get the direction of lines, start the first point in the list sorted according to 'x' (viz the leftest bottom point)
    And similar to the convex hull formation, get the final rectangular polygon.
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
class POINT
{
    public:
    int id;
    int P[2];
};
bool sort_x(const POINT &a,const POINT &b)
{
    if(a.P[0]==b.P[0])
        return a.P[1]<b.P[1];
    return a.P[0]<b.P[0];
}
bool sort_y(const POINT &a,const POINT &b)
{
    if(a.P[1]==b.P[1])
        return a.P[0]<b.P[0];
    return a.P[1]<b.P[1];
}
int main()
{
    int n;
    POINT points[1001],points2[1001],pt[1001];
    int to[10001],from[10001],fin[10001];
    while(1)
    {
        in_I(n);
        if(n==0)return 0;
        for(int i=0;i<n;i++)
        {
            to[i]=from[i]=fin[i]=-1;
            points[i].id = i;
            scanf("%d%d",&points[i].P[0],&points[i].P[1]);
            pt[i]=points2[i]=points[i];
        }
        sort(points,points+n,sort_x);
        sort(points2,points2+n,sort_y);
        for(int i=0;i<n;i+=2)
        {
            to[points[i].id] = points[i+1].id;
            to[points[i+1].id] = points[i].id;
            from[points2[i].id] = points2[i+1].id;
            from[points2[i+1].id] = points2[i].id;
        }
//        cout<<n<<endl;
//        for(int i=0;i<n;i++)
//        cout<<"---"<<from[i]<<" "<<to[i]<<endl;
        int curr=points[0].id;
        bool dir=1;
        do
        {
            if(dir)
            {
                if(pt[curr].P[1]!=pt[to[curr]].P[1])
                {
                    fin[curr] = to[curr];
                }else
                {
                    fin[curr] = from[curr];
                }
            }else
            {
                if(pt[curr].P[0]!=pt[to[curr]].P[0])
                {
                    fin[curr] = to[curr];
                }else
                {
                    fin[curr] = from[curr];
                }
            }
            curr = fin[curr];
            dir=!dir;
//            cout<<curr<<endl;
        }while(curr!=points[0].id);
        curr=0;
        do
        {
            if(pt[curr].P[0]==pt[fin[curr]].P[0])
            {
                if(pt[curr].P[1]<pt[fin[curr]].P[1])
                    printf("N");
                else printf("S");
            }else
            {
                if(pt[curr].P[0]<pt[fin[curr]].P[0])
                    printf("E");
                else printf("W");
            }
            curr = fin[curr];
        }while(curr!=0);
        newline;
    }
}
