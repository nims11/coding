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
#include<cstring>
using namespace std;
int look[10][10] =
{
    {1,0,0,0,0,0,0,0,1,0},
    {1,1,0,1,1,0,0,1,1,1},
    {0,0,1,0,0,0,0,0,1,0},
    {0,0,0,1,0,0,0,0,1,1},
    {0,0,0,0,1,0,0,0,1,1},
    {0,0,0,0,0,1,1,0,1,1},
    {0,0,0,0,0,0,1,0,1,0},
    {1,0,0,1,0,0,0,1,1,1},
    {0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1,1},
};
char src[10], dest[10];
int main()
{
    in_T
    {
        scanf("%s %s", src, dest);
        int len1 = strlen(src), len2 = strlen(dest);
        bool possi = false;
        //exact fitting
        for(int i=len2-1;i>=len1-1;i--)
        {
            bool flag = true;
            for(int j=len1-1;j>=0;j--)
            {
                if(!look[src[j]-'0'][dest[i-(len1-1-j)]-'0'])
                    {flag = false;break;}
            }
            if(flag)
            {
                printf("%s\n", dest);
                possi = true;
                break;
            }
        }
        if(possi)
        {
           continue;
        }

        int at_pos =-1;
        int foo;
        for(int i=len2-1;i>=len1-1 && i>=len2-len1;i--)
        {
            for(int j=0;j<len1;j++)
            {
                if(look[src[j]-'0'][dest[i-(len1-1-j)]-'0'])
                    continue;
                bool flag2 = false;
                for(int k=0;k<dest[i-(len1-1-j)]-'0';k++)
                {
                    if(look[src[j]-'0'][k])
                    {flag2 = true;break;}
                }
                if(!flag2)
                {
                    break;
                }else
                {
                    if(at_pos == -1)
                        at_pos = j, foo = i;
                    else
                        if(foo-len1+1+at_pos<i-len1+1+at_pos)
                            at_pos = j, foo = i;
                    break;
                }
            }
        }
        if(at_pos!=-1 && foo-len1+1+at_pos>=len2-len1)
        {
            for(int k=-1+dest[foo-len1+1+at_pos]-'0';k>=0;k--)
                if(look[src[at_pos]-'0'][k])
                    {dest[foo-len1+1+at_pos] = k+'0';break;}
            for(int i=foo-len1+1+at_pos+1, j = at_pos+1;i<foo+1;i++, j++)
            {
                for(int k=9;k>=0;k--)
                    if(look[src[j]-'0'][k])
                        {dest[i] = k+'0';break;}
            }
            printf("%s\n", dest);
            possi = true;
        }
        if(possi)
            continue;
        for(int j=len1-1;j>=0;j--)
        {
            for(int k=9;k>=0;k--)
            {
                if(look[src[j]-'0'][k])
                {dest[len2-1-(len1-1-j)] = k+'0';break;}
            }
        }
        if(dest[len2-len1-1] >'0')
            dest[len2-len1-1]--;
        else
        {
            int i = len2-len1-1;
            while(i>=0 && dest[i]=='0')
            {
                dest[i] = '9';
                i--;
            }
            if(i>=0)
                dest[i]--;
        }
        int i=0;
        char *str = dest;
        while(str[0]=='0' && i<len2-1)
            str++, i++;
        printf("%s\n", str);
    }
}
