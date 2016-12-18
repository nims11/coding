/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<set>
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
set <string> X;
set <string>::iterator pre,it;
int main()
{
    int n;char str[12];
    in_T
    {
        X.clear();
        in_I(n);
        for(int i=0;i<n;i++)
        {
            in_S(str);
            X.insert(str);
        }
        bool flag=true;
        pre=X.begin();
        it=pre;it++;
        for(;it!=X.end();it++)
        {
            bool found=true;
            for(int i=0;i<pre->length();i++)
            {
                if((*pre)[i]!=(*it)[i]){found=false;break;}
            }
            if(found){flag=false;break;}
            pre=it;
        }
        if(flag)
        printf("YES\n");
        else
        printf("NO\n");
    }
}
