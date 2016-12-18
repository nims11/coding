#include<cstdio>
//using namespace std;
char a[]={'A','W','W','A','A','M','W','W','M','A'};
char b[]={'L','L','L','L','R','R','R','R','R','R'};
int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        if(n==1)
        printf("poor conductor\n");
        else
        {
            x=n%10;
            printf("%lld %c %c\n",(n-2)/5+1,a[x],b[x]);
        }
    }
    return 0;
}
