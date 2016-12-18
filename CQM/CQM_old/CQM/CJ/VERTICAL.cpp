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
int mirror[5][2] = {{0,0}, {1,1}, {2,5}, {5,2}, {8,8}};
int bar[] = {0,1,2,3,3,3,3,3,4};
set<long long> foo;
int mid = -1;
vector<int> tmp(200);
int tmp_size = 0;
void compute(int len)
{

    if(tmp_size == len)
    {
//        cout<<"1"<<endl;
        long long fin = 0;
        for(int i=0;i<tmp_size;i++)
        {
            fin = fin*10+tmp[i];
        }
        if(mid!=-1)
            fin = fin*10+mid;
        for(int i=int(tmp_size)-1;i>=0;i--)
            fin = fin*10+mirror[bar[tmp[i]]][1];
        foo.insert(fin);
        return;
    }
    int i = 0;
    if(tmp_size == 0)
        i++;
    for(;i<5;i++)
    {
        tmp[tmp_size] = mirror[i][0];
        tmp_size++;
        compute(len);
        tmp_size--;
    }
}
long long A,B;
int main()
{
    for(int len=1;len<=18;len++)
    {
        if(len&1)
        {
            for(int i=0;i<5;i++)
            {
                if(mirror[i][0] == mirror[i][1])
                {
                    mid = mirror[i][0];
                    tmp_size = 0;
                    compute(len/2);
                }
            }
        }else
        {

        }
    }
    int i=0;
    for(set<long long>::iterator it = foo.begin();it!=foo.end() && i<50;it++, i++)
        cout<<*it<<endl;
    in_T
    {
        in_L(A);
        in_L(B);

    }
}
