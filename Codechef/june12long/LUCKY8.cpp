/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
int lenX(long long a)
{
    int count=0;
    do
    {
        count++;
        a/=10;
    }while(a--);
    return count;
}
int get_ans_all_dig(int dig,int f,int s)
{
    while(dig--)
    {
        if(f>s)s++;
        else f++;
    }
    return s*f;
}
long long ten_n(int n)
{
    long long x=1;
    while(n--)
    x*=10;
    return x;
}
//when range magnitude is one
int get_len_ans(int len_x,long long a,long long b,int f,int s)
{
    if(len_x==1)
    {
        if(a<=4 && b>=7)
        {
            return get_ans_all_dig(1,f,s);
        }else if((a>4 && b<7) || (a<4 && b<4) || (a>7 && b>7))
        return f*s;
        else if(a<=4 && b>=4)return (f+1)*s;
        else return f*(s+1);
    }
    int ans=0,x,common;
    long long tmp=ten_n(len_x-1);

    if(b==ten_n(len_x)-1 && a==0)
    return get_ans_all_dig(len_x,f,s);

//    printf("len_x=%d a=%lld b=%lld f=%lld s=%lld\n",len_x,a,b,f,s);
    long long a_m=a%tmp;long long b_m=b%tmp;


    long long a_d=a/tmp,b_d=b/tmp;

    if(a_d==b_d)
    {
        if(a_d==4)x=get_len_ans(len_x-1,a_m,b_m,f+1,s);
        else if(a_d==7)x=get_len_ans(len_x-1,a_m,b_m,f,s+1);
        else x=get_len_ans(len_x-1,a_m,b_m,f,s);
        return x;
    }
    if(a_d==4)x=get_len_ans(len_x-1,a_m,tmp-1,f+1,s);
    else if(a_d==7)x=get_len_ans(len_x-1,a_m,tmp-1,f,s+1);
    else x=get_len_ans(len_x-1,a_m,tmp-1,f,s);
    ans=MAX(ans,x);

    a_d++;

//    printf("len_x=%d a=%lld b=%lld f=%lld s=%lld ans=%d\n",len_x,a,b,f,s,ans);

    if(a_d!=b_d){
    common=get_len_ans(len_x-1,0,tmp-1,f,s);
    ans=MAX(ans,common);}

    while(a_d!=b_d)
    {
        x=0;
        if(a_d==4)x=get_len_ans(len_x-1,0,tmp-1,f+1,s);
        else if(a_d==7)x=get_len_ans(len_x-1,0,tmp-1,f,s+1);

        ans=MAX(ans,x);
        a_d++;
    }

        if(a_d==4)x=get_len_ans(len_x-1,0,b_m,f+1,s);
        else if(a_d==7)x=get_len_ans(len_x-1,0,b_m,f,s+1);
        else x=get_len_ans(len_x-1,0,b_m,f,s);
        ans=MAX(ans,x);


    return ans;
}
int main()
{
    long long a,b,n;
    in_T
    {
    in_L(a);
    in_L(b);
    int lenss=lenX(b);
    printf("%d\n",get_len_ans(lenss,a,b,0,0));
    }
    //printf("%d\n",getans(a,b,0,0));
}

