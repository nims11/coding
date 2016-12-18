/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
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
int at,bt;
int arr[100003];
int main()
{
    in_T
    {
        in_I(at);
        in_I(bt);
        arr[0]=0;
        for(int i=1;i<=at;i++)
            in_I(arr[i]);
        int start=0,end=0,curr=0,ans=0, ans2=0;
        while(end<at)
        {
            curr-=arr[start++];
            while(curr<bt && end<at)
            {
                curr+=arr[++end];
            }
            while(curr>bt && end>=0)
                curr-=arr[end--];

//            cout<<curr<<" "<<start<<" "<<end<<endl;
            if(ans<end-start+1)
            {
                ans = end-start+1;
                ans2 = curr;
            }else if(ans==end-start+1)
            {
                if(curr<ans2)
                    ans2=curr;
            }
        }
        printf("%d %d\n", ans2, ans);
    }
}
