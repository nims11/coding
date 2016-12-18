/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cstring>
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
int len,k;
char str[105];
bool isValid(char str[])
{
    if(len==1)return true;
    if(str[0]==str[len-1] && str[0]!='?')return false;
    for(int i=0;i<len-1;i++)
    if(str[i]!='?' && str[i]==str[i+1])
    return false;
    return true;
}
bool get_ans(int start)
{
    while(str[start]!='?' && start<len)start++;
    if(start==len)return true;
    for(int i=0;i<k;i++)
    {
        if(str[(len+start-1)%len]!='0'+i && '0'+i!=str[(start+1)%len])
        {
            str[start]=i+'0';
            if(get_ans(start+1))return true;
        }
    }
    str[start]='?';
    return false;
}
int main()
{
    in_T
    {
        in_I(k);in_S(str);
        len=strlen(str);

        if(!isValid(str))
        {
            printf("NO\n");continue;
        }

        if(get_ans(0))printf("%s\n",str);
        else printf("NO\n");


    }
}

