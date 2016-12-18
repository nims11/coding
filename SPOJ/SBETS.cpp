/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<map>
#include<string>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;
int main()
{
    int n,a1,a2;char str1[4],str2[4];
    map<string,bool> teams;
    map<string,bool>::iterator it;
    in_T
    {
        teams.clear();
        for(int i=0;i<16;i++){
            in_S(str1);in_S(str2);
            in_I(a1);in_I(a2);
            if(teams.find(str1)==teams.end())teams[str1]=true;
            if(teams.find(str2)==teams.end())teams[str2]=true;
            teams[str1]&=a1>a2;
            teams[str2]&=a1<a2;
        }
        for(it=teams.begin();it!=teams.end();it++)
        {
            if(it->second)
            {
                printf("%s\n",it->first.c_str());break;
            }
        }
    }

}
