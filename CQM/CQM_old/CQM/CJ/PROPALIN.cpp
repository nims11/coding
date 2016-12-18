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
string str;
int main()
{
    in_T
    {
        int k;
        in_I(k);
        cin>>str;
        int foo = 0;
        for(int i=0;i<str.length()-k+1;i++)
        {
            if(str[i] == str[i+k-1])
            {
                bool flag = true;
                int st = i;
                int end = i+k-1;
                for(int j=st;j<(end+st)/2;j++)
                {
                    if(str[j] != str[end-j+st])
                    {
                        flag = false;
                        break;
                    }
                }
                foo+=flag;
            }
        }
        int tot = str.length()-k+1;
        printf("%.4lf\n", double(foo)/tot);
    }
}
