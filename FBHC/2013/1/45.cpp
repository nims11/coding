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
#include<list>
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
#include<set>
using namespace std;
typedef pair<int, int> PT;
int main()
{
    int cc = 0;
    in_T
    {
        cc++;
        long long W,H, P,Q, N, X,Y,a,b,c,d;
        cin>>W>>H>>P>>Q>>N>>X>>Y>>a>>b>>c>>d;
        cout<<N<<endl;
        set<int> points[W];
        set<int>::iterator it;
        points[X].insert(Y);
        int _X, _Y;
        for(int i=1;i<N;i++)
        {
            _X = (X*a+Y*b+1)%W;
            _Y = (X*c+Y*d+1)%H;
            X = _X;
            Y = _Y;
            points[X].insert(Y);
        }
        long long to_rem = 0;
        int status[H];
        for(int i=0;i<H;i++)
            status[i] = -1;
        for(int i=0;i<W;i++)
        {
            for(it = points[i].begin();it!=points[i].end();it++)
            {
//                cout<<i<<" "<<*it<<endl;
                for(int j=*it;j>=0 && j>*it-Q;j--)
                {
                    if(i-status[j]>=P)
                    {
                        status[j] = i;
                        if(j<=H-Q){
                            if(i<=W-P && status[j]<=W-P)
                                to_rem += P;
                            else
                                to_rem += P-(i-(W-P));
                        }
                    }else
                    {
                        if(j<=H-Q && status[j]<=W-P)
                        {
                            if(i<=W-P)
                                to_rem += i-status[j];
                            else
                                to_rem += i-status[j] - (i-(W-P));
                        }
                        status[j] = i;
                    }
//                    cout<<"  "<<to_rem<<endl;
                }
            }
        }
        cout<<"Case #"<<cc<<": "<<((W-P+1)*(H-Q+1))-to_rem<<endl;
    }
}
