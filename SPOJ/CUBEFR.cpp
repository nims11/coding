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
int main()
{
    int cubes[101];
    for(int i=0;i<=100;i++)
        cubes[i] = i*i*i;
    int nums[1000001]={0};
    for(int i=2;i<=100;i++)
    {
        int k = cubes[i];
        while(k<=1000000)
        {
            nums[k]=-1;
            k+=cubes[i];
        }
    }
    int count=1;
    for(int i=1;i<=1000000;i++)
    {
        if(!nums[i])
            nums[i] = count++;
    }
    int c=0;
    in_T
    {
        c++;
        int n;
        in_I(n);
        cout<<"Case "<<c<<": ";
        if(nums[n]==-1 || !nums[n])
        {
            cout<<"Not Cube Free\n";
        }else
        cout<<nums[n]<<endl;
    }
}
