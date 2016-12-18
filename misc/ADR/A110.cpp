/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
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
int main()
{
    std::vector <int> ans;
    int N[3],tmp;
    in_I(N[0]);in_I(N[1]);in_I(N[2]);
    std::map<int,int> foo;
    std::map<int,int>::iterator it;
    int count=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<N[i];j++){
        in_I(tmp);
        it=foo.find(tmp);
        if(it==foo.end())foo[tmp]=1;
        else it->second++;}
    }

    for(it=foo.begin();it!=foo.end();it++)
    {
        if(it->second>=2)
        {
            count++;
            ans.push_back(it->first);
        }
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++)
    {
        printf("%d\n",ans[i]);
    }
}

