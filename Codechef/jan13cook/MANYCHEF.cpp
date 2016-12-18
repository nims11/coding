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
    in_T
    {
        string str;
        cin>>str;
        for(int i=str.length()-1;i>=3;i--)
        {
            if(str[i] != '?' && str[i] != 'F')
                continue;
            bool flag = false;
            if(str[i-1] == 'E' || str[i-1] == '?')
                if(str[i-2] == 'H' || str[i-2] == '?')
                    if(str[i-3] == 'C' || str[i-3] == '?')
                        flag = true;
            if(flag)
            {
                str[i] = 'F';
                str[i-1] = 'E';
                str[i-2] = 'H';
                str[i-3] = 'C';
            }else
            {
                if(str[i]=='?')str[i] = 'A';
            }
        }
        if(str.length()<4)
        {
            for(int i=0;i<str.length();i++)
            if(str[i] == '?')str[i] = 'A';
        }else
            for(int i=0;i<4;i++)
            if(str[i] == '?')str[i] = 'A';
        cout<<str<<endl;
    }
}
