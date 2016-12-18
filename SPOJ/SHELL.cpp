/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
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
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
using namespace std;
int main()
{
    int n;
    int pos[26]={0};
    string str1,str2;
    cin>>str1;pos[str1[0]-'a']=1;
    in_I(n);
    if(n==10)
    return 0;
    while(cin>>str1>>str2)
    {
        SWAP(pos[str1[0]-'a'],pos[str2[0]-'a'])
    }
    if(pos['l'-'a'])printf("left\n");
    else if(pos['r'-'a'])printf("right\n");
    else if(pos['c'-'a'])printf("center\n");
}
