/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
struct foo
{
    int a,b,c,d;
    friend bool operator<(const foo &a,const foo &b)
    {
        if(a.a==b.a)return a.b<b.b;
        return a.a<b.a;
    }
}tmp;
int main()
{
    vector<foo> ans;
    map<int,int> arr;
    for(int i=2;i<=100;i++)
    arr[i*i*i]=i;
    int x,y,z;
    map<int,int>::iterator it;

    for(int b=2;b<100;b++)
    {
        x=b*b*b;
        for(int c=b;c<100;c++)
        {
            y=x+c*c*c;
            for(int d=c;d<100;d++)
            {
                z=y+d*d*d;
                it=arr.find(z);
                if(it!=arr.end())
                {
                    tmp.a=it->second;tmp.b=b;tmp.c=c;tmp.d=d;
                    ans.push_back(tmp);
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    printf("Cube = %d, Triple = (%d,%d,%d)\n",ans[i].a,ans[i].b,ans[i].c,ans[i].d);
}
