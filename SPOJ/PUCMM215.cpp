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
int main()
{
    long long n1,n2,x,ans1,ans2;
    string str;
    while(getline(cin,str))
    {
        n1 = n2 = 0;
        int a = 0;
        while(str[a]>='0' && str[a]<='9')
        {
            n1 = n1*10 + str[a] - '0';
            a++;
        }
        if(a == str.length())
        {
            x = (n1-1) / 23;
            if(x%2==0)
            {
                x/=2;
                cout<<(2+23*x)<<", "<<(23*x+1+(n1-1)%23)<<endl;
            }else
            {
                x/=2;x++;
                cout<<(23*(x-1)+2+(n1-1)%23)<<", "<<(23*x+1)<<endl;
            }
        }else
        {
            a++;
            while(a<str.length())
            {
                n2 = n2*10 + str[a] - '0';
                a++;
            }
            if(n1==0 && n2==0)return 0;
            bool flag = false;
            if((n1-2)%23 == 0)
            {
                x = (n1-2)/23;
                if(x>=0)
                {
                    if(23*x+1 <= n2 && n2<=23*(x+1))
                    {
                        flag = true;
                        ans1 = 46*x + n2 - 23*x;
                    }
                }
            }

            if(!flag && (n2-1)%23 == 0)
            {
                x = (n2-1)/23;
                if(x>=1)
                {
                    if(23*(x-1)+2 <= n1 && n1<=23*x+1)
                    {
                        flag = true;
                        ans1 = 23*(2*x-1) + n1 - 23*(x-1)-1 ;
                    }
                }
            }
            if(flag)
            cout<<ans1<<endl;
            else
            cout<<"No Number\n";
        }

    }
}
