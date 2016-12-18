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
#include<set>
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
    string str;
    while(cin>>str)
    {
        if(str[0] == 'Q')
            return 0;
        set<int> foo[10000];
        int curx = 5000, cury=5000;
        int inter = 0;
        foo[curx].insert(cury);
        for(int i=0;i<str.length()-1;i++)
        {
            switch(str[i])
            {
            case 'U':
                cury++;
                break;
            case 'D':
                cury--;
                break;
            case 'L':
                curx--;
                break;
            case 'R':
                curx++;
                break;
            }
            if(foo[curx].find(cury) != foo[curx].end())
                inter++;
            else
                foo[curx].insert(cury);
        }
        printf("%d\n", inter);
    }
}
