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
string str;
int bef[26][1001];
int getans(int a, int b, int c)
{
    if(a > b)
        return 0;
    int x = (c != str[a]-'A')+getans(a+1, bef[str[a]-'A'][b+1]-1, str[a]-'A') + getans(bef[str[a]-'A'][b+1]+1,b, c);
//    cout<<a<<" "<<b<<" "<<c<<endl;
    return x;
}
int main()
{
    in_T
    {
        cin>>str;
        for(int i = 0; i<str.length(); i++)
        {
            for(int j = 0; j<26; j++)
                bef[j][i+1] = bef[j][i];
            bef[str[i]-'A'][i+1] = i;
        }
        printf("%d\n", getans(0, str.length()-1, -1));
    }
}
