/*
    Nimesh Ghelani (nims11)
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
    long long t3,tn_3,Sn,d,a,n,A,B,C,D;double Ba;
    in_T
    {
        scanf("%lld%lld%lld",&t3,&tn_3,&Sn);
        A = t3 + tn_3;
        Ba = 7.0*t3 + 5.0*tn_3 +2.0*Sn;
        C = 12.0*Sn;
        D = llrintl(sqrtl(Ba*Ba - 4*double(A)*C));
//        cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
        bool flag = true;
        if( 1)
        {
            n = ((llrintl(Ba)+D)/2)/A;
            if(1)
            {
                d = (tn_3 - t3)/(n-6);
                a = t3 - 2*d;
            }
//            else
//            flag = false;
        }
//        else flag = false;
//
//        if(!flag)
//        {
//            n = (Ba-D)/A;
//            d = (tn_3 - t3)/(n-6);
//            a = t3 - 2*d;
//        }
        cout<<n<<endl;
        for(long long i=0;i<n;i++)
        printf("%lld ",a + i*d);
        newline;
    }
}
