/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cstring>
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
char inf_1[]="aeiou",inf_2[]="bcdfghjklmnpqrstvwxyz",str[50002];
int len_1=5,len_2=21;
int map_1[26],map_2[26];
int main()
{
    for(int i=0;i<26;i++)
    map_1[i]=map_2[i]=-1;

    for(int i=0;i<len_1;i++)
    map_1[inf_1[i]-'a']=i;
    for(int i=0;i<len_2;i++)
    map_2[inf_2[i]-'a']=i;

    in_T
    {
        in_S(str);
        int k[26]={0};
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            k[str[i]-'a']++;
            if(map_1[str[i]-'a']!=-1)
            {
                int occ=k[str[i]-'a'];
                occ=(occ-1)*len_1+map_1[str[i]-'a'];
                printf("%c",inf_2[occ%len_2]);
            }else
            {
                int occ=k[str[i]-'a'];
                occ=(occ-1)*len_2+map_2[str[i]-'a'];
                printf("%c",inf_1[occ%len_1]);
            }
        }
        newline;
    }
}
