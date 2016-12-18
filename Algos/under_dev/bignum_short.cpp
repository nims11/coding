#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const long long BASE=1000000;
const int BASE_pow=6;
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
        N.N[i]=carry%BASE;
        carry/=BASE;
        i++;
    }
}
void add(BIGNUM &N1,BIGNUM &N2,BIGNUM &N3,bool do_carry=true)
{
    BIGNUM *num1,*num2;
    if(N1.size>N2.size)
    {
        num1=&N1;
        num2=&N2;
    }else
    {
        num1=&N2;
        num2=&N1;
    }

    N3.size=1+num1->size;
    N3.N=new long long[N3.size];

    for(int i=0;i<num2->size;i++)
    {
        N3.N[i]= num1->N[i] + num2->N[i] ;
    }
    for(int i=num2->size;i<num1->size;i++)
    N3.N[i]=num1->N[i];
    N3.N[N3.size-1]=0;
    if(do_carry)
    docarry(N3);
}
void multiply_nor(BIGNUM &N1,BIGNUM &N2,BIGNUM &N3, bool do_carry=true)
{
    int size1=N1.size,size2=N2.size;
    N3.N=new long long[size1+size2];
    N3.size=size1+size2;
    for(int i=0;i<size2;i++)
    {
        int k=0,carry2=0;
        long long x=N2.N[i];
        long long carry=0;
        for(int j=0;j<size1;j++)
        {
            long long y=N1.N[j];
            N3.N[k+i]+=x*y;
            k++;
        }
    }
    if(do_carry)
    docarry(N3);
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

        add(N1,N2,N3,false);
        docarry(N3);
        show(N3);
    }
    return 0;
}
