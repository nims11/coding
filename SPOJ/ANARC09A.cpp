/*
Objective: minimum number of operations (replacements) needed to convert the given string of braces into a balanced one.

Solution: read the code, it is easy to understand.
*/
#include<iostream>
#include<cstdio>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
int main()
{
    char str[2005];
    int t=0;
    while(1)
    {
        t++;
        in_S(str);
        if(str[0]=='-')return 0;
        int curr=0,count=0;
        for(int i=0;str[i]!=0;i++)
        {
            if(str[i]=='}')
            curr--;
            else
            curr++;
            if(curr<0)
            {
                curr=1;count++;
            }
        }
        count+=curr/2;
        printf("%d. %d\n",t,count);

    }
    return 0;
}

