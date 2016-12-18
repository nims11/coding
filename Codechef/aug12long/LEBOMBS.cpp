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
int main()
{
    in_T
    {
        int n;
        in_I(n);
        char str[1003];
        in_S(str);
        bool destroyed[1003]={0};
        destroyed[0]=1;
        destroyed[n+1]=1;
        int ans=n;
        for(int i=1;i<=n;i++)
        {

            if(str[i-1]=='1')
            {
                destroyed[i]=true;
                ans--;
                if(!destroyed[i-1]){destroyed[i-1]=true;ans--;}
                if(!destroyed[i+1] && str[i]=='0'){destroyed[i+1]=true;ans--;}
            }
        }
        cout<<ans<<endl;
    }
}
