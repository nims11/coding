/*
    Nimesh Ghelani (nims11)
    Use the 3 scores as coordinates and get the points in a 3-d plane. A point is excellent if there is no other point having all coordinates less than that point.
    First sort according to 1 coordinate (say z coordinate)
    imagine foo as a set containing points which determine a 2-d region (without the z-axis) within which if a point lie, should be counted. Also, upon finding such point, the region should be suitably updated.
    
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
pair<int, int> x_y[100000];
int a,b,c, n;
struct cmp{
bool operator()(int a, int b)
{
    return x_y[a]<x_y[b];
}
};
int main()
{
    in_T
    {
        in_I(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            x_y[a-1] = make_pair(b,c);
        }
        set<int, cmp> foo;
        set<int, cmp>::iterator it1, it2;
        foo.insert(0);
        int ans = 1;
        for(int i=1;i<n;i++)
        {
            it1 = foo.lower_bound(i);
//            if(it1!=foo.end())
            {
                bool flag = false;
                if(it1 == foo.begin())
                {
                    flag = true;
                }else
                {
                    it1--;
                    if(x_y[*it1].second > x_y[i].second)
                        flag = true;
                }
                if(flag)
                {
                    ans++;
                    foo.insert(i);
                    for(it1 = foo.upper_bound(i);it1 != foo.end();it1++)
                    {
                        if(x_y[*it1].second>x_y[i].second)
                        {
                            it2 = it1;it2++;
                            foo.erase(it1);
                            it1=it2;
                            it1--;

                        }else
                        break;
                    }

                }
            }
        }
        printf("%d\n", ans);
    }
}
