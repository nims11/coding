#include<cstring>
#include<cstdio>
#define BASE 1000000
#define L long long
#define I int
#define F for
I t,i,s,l,j;
struct B{L *N;I s;};
I Z(L x){I c=0;do{x/=10;c++;}while(x);return c;}
I X(B &a,B &b,B &N)
{
    I j,i,c=0,m=a.s,n=b.s;
    N.s=m+n;
    N.N=new L[N.s];
    F(i=0;i<n;i++)
    {
        I k=0;
        F(j=0;j<m;j++)
        {
            N.N[k+i]+=b.N[i]*a.N[j]+c;
            c=N.N[k+i]/BASE;
            N.N[k+++i]%=BASE;
        }
    }
    F(j=N.s-1;N.N[j]<=0&&j;j--);
    N.N[j]=c;
}
I G(B &N){char t[10001];scanf("%s",t);l=strlen(t);N.s=(l-1)/6+1;N.N=new L[N.s];F(i=0;i<N.s;i++)N.N[i]=0;F(i=0;i<l;i++){N.N[(l-1-i)/6]=N.N[(l-1-i)/6]*10+t[i]-'0';}}
I main(){scanf("%d",&t);F(;t--;){B a,b,n;G(a);G(b);X(a,b,n);F(i=n.s-1;!n.N[i]&&i;i--);s=i;F(;i>=0;i--){l=Z(n.N[i]);F(j=0;j<6-l&&i!=s;j++)printf("0");printf("%lld",n.N[i]);}printf("\n");}}
