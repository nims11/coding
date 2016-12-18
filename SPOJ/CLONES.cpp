/*
Given two sets of characters (say A and B), the problem boils down to finding size(A [intersection] B)
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<map>

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
    int t,n;char str[22];
    map<string,int> dna;
    map<string,int>::iterator it;
    map<int,int> ans;
    while(1)
    {
        ans.clear();
        dna.clear();
        in_I(t);in_I(n);
        if(t==0)break;
        for(int i=0;i<t;i++)
        {
            ans[i]=0;
            in_S(str);
            it=dna.find(str);
            if(it==dna.end())
            dna[str]=0;
            else
            dna[str]++;
        }
        for(it=dna.begin();it!=dna.end();it++)
        {
            ans[it->second]++;
        }
        for(int i=0;i<t;i++)
        printf("%d\n",ans[i]);
    }
}
