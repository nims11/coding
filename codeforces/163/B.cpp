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
    int n,t;
    cin>>n>>t;
    string str;
    cin>>str;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<str.size()-1;j++)
        {
            if(str[j] == 'B' && str[j+1] == 'G')
            {
                str[j] = 'G';
                str[j+1] = 'B';
                j++;
            }
        }
    }
    cout<<str<<endl;
}
