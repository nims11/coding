#include<cstdio>
#define L long long
#define R return
L q=10,i,a,b,*g;struct B{L s,N[3000];};L l(L x){b=1;while(x/=10)b++;R b;}
B k={1};
B M(B N,B M)
{
    B O={N.s+M.s};
    for(i=0;M.s-i;i++)
    for(a=b=0;b<N.s;)
    O.N[a+++i]+=M.N[i]*N.N[b++];
    for(a=i=0;i<O.s;)g=O.N+i++,a=(*g+=a)/q,*g%=q;a?*g=a%q:0;
    R O;
}
B P(L a,L b){*k.N=a;R b-1?M(P(a,b/2),P(a,b-b/2)):k;}
main(){while(scanf("%d%d",&a,&b))if(a){B n=P(a,b);for(i=n.s-1;!n.N[i];i--);for(a=i;i+1;i--){L w=l(n.N[i]),j=0;for(;j<1-w&i-a;j++)printf("0");printf("%lld",n.N[i]);}printf("\n");}else break;}
