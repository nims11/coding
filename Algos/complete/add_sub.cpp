#include<cstring>
#include<cstdio>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
const long long BASE=10;
const int BASE_pow=1;
class BIGNUM
{
    public:
    long long *N;
    int size;
};
int int_len(long long x)
{
    int count=0;
    do
    {
        x/=10;
        count++;
    }while(x!=0);
    return count;
}
void show(BIGNUM &n)
{
    int i;
    for(i=n.size-1;n.N[i]<=0 && i>0;i--);
    int start=i;
    for(;i>=0;i--)
    {
        int len=int_len(n.N[i]);
        for(int j=0;j<BASE_pow-len && i!=start;j++)
        printf("0");
        printf("%lld",n.N[i]);
    }
    printf("\n");
}
void docarry(BIGNUM &N)
{
    int carry=0;
    int j,i;
    for(j=N.size-1;N.N[j]<=0 && j>0;j--);
    for(i=0;i<=j;i++)
    {
        N.N[i]+=carry;
        carry=N.N[i]/BASE;
        N.N[i]%=BASE;
    }
    while(carry>0)
    {
        N.size++;
        N.N[i]=carry%BASE;
        carry/=BASE;
        i++;
    }
}
void add(BIGNUM &N1,BIGNUM &N2,BIGNUM &N3)
{
    int size1=MAX(N1.size,N2.size),size2=MIN(N1.size,N2.size);
    N3.N=new long long[size1+1];
    N3.size=size1;
    for(int i=0;i<size2;i++)
    {
        N3.N[i]=N1.N[i]+N2.N[i];
    }
    if(N1.size==size1)
    for(int i=size2;i<size1;i++)
    {
        N3.N[i]=N1.N[i];
    }else
    for(int i=size2;i<size1;i++)
    {
        N3.N[i]=N2.N[i];
    }
    docarry(N3);
}
void sub(BIGNUM &N1,BIGNUM &N2,BIGNUM &N3)
{
    int size1=N1.size,size2=N2.size;
    N3.N=new long long[size1];
    N3.size=size1;
    bool carry=false;
    for(int i=0;i<size1;i++)
    {
        long long x,y=0;
        x=N1.N[i];
        if(i<size2)
        y=N2.N[i];

        if(!carry)
        {
            if(x<y)
            {
                carry=true;
                N3.N[i]=x+10-y;
            }else
            N3.N[i]=x-y;
        }else
        {
            carry=false;
            if(x-1<y)
            {
                carry=true;
                N3.N[i]=x+9-y;
            }else
            N3.N[i]=x-1-y;
        }
    }
    for(int i=size1-1;i>0 && N3.N[i]==0;i--)
    N3.size--;
}
void getInput(BIGNUM &N1)
{
    char tmp[10001];
    scanf("%s",tmp);
    int len=strlen(tmp);
    N1.size=(len-1)/BASE_pow + 1;
    N1.N=new long long[N1.size];
    for(int i=0;i<N1.size;i++)
    N1.N[i]=0;
    for(int i=0;i<len;i++)
    {
        N1.N[((len-1-i)/BASE_pow)]=N1.N[(len-1-i)/BASE_pow]*10+tmp[i]-'0';
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        BIGNUM N1,N2,N3;
        getInput(N1);
        getInput(N2);

        sub(N1,N2,N3);
//        docarry(N3);
        show(N3);
    }
    return 0;
}

