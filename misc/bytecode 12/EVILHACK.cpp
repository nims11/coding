    /*
        Nimesh Ghelani (nims11)
    */
    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    #include<map>
    #include<string>
    #include<vector>
    #define in_T int t;for(scanf("%d",&t);t--;)
    #define in_I(a) scanf("%d",&a)
    #define in_F(a) scanf("%lf",&a)
    #define in_L(a) scanf("%lld",&a)
    #define in_S(a) scanf("%s",&a)
    #define newline printf("\n")
    #define MAX(a,b) a>b?a:b
    #define MIN(a,b) a<b?a:b
    #define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
    #define P_I(a) printf("%d",a)

    using namespace std;
    int x,y;
    int main()
    {
        in_T
        {
            in_I(x);in_I(y);
            if(x==0 || y==0)printf("0\n");
            else
            printf("%d\n",1+x/2+y/2);
        }
    }
