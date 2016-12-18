/*
Objective: to find the lexigraphically smallest string.
Solution: evident from the code.
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

int main()
{
    char str[10003];
    in_T
    {
        in_S(str);
        int len=strlen(str);
        int min=0;int curr=1;
        while(curr<len)
        {
            int k=0;
            while(k<len && str[(min+k)%len]==str[(curr+k)%len])k++;
            if(k==len)break;
            if(str[(min+k)%len]>str[(curr+k)%len])
            {
                min=curr;
                curr++;
            }else
            curr+=k+1;
        }
        printf("%d\n",min+1);
    }
}
