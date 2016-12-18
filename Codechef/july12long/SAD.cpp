/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
//returns element >=n
int search_b(int *nums, int n, int end)
{
    int start=0;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(nums[mid]<n)
        {
            start=mid+1;
            continue;
        }
        if(nums[mid]>n)
        {
            end=mid-1;
            continue;
        }
        return mid;
    }
    return -1;
}

int main()
{
    int r,c,tmp,min_R[100],max_C[100]={0};
    for(int i=0;i<100;i++)min_R[i]=1<<30;

    in_I(r);in_I(c);
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    {
        in_I(tmp);
        if(tmp>max_C[j])max_C[j]=tmp;
        if(tmp<min_R[i])min_R[i]=tmp;
    }

    sort(min_R,min_R+r);
    for(int i=0;i<c;i++)
    {
        int foo=search_b(min_R,max_C[i],r-1);
        if(foo!=-1)
        {
            cout<<max_C[i]<<endl;
            return 0;
        }
    }
    cout<<"GUESS"<<endl;
}
