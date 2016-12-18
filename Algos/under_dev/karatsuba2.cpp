#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define BASE 10
#define BASE_pow 1
int int_len(int x)
{
    if(x==0)
    return 1;
    int count=0;
    while(x!=0)
    {
        x/=10;
        count++;
    }
    return count;
}
void  show(int *a,int len)
{
    int i;
    for(i=len-1;a[i]<=0 && i>0;i--);
    int start=i;
    for(;i>=0;i--)
    {
        int len=int_len(a[i]);
        for(int j=0;j<BASE_pow-len && i!=start;j++)
        printf("0");
        printf("%d",a[i]);
    }
    printf("\n");
}
void multiply(int *a,int *b,int *res,int len)
{
    for(int i=0;i<2*len;i++)res[i]=0;
    for(int i=0;i<len;i++)
    for(int j=0;j<len;j++)
    res[i+j]+=a[i]*b[j];
}
//void karatsuba(int *a, int *b, int *res, int len)
//{
//    int *ar=&a[0];
//    int *al=&a[len/2];
//    int *br=&b[0];
//    int *bl=&b[len/2];
//    int *asum=&res[len*5];
//    int *bsum=&res[len*5+len/2];
//    int *ar_br=&res[0];
//    int *al_bl=&res[len];
//    int *asum_bsum=&res[2*len];
//
//    if(len<=4)
//    {
//        multiply(a,b,res,len);
//        return;
//    }
//
//    for(int i=0;i<len/2;i++)
//    {
//        asum[i]=al[i]+ar[i];
//        bsum[i]=bl[i]+br[i];
//    }
//    karatsuba(ar, br, ar_br, len/2);
//    karatsuba(al, bl, al_bl, len/2);
//    karatsuba(asum, bsum, asum_bsum, len/2);
//
//    for(int i=0;i<len;i++)
//    asum_bsum[i]=asum_bsum[i]-ar_br[i]-al_bl[i];
//    for(int i=0;i<len;i++)
//    res[i+len/2]+=asum_bsum[i];
//}
void
karatsuba(int *a, int *b, int *ret, int d) {
    int             i;
    int             *ar = &a[0]; // low-order half of a
    int             *al = &a[d/2]; // high-order half of a
    int             *br = &b[0]; // low-order half of b
    int             *bl = &b[d/2]; // high-order half of b
    int             *asum = &ret[d * 5]; // sum of a's halves
    int             *bsum = &ret[d * 5 + d/2]; // sum of b's halves
    int             *x1 = &ret[d * 0]; // ar*br's location
    int             *x2 = &ret[d * 1]; // al*bl's location
    int             *x3 = &ret[d * 2]; // asum*bsum's location

    // when d is small, we're better off just reverting to
    // grade-school multiplication, since it's faster at this point.
    if(d <= 4) {
        multiply(a, b, ret, d);
        return;
    }

    // compute asum and bsum
    for(i = 0; i < d / 2; i++) {
        asum[i] = al[i] + ar[i];
        bsum[i] = bl[i] + br[i];
    }

    // do recursive calls (I have to be careful about the order,
    // since the scratch space for the recursion on x1 includes
    // the space used for x2 and x3)
    karatsuba(ar, br, x1, d/2);
    karatsuba(al, bl, x2, d/2);
    karatsuba(asum, bsum, x3, d/2);

    // combine recursive steps
    for(i = 0; i < d; i++) x3[i] = x3[i] - x1[i] - x2[i];
    for(i = 0; i < d; i++) ret[i + d/2] += x3[i];
}

void doCarry(int *a,int len)
{
    int c=0;
    int i;
    for(i=0;i<len;i++)
    {
        a[i]+=c;

        if(a[i]<0)
        c = -(-(a[i]+1)/10+1);
        else
        c = a[i]/10;

        a[i] -= c * 10;
    }
    if(c != 0) fprintf(stderr, "Overflow %d\n", c);
}
int main()
{
    int a[10000],b[10000],res[60000],len_a,len_b,len,i;
    int t=1;
    //cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        len_a=s1.size();
        len_b=s2.size();
        len=len_a>len_b?len_a:len_b;
        len+=len%2;
        int i;
        for(i=0;i<len_a;i++)
        a[i]=s1[len_a-1-i]-'0';
        while(i<len)
        a[i++]=0;

        for(i=0;i<len_b;i++)
        b[i]=s2[len_b-1-i]-'0';
        while(i<len)
        b[i++]=0;
//        show(a,len_a);show(b,len_b);
        karatsuba(a,b,res,len);
        doCarry(res, 2 * len);
        show(res,2*len);
    }
    return 0;
}
