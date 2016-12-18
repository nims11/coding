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
#define in_T int t;for(scanf("%d\n",&t);t--;)
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
    int cc = 0;
    in_T
    {
        cc++;
        string str;
        getline(cin, str);
        for(int i=0;i<str.length();i++)
        {
            if(i==0 && isalpha(str[i]))
                str[i] = toupper(str[i]);
            else if(str[i] == ' ')
                str[i] = '_';
            else if(i>0 && str[i-1]=='_' && isalpha(str[i]))
                str[i] = toupper(str[i]);
        }
        printf("Case#%d: ", cc);
        cout<<str<<endl;
    }
}
