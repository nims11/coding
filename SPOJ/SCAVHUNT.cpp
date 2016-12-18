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
    int c=0;
    in_T
    {
        c++;
        map<string, pair<int, string> > foo;
        map<string, pair<int, string> >::iterator it;
        int n;
        in_I(n);
        string str1, str2;
        for(int i=0;i<n-1;i++)
        {
            cin>>str1>>str2;
            it = foo.find(str1);
            if(it!=foo.end())
            {
                (it->second).first +=1;
                (it->second).second = str2;
            }else
                foo[str1] = make_pair(1, str2);
            it = foo.find(str2);
            if(it!=foo.end())
            {
                (it->second).first +=1;
            }else
                foo[str2] = make_pair(1, "");
        }
        for(it = foo.begin();;it++)
        {
            if((it->second).first == 1 && (it->second).second!="")
            break;
        }
        string str = it->first;
        printf("Scenario #%d:\n", c);
        while(str!="")
        {
            cout<<str<<endl;
            str = foo[str].second;
        }
        newline;
    }
}
