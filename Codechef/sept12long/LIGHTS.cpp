/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<utility>
#include<list>
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
struct light
{
    double x,y,z,x_L,x_R;
    friend bool operator<(const light &a, const light &b)
    {
        return a.x < b.x;
    }
}tmp;
const double PI = acos(-1);
vector<light> lights;
list< pair<pair<double, double>, pair<double, double> > > max_funcs;
list< pair<pair<double, double>, pair<double, double> > >::iterator it2,it3;
list< pair<pair<double, double>, pair<double, double> > >::reverse_iterator it1;
pair<pair<double, double>, pair<double, double> > line_tmp;

int main()
{
    int N;
    double L,R,foo;
    in_I(N);
    in_F(L);in_F(R);
    for(int i=0;i<N;i++)
    {
        in_F(tmp.x);
        in_F(tmp.y);
        in_F(tmp.z);
        foo= tmp.y*tan(tmp.z*PI/180);
        tmp.x_L=tmp.x-foo;
        tmp.x_R=tmp.x+foo;
        lights.push_back(tmp);
    }
    sort(lights.begin(),lights.end());
//    for(int i=0;i<lights.size();i++)
//        cout<<lights[i].x_L<<" "<<lights[i].x_R<<endl;
//    cout<<endl;
    max_funcs.push_back(make_pair(make_pair(lights[0].x_L,0) , make_pair(lights[0].x,lights[0].y)));
    max_funcs.push_back(make_pair(make_pair(lights[0].x,lights[0].y) , make_pair(lights[0].x_R,0)));

    for(int i=1; i<N; i++)
    {
        double slope_i_L = (lights[i].y)/(lights[i].x-lights[i].x_L);
        double slope_i_R = (lights[i].y)/(lights[i].x-lights[i].x_R);

        it1 = max_funcs.rbegin();
        while(1)
        {
            if(it1->first.first < lights[i].x)
            break;
            else it1++;
        }
        double line_y = it1->first.second + (it1->second.second - it1->first.second)*(lights[i].x - it1->first.first)/(it1->second.first - it1->first.first);
        bool above=true;
        if(line_y>lights[i].y)
            above = false;
        if(above)
        {
            it1->second = make_pair(lights[i].x,line_y);
            if(lights[i].x_R>=max_funcs.back().second.first)
            {
                max_funcs.erase(--(it1.base()), max_funcs.end());
                max_funcs.push_back(make_pair(make_pair(lights[i].x, lights[i].y),make_pair(lights[i].x_R,0)));
            }else
            {
                for(it2 = --(it1.base()); it2!=max_funcs.end(); it2++)
                {
                    double x =  ( it2->first.first*(it2->second.second - it2->first.second)/(it2->second.first - it2->first.first) + it2->first.second - lights[i].x_R*lights[i].y/(lights[i].x - lights[i].x_R));
                    double y = (x-lights[i].x_R)*lights[i].y/(lights[i].x - lights[i].x_R);
                    if(x>= it2->first.first && x<= it2->second.first)
                    {
                        it2->first.first = x;
                        it2->first.second = y;
                        max_funcs.erase(it1.base(), it2);
                        max_funcs.insert(it2, make_pair(make_pair(lights[i].x,lights[i].y),make_pair(x,y)));
                    }
                }
            }
        }
    }
}
