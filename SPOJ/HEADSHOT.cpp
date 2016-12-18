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
    string str;
    cin>>str;
    int nxt_1 = 0, nxt_0 = 0, num_1=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '0')
        {
            if(str[(i+1)%str.length()]=='0')nxt_0++;
            else nxt_1++;
        }else
        num_1++;
    }
    if(nxt_1==nxt_0 || num_1 == 0)
    cout<<"EQUAL"<<endl;
    else if(nxt_1>nxt_0)
    cout<<"ROTATE"<<endl;
    else
    cout<<"SHOOT"<<endl;
}
