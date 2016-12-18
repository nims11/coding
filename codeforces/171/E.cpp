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
    cin>>str;
    int pre[2] = {0, 1};
    int pre_star = 1;
    int x,y;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '0')
        {

            x = min(pre[0], pre[1]+1);
            y = pre_star+1;
            pre_star = y;
        }else
        {
            if(i==0)
            {
                x = 1, y = 2;
            }else
            {
                if(str[i-1] == '0')
                    x = min(pre[0], pre[1]+1)+1;
                else
                    x = 1+min(pre[0], pre[1]);

                y = pre_star+1;
            }
        }

        pre[0] = x, pre[1] = y;
//        cout<<x<<" "<<y<<endl;
    }
    if(str[str.length()-1] != '0')
    cout<<min(pre[0], pre[1])<<endl;
    else
        cout<<min(pre[0], pre[1]+1)<<endl;
}
