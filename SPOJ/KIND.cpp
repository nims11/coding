/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}

using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        int count=0;
        bool flag=false;
        for(int i=0;i<str.length();i++)
        {
            if(!flag)
            {
                if(isalpha(str[i]))
                {
                    flag=true;
                    count++;
                }
                continue;
            }else
            {
                if(!isalpha(str[i]))
                flag=false;
            }
        }
        if(str.length()>0)
        printf("%d\n",count);
    }
}
