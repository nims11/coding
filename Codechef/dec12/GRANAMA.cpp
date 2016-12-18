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
#include<set>
using namespace std;
int main()
{
    in_T
    {
        string str1, str2;
        cin>>str1>>str2;
        int foo1[26] = {0}, foo2[26] = {0};
        for(int i=0;i<str1.length();i++)
            foo1[str1[i]-'a']++;
        for(int i=0;i<str2.length();i++)
            foo2[str2[i]-'a']++;
        bool flag1 = true, flag2 = true;
        for(int i=0;i<26;i++)
        {
            if(foo1[i]!=foo2[i]){flag1 = false;break;}
        }
        for(int i=0;i<26;i++)
        {
            if((bool(foo1[i])^bool(foo2[i])))
            {
                flag2 = false;
                break;
            }
        }
//        cout<<flag1<<" "<<flag2<<endl;
        cout<<(!(flag1^flag2)?"YES":"NO")<<endl;
    }
}
