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
int grid[21][21];
int r,c;
char str[500];
int foo[5] = {16,8,4,2,1};
int main()
{
    int cnta=0;
    char ans[500];
    in_T
    {
        int ans_cnt=0;
        cnta++;
        printf("%d ",cnta);
        in_I(r);in_I(c);
        cin>>str;
        int cnt=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                grid[i][j]=str[cnt++]-'0';
        int dir_R=0,dir_C=1;
        int I=0,J=0;
        int lt = 5*((r*c)/5);
        int curr=0;
//        cout<<str<<endl;
        int max_R=r-1,max_C=c-1,min_R=0,min_C=0;
        for(int i=0;i<lt;i++,I+=dir_R,J+=dir_C)
        {
            curr+=grid[I][J]*foo[i%5];
//            cout<<I<<" "<<J<<" "<<grid[I][J]<<" "<<curr<<endl;
            if(i%5==4)
            {
                if(curr==0)
                {
                    ans[ans_cnt++]=' ';
                }else
                    ans[ans_cnt++]='A'+curr-1;
                curr=0;
            }
            if(I==min_R && J==min_C && dir_R==-1 && i!=0)
            {
                dir_R=0;
                dir_C=1;
                min_C++;
            }else if(I==min_R && J==max_C && dir_C==1)
            {
                dir_R=1;
                dir_C=0;
                min_R++;
            }else if(I==max_R && J==max_C && dir_R==1)
            {
                dir_R=0;
                dir_C=-1;
                max_C--;
            }else if(I==max_R && J==min_C && dir_C==-1)
            {
                dir_R=-1;
                dir_C=0;
                max_R--;
            }
        }
        ans_cnt--;
//        while(ans[ans_cnt]==' ' && ans_cnt>=0)
//        ans_cnt--;
        ans[ans_cnt+1]=0;
        printf("%s\n",ans);
    }
}
