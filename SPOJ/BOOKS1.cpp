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
int m,k;
int p[500];
vector<int>ans;
bool possible(int size, bool print = false)
{
    if(print)ans.clear();
    int curr=0;
    for(int i=0;i<k-1;i++)
    {
        int sum=0;
        while(curr<m-k+i+1 && sum+p[curr]<=size)
        {
            if(print)ans.push_back(p[curr]);
            sum+=p[curr];
            curr++;
        }
        if(print)ans.push_back(-1);
    }
    int sum2=0;
    while(curr<m)
    {
        if(print)ans.push_back(p[curr]);
        sum2+=p[curr++];
    }
    if(print)
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(ans[i]!=-1)printf("%d ",ans[i]);
        else printf("/ ");
    }
    if(print)
    newline;
    if(sum2>size)return false;
    return true;
}
int main()
{
    in_T
    {
        in_I(m);in_I(k);
        int start=0,end=0;
        for(int i=m-1;i>=0;i--)
        {
            in_I(p[i]);
            start = max(start,p[i]);
            end +=p[i];
        }
        while(start<end)
        {
            int mid = (start+end)/2;
            if(possible(mid))
            {
                end = mid;
            }else
            start = mid+1;
        }
        possible(start,true);
    }
}
