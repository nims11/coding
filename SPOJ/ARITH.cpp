#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
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
void docarry(BIGNUM &N,bool foo=true)
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
        if(foo)
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
void multiply_nor(BIGNUM &N1,BIGNUM &N2,BIGNUM &N3)
{
    int size1=N1.size,size2=N2.size;
    std::vector<BIGNUM> baz;
    N3.N=new long long[size1+size2];
    N3.size=size1+size2;
    for(int i=0;i<N3.size;i++)
    N3.N[i]=0;
    for(int i=0;i<size2;i++)
    {
        BIGNUM bar;
        bar.N=new long long[size1+1];
        bar.size=size1+1;
        bar.N[size1]=0;

        int k=0,carry2=0;
        long long x=N2.N[i];
        long long carry=0;
        for(int j=0;j<size1;j++)
        {
            long long y=N1.N[j];
            bar.N[j]=x*y;
            N3.N[k+i]+=x*y;
            k++;
        }
        docarry(bar,false);
        while(bar.N[bar.size-1]==0 && bar.size>1)
        bar.size--;
        baz.push_back(bar);
    }
    while(N3.N[N3.size-1]==0 && N3.size>1)
    N3.size--;
    docarry(N3,true);

    if(baz.size()==1)
    {
        int foo=MAX(N1.size,N2.size) + 1;
        int tux=MAX(N3.size,N2.size+1);
        for(int i=0;i<tux-N1.size;i++)
        printf(" ");
        show(N1);
        for(int i=1;i<tux-N2.size;i++)
        printf(" ");
        printf("*");
        show(N2);
//        for(int i=0;i<foo-tux;i++)
//        printf(" ");
        for(int i=0;i<tux;i++)
        printf("-");
        printf("\n");
        for(int i=0;i<tux-N3.size;i++)
        printf(" ");
        show(N3);
    }else
    {
        int foo=MAX(N3.size,N2.size+1);
        int foo2=MAX(N1.size,N2.size+1);
        int foo3=MAX(baz[0].size,N2.size+1);
        for(int i=0;i<foo-N1.size;i++)
        printf(" ");
        show(N1);
        for(int i=1;i<foo-N2.size;i++)
        printf(" ");
        printf("*");
        show(N2);
        for(int i=0;i<foo-foo3;i++)
        printf(" ");
        for(int i=0;i<foo3;i++)
        printf("-");
        printf("\n");
        for(int i=0;i<baz.size();i++)
        {
            for(int j=0;j<foo-baz[i].size-i;j++)
            printf(" ");
            show(baz[i]);
        }

        for(int i=0;i<foo-N3.size;i++)
        printf(" ");
        for(int i=0;i<N3.size;i++)
        printf("-");
        printf("\n");
        for(int i=0;i<foo-N3.size;i++)
        printf(" ");
        show(N3);
    }
}
void getInput(BIGNUM &N1,BIGNUM &N2,char &op)
{
    char tmp[600];
    scanf("\n%[0123456789]",tmp);
    scanf("%c",&op);
    int len=strlen(tmp);
    N1.size=len;
    N1.N=new long long[N1.size];
    for(int i=0;i<N1.size;i++)
    N1.N[i]=tmp[len-1-i]-'0';
    scanf("%[0123456789]",tmp);
    len=strlen(tmp);
    N2.size=len;
    N2.N=new long long[N2.size];
    for(int i=0;i<N2.size;i++)
    N2.N[i]=tmp[len-1-i]-'0';
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        BIGNUM N1,N2,N3;
        char op;
        getInput(N1,N2,op);
        switch(op)
        {
            int foo;
            int tux;
            case '+':
            add(N1,N2,N3);
            foo=MAX(N1.size,N2.size+1);
            tux=MAX(N3.size,N2.size+1);
            for(int i=0;i<foo-N1.size;i++)
            printf(" ");
            show(N1);
            for(int i=1;i<foo-N2.size;i++)
            printf(" ");
            printf("+");
            show(N2);
            for(int i=0;i<foo-tux;i++)
            printf(" ");
            for(int i=0;i<tux;i++)
            printf("-");
            printf("\n");
            for(int i=0;i<foo-N3.size;i++)
            printf(" ");
            show(N3);
            break;

            case '-':
            sub(N1,N2,N3);
            foo=MAX(N1.size,N2.size+1);
            tux=MAX(N3.size,N2.size+1);
            for(int i=0;i<foo-N1.size;i++)
            printf(" ");
            show(N1);
            for(int i=1;i<foo-N2.size;i++)
            printf(" ");
            printf("-");
            show(N2);
            for(int i=0;i<foo-tux;i++)
            printf(" ");
            for(int i=0;i<tux;i++)
            printf("-");
            printf("\n");
            for(int i=0;i<foo-N3.size;i++)
            printf(" ");
            show(N3);
            break;

            case '*':
            multiply_nor(N1,N2,N3);
            break;
        }
        printf("\n");

//        sub(N1,N2,N3);
//        show(N3);
    }
    return 0;
}


