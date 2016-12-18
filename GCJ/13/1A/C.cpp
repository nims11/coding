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
#include<set>
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
    int c = 0;
    in_T
    {
        c++;
        cout<<"Case #"<<c<<":"<<endl;
        int r,n,m,k;
        cin>>r>>n>>m>>k;
        while(r--)
        {
            int res[8] = {0};
            int cnt = 0;
            int arr[k][2];
            for(int i=0;i<k;i++)
            {
                arr[i][1] = 0;
                in_I(arr[i][0]);
            }
            for(int X = 3;X<=7;X+=2)
            for(int i=0;i<k;i++)
            {
                int foo = 0;
                while(arr[i][0]%X == 0)
                {
                    foo++;
                    arr[i][0] /= X;
                }
                if(foo>res[X])
                {
                    cnt += foo-res[X];
                    res[X] = foo;
                }
            }
            for(int i=0;i<k;i++)
            {
                int foo = 0;
                if(arr[i][0]%2 == 0 && arr[i][0]%4 != 0)
                {
                    foo = 1;
                    arr[i][0] /= 2;
                }
                if(foo>res[2])
                {
                    cnt += foo-res[2];
                    res[2] = foo;
                }
            }
            for(int i=0;i<k;i++)
            {
                if(arr[i][0]%4 == 0)
                {
                    if(cnt == n-1)
                    {
                        if(arr[i][0]%8 == 0)
                        {
                            res[4]++;
                            cnt++;
                        }else if(res[2])
                        {
                            res[2]++;
                            cnt++;
                        }else
                        {
                            res[4]++;
                            cnt++;
                        }
                    }
                }
            }
            int i = 2;

            while(cnt>n)
            {
                res[6]++;
                res[2]--;
                res[3]--;
                cnt--;
            }
            int rem = n-cnt;
            while(i<6 && cnt)
            {
                while(res[i])
                {
                    cout<<i;
                    cnt--;
                    res[i]--;
                }
                i++;
            }
            while(rem--)
            {
                cout<<4;
            }
            cout<<endl;
        }
    }
}
