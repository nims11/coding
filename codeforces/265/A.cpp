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
    int n, p;
    cin>>n>>p;
    string str;
    cin>>str;
    for(int i = str.length()-1;i>=0;i--){
        for(char c = str[i]+1;c<'a'+p;c++){
            bool poss = true;
            for(int j = i-2;j<i;j++){
                if(j>=0 && j != i){
                    if(str[j] == c)
                        poss = false;
                }
            }
            if(poss){
                str[i] = c;
                for(int j = i+1;j<str.length();j++){
                    for(char k = 'a';k<'a'+p;k++){
                        bool poss = true;
                        for(int l = j-2;l<j;l++)
                            if(l>=0 && str[l] == k)
                                poss = false;
                        if(poss){
                            str[j] = k;
                            break;
                        }
                    }
                }
                cout<<str<<endl;
                return 0;
            }

        }
    }

    cout<<"NO"<<endl;
}
