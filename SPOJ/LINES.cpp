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
int pt[200][2];
pair<int, int> tmp;
int GCD(int a,int b)
{
	while(b>0)
	{
	   int temp=a;
	   a=b;
	   b=temp%b;
	}
      return a;
}

int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}
int main()
{
    int n;
    while(1)
    {
        in_I(n);
        if(n==0)return 0;
        for(int i=0;i<n;i++)
            scanf("%d%d", &pt[i][0], &pt[i][1]);
        set<pair<int, int> > foo;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                tmp = make_pair(pt[i][0]-pt[j][0], pt[i][1]-pt[j][1]);
                if(tmp.first<0)
                    tmp.first *=-1, tmp.second *= -1;
                if(tmp.first == 0)
                {
                    if(tmp.second<0)
                        tmp.second *= -1;
                }
                int x = GCD(abs(tmp.first), abs(tmp.second));
                tmp.first/=x;
                tmp.second/=x;
                foo.insert(tmp);
            }
        printf("%d\n", foo.size());
    }
}
