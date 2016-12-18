#include<cstring>
#include<cstdio>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define P(a) printf("*%d\n",a);
int getInput(int a)
{
    char tmp2[255];
    int tmp[255];
    in_S(tmp2);
    if(a==0)
    {
        printf("%s\n",tmp2);
        return -1;
    }

    int len=strlen(tmp2);
    for(int i=0;i<len;i++)
    tmp[i]=tmp2[i]-'0';
    for(int i=0;i<len-1;i++)
    {
        tmp[i]%=a;
        tmp[i+1]+=10*tmp[i];
    }
    return tmp[len-1]%a;

}
int gcd(int a, int b)
{
	if (b==0)
		printf("%d\n",a);
	else
		return gcd(b,a%b);
}
int main()
{
    in_T
    {
        int a;
        in_I(a);
        int b=getInput(a);
        if(b!=-1)
        gcd(b,a);
    }
    return 0;
}
