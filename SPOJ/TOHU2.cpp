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
#include<cstring>
#include<cstdlib>
#include<cassert>
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
    in_T
    {
        bool flag = true;
        char pre = 0;
        for(int i=0;i<99;i++)
        {
            int x;char ch;
            cin>>x>>ch;
            if(x != 90 && x%9 == 0 && x != 99)
            {
                if(pre == 0)
                    pre = ch;
                else
                    if(pre != ch)
                {
                    flag = false;
                }
            }
        }
        if(flag)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
    }
}
