/*
    Nimesh Ghelani (nims11)
*/
#include<cstring>
#include<cstdio>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define P(a) printf("* %d ",a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

int main()
{
    in_T
    {
        char a[2][20];
        in_S(a[0]);in_S(a[1]);
        int a1[2][4]={{0}},c[4]={0};
        int len[2]={strlen(a[0]),strlen(a[1])};
        for(int m=0;m<2;m++)
        for(int i=0;i<len[m];i++)
        {
            switch(a[m][i])
            {
                case 'm': a1[m][0]=1;break;
                case 'c': a1[m][1]=1;break;
                case 'x': a1[m][2]=1;break;
                case 'i': a1[m][3]=1;break;
                default :
                switch(a[m][i+1])
                {
                    case 'm': a1[m][0]=a[m][i]-'0';break;
                    case 'c': a1[m][1]=a[m][i]-'0';break;
                    case 'x': a1[m][2]=a[m][i]-'0';break;
                    case 'i': a1[m][3]=a[m][i]-'0';break;
                }
                i++;
            }
        }

        for(int i=0;i<4;i++)c[i]=a1[0][i]+a1[1][i];
        int carry=0;
        for(int i=3;i>=0;i--)
        {
            c[i]+=carry;
            carry=c[i]/10;
            c[i]%=10;
        }
        if(c[0])
        {
            if(c[0]==1)printf("m");
            else printf("%dm",c[0]);
        }
        if(c[1])
        {
            if(c[1]==1)printf("c");
            else printf("%dc",c[1]);
        }if(c[2])
        {
            if(c[2]==1)printf("x");
            else printf("%dx",c[2]);
        }if(c[3])
        {
            if(c[3]==1)printf("i");
            else printf("%di",c[3]);
        }
        newline;
    }
}
