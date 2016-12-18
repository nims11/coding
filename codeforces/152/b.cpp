/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
const long long BASE=1000000;
const int BASE_pow=6;
class BIGNUM
{
    public:
    long long *N;
    int size;
    ~BIGNUM()
    {
        delete [] N;
    }
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
void multiply_nor(BIGNUM &N1, bool do_carry=true)
{
    int size1=N1.size;
    for(int i=0;i<size1;i++)
    {
        N1.N[i] = 210*N1.N[i];
    }
    if(do_carry)
    docarry(N1);
}

void getInput(BIGNUM &N1, int n)
{
    char tmp[n];
    tmp[0] = 1;
    for(int i=1;i<n;i++)
        tmp[i] = 0;
    int len=n;
    N1.size=(len-1)/BASE_pow + 1;
    N1.N=new long long[N1.size];
    for(int i=0;i<N1.size;i++)
    N1.N[i]=0;
    for(int i=0;i<len;i++)
    {
        N1.N[((len-1-i)/BASE_pow)]=N1.N[(len-1-i)/BASE_pow]*10+tmp[i];
    }
}
void getans(int n)
{
    BIGNUM N1;
    getInput(N1, n);
    int d;
    int rem = 0;
    BIGNUM quo;
    vector<long long> quot;
    int i=N1.size-1;
    for(;i>=0;i--)
    {
        N1.N[i]+=rem;
        quot.push_back(N1.N[i]/210);
//        cout<<N1.N[i]<<" "<<quot[quot.size()-1]<<endl;
        rem = N1.N[i]%210;
        rem*=BASE;
    }
    quo.N = new long long[quot.size()+1];
    quo.size = quot.size()+1;
    for(int i=0;i<quo.size;i++)
    {
        quo.N[i] = quot[quot.size()-1-i];
    }
    quo.N[quo.size-1]=0;
    if(rem!=0)
        quo.N[0]++;
    multiply_nor(quo);
    show(quo);
}
int main()
{
    int n;
    cin>>n;
    if(n<3)cout<<-1<<endl;
    else
    {
        getans(n);
    }
    return 0;
}

