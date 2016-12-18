/*
ID: nimeshg1
PROG: crypt1
LANG: C++
*/
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
#include<fstream>
#include<utility>
#include<set>
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
#include<cstring>
using namespace std;
ifstream fin("crypt1.in");
ofstream fout("crypt1.out");
int arr[10];
int n;
bool isValid(int n1, int len)
{
    int f = 0;
    while(n1)
    {
        f++;
        int foo = n1%10;
        n1/=10;
        int i;
        for(i=0;i<n;i++)
        {
            if(arr[i]==foo)
            break;
        }
        if(i==n)
        return false;
    }
    if(f==len)
    return true;
    return false;
}
int main()
{
    fin>>n;
    int ans = 0;
    for(int i=0;i<n;i++)
        fin>>arr[i];
    for(int a=0;a<n;a++)
        for(int b=0;b<n;b++)
            for(int c=0;c<n;c++)
                for(int d=0;d<n;d++)
                    for(int e=0;e<n;e++)
                    {
                        int t1 = arr[a],t2 = arr[b], t3 = arr[c], t4 = arr[d], t5 = arr[e];
                        int foo = t1*100 + t2*10 + t3;
                        int x = foo*t4;
                        if(!isValid(x,3))
                            break;
                        int y = foo*t5;
                        if(!isValid(y,3))
                            continue;
                        if(isValid(x + y*10,4))
                            ans++;
                    }
    fout<<ans<<endl;
}
