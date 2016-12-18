//GQ
/*
    Nimesh Ghelani (nims11)
    Find observe the pattern using bits and keep reducing the problem down to 2 bits.
    Since for the given n, 2^n can be very large, use log.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cmath>
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
int main()
{
    in_T
    {
        long long n,k;
        in_L(n);in_L(k);
        int c =0;
        while(k>2)
        {
            if(log2(k)>n-1)
                {c++;long long A =(long long)1<<(n-1); k = k - A;n--;}
            else
                n = (int)ceil(log2(k));
        }
        cout<<((k==1 && c%2==0 || (k==2 && c%2))?"Male":"Female")<<endl;
    }
}

