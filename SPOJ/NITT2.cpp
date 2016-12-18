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
#include<cstring>
#include<utility>
#define in_T int t;for(scanf("%d\n",&t);t--;)
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
void getInput(BIGNUM &N1)
{
    char tmp[51000];
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
bool getans(BIGNUM &N1, int n)
{
    int d;
    int rem = 0;
//    BIGNUM quo;
//    vector<long long> quot;
    int i=N1.size-1;
    for(;i>=0;i--)
    {
//        N1.N[i]+=rem;
//        quot.push_back(N1.N[i]/n);
//        cout<<N1.N[i]<<" "<<quot[quot.size()-1]<<endl;
        rem = (N1.N[i]+rem)%n;
        rem*=BASE;
    }
//    quo.N = new long long[quot.size()+1];
//    quo.size = quot.size()+1;
//    for(int i=0;i<quo.size;i++)
//    {
//        quo.N[i] = quot[quot.size()-1-i];
//    }
//    quo.N[quo.size-1]=0;
//    if(rem!=0)
//        quo.N[0]++;
//    multiply_nor(quo);
//    show(quo);
    return rem==0;
}
int main()
{
    in_T
    {
        BIGNUM N1;
        getInput(N1);
        if(getans(N1, 252))
            printf("Yes ");
        else
            printf("No ");
        if(getans(N1, 525))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
