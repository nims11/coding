/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
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
int main()
{
    char str1[50],str2[50], op;
    while(scanf("%s %c %s",str1,&op,str2)!=EOF)
    {
        long long num1=0, num2=0, ans, rev=0;
        for(int i=0;str1[i];i+=2)
        {
            for(int j=0;j<str1[i]-'0';j++)
                num1 = num1*10 + str1[i+1] - '0';
        }
        for(int i=0;str2[i];i+=2)
        {
            for(int j=0;j<str2[i]-'0';j++)
                num2 = num2*10 + str2[i+1] - '0';
        }
//        cout<<num1<<op<<num2<<endl;
        switch(op)
        {
            case '+': ans = num1+num2;break;
            case '-': ans = num1-num2;break;
            case '/': ans = num1/num2;break;
            case '*': ans = num1*num2;break;
        }
//        while(ans)
//        {
//            rev = rev*10 + ans%10;
//            ans/=10;
//        }
        printf("%s %c %s = ",str1,op,str2);
        if(ans==0)printf("10\n");
        else
        {
            long long foo = 1;
            long long bar = ans/10;
            while(bar)
            {
                foo*=10;
                bar/=10;
            }
            while(foo)
            {
                int curr = (ans/foo)%10;
                int count=0;
                while(foo && (ans/foo)%10 == curr)
                {
                    count++;
                    foo/=10;
                    if(count == 9)
                    {
                        printf("%d%d",count,curr);
                        count=0;
                    }
                }
                if(count)
                printf("%d%d",count,curr);
            }
            newline;
        }
    }
}

