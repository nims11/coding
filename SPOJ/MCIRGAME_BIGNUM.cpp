/*
 * BIGNUM + divide and conquer
 * See the getans() function
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const long long BASE=10000;
const int BASE_pow=4;
class BIGNUM
{
    public:
    long long *N;
    int size;
};
BIGNUM dp[151];
bool dp_p[151];
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
    N.size=i;
}
void add(BIGNUM &N1,BIGNUM &N2)
{
    for(int i=0;i<N1.size;i++)
    {
        N2.N[i]+= N1.N[i] ;
    }
}
BIGNUM multiply_nor(BIGNUM N1,BIGNUM N2)
{
    BIGNUM N3;
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
    docarry(N3);
    return N3;
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
void getans(int n)
{
//    cout<<"getans "<<n<<endl;
    BIGNUM ans;
    ans.N=new long long[50];
    for(int i=0;i<50;i++)
    ans.N[i]=0;
    for(int i=2;i<=2*n;i+=2)
    {
//        cout<<(i-2)/2<<" "<<(2*n-i)/2<<endl;
        BIGNUM x=multiply_nor(dp[(i-2)/2],dp[(2*n-i)/2]);
        add(x,ans);
    }
    ans.size=50;
    docarry(ans);
    dp[n]=ans;
}//    cout<<"getans "<<n<<endl;

int main()
{
    BIGNUM x;
    x.size=1;
    x.N=new long long(1);

    dp[0]=dp[1]=x;
    for(int i=2;i<=150;i++)
    {
        getans(i);
    }
    int n;
    while(cin>>n)
    {
        if(n==-1)
        return 0;
        show(dp[n]);
    }
    return 0;
}

