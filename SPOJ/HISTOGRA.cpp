/*
 * To find the largest rectangle in a given histogram.
 * STACK
 * If stack is empty, push the element.
 * Push if height of top is <= height[i]
 * If height[i] is less than that of top, pop the stack and find the maximum rectangle which contains the popped element.
 * To find the area of that maximum rectangle, use the value of top of the stack to determine the length of base.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<string>
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
long long max_ans;int n,histo[100002];
stack<int> foo;
long long getmax(int curr,int bar)
{
    long long ans=histo[curr];
    int left=foo.size()>0?foo.top():-1;
    return ans*(bar-left);
}
void getans()
{
    for(int i=0;i<n;i++)
    {
        if(foo.empty())
        {
            foo.push(i);continue;
        }
        if(histo[foo.top()]<=histo[i]){foo.push(i);continue;}
        while(foo.size()>0 && histo[foo.top()]>=histo[i])
        {
            long long k=foo.top();
            foo.pop();
            k=getmax(k,i-1);
            max_ans=MAX(max_ans,k);
        }
        foo.push(i);
    }
    while(!foo.empty())
    {
        long long k=foo.top();
        foo.pop();
        k=getmax(k,n-1);
        max_ans=MAX(max_ans,k);
    }
}
int main()
{
    while(1)
    {
        in_I(n);
        if(n==0)return 0;
        max_ans=0;
        for(int i=0;i<n;i++)in_I(histo[i]);
        getans();
        printf("%lld\n",max_ans);
    }
}
