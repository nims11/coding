/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
map<int,string> code_of;
map<string,int> digit_of;
int main()
{
    code_of[0]="063";code_of[1]="010";code_of[2]="093";code_of[3]="079";code_of[4]="106";code_of[5]="103";code_of[6]="119";code_of[7]="011";code_of[8]="127";code_of[9]="107";
    map<int,string>::iterator it;
    for(it=code_of.begin();it!=code_of.end();it++)
        digit_of[it->second]=it->first;
    char expr[200],tmp[4];
    long long num1,num2,res;

    tmp[3]=0;
    while(1)
    {
        in_S(expr);
        if(expr[0]=='B')break;
        num1=num2=res=0;
        int i;
        for(i=0;expr[3*i]!='+';i++)
        {
            tmp[0]=expr[3*i];tmp[1]=expr[3*i+1];tmp[2]=expr[3*i+2];
            num1=num1*10+digit_of[tmp];
        }
        char *expr2=expr+3*i+1;
        for(i=0;expr2[3*i]!='=';i++)
        {
            tmp[0]=expr2[3*i];tmp[1]=expr2[3*i+1];tmp[2]=expr2[3*i+2];
            num2=num2*10+digit_of[tmp];
        }
        res=num1+num2;
        long long x=1000000000;
        while(res/x == 0)x/=10;
        cout<<expr;
        while(x>0)
        {
            cout<<code_of[res/x];
            res%=x;
            x/=10;
        }
        cout<<endl;
    }
}
