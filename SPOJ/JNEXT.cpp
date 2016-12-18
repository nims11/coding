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
char arr[1000000];
int main()
{
    in_T
    {
        int n;
        in_I(n);
        for(int i=0;i<n;i++)
            in_I(arr[i]);
        bool flag = false;
        int tmp = 0, foo;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]<arr[i+1])
            {
//                tmp = arr[i+1];
//                int j = upper_bound(arr, arr+i+1, tmp) - arr;
//                for(int j=n-1;j>i-1;j--)
//                {
//                    if(arr[j]>tmp)
//                    {
//                        arr[i+1] = arr[j];
//                        arr[j] = -1;
//                        foo = i+1;
//                    }
//                }
                flag=true;
                break;
            }
        }
//        cout<<foo<<" "<<tmp<<endl;
        if(flag)
        {
            next_permutation(arr, arr+n);
            for(int i=0;i<n;i++)
//                if(arr[i]!=-1)
//                {
//                    if(i<foo && tmp<=arr[i])
//                        {cout<<tmp;tmp=-1;}
                    printf("%d", arr[i]);
//                }
//                if(tmp!=-1)
//                    cout<<tmp;
                newline;
        }else
        printf("-1\n");
    }
}
