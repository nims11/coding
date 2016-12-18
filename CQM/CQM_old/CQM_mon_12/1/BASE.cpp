/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
char str_num[1000];int base_from,base_to,inter_count,final_count,inter;
char final[1000];
int foo[200];
void to_dec()
{
    inter=0;
    int foo1=1;
    int len=strlen(str_num);
    for(int i=len-1;i>=0;i--)
    {
        inter+=(foo[str_num[i]])*foo1;
        foo1*=base_from;
    }
}
void to_base_n()
{
    final_count=0;
    do
    {
        int k=inter%base_to;
        if(k<10)
        final[final_count++]=k+'0';
        else
        final[final_count++]=k-10+'A';
        inter/=base_to;
    }while(inter>0);
}
int main()
{
    for(char i='0';i<='9';i++)
    foo[i]=i-'0';
    for(char i='A';i<='Z';i++)
    foo[i]=10+i-'A';
    in_T
    {
        cin>>base_from>>str_num>>base_to;
        to_dec();
        to_base_n();
        for(int i=final_count-1;i>=0;i--)printf("%c",final[i]);
            newline;
    }
}
