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
#include<cstring>
#include<cstdlib>
#include<cassert>
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
    in_T{
        string str;
        cin>>str;
        int left = (str.length()-1)/2, right = (str.length())/2;
            right++;
        int err = 0;
        while(left >=0 && right <str.length() && err < 2){
            if(str[left] == str[right])left--, right++;
            else
                left--, err++;
        }
        while(left >=0 || right <str.length())
            err++, left--, right++;
        if(err > 1){
            left = (str.length()-1)/2, right = (str.length())/2;
            left--;
            err = 0;
            while(left >=0 && right <str.length() && err < 2){
                if(str[left] == str[right])left--, right++;
                else
                    right++, err++;
            }
            while(left >=0 || right <str.length())
                err++, left--, right++;
        }
        if(err < 2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
