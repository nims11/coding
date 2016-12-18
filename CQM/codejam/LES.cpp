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
int L;
char str[110];
int rem[26];
bool getres(int idx, int tot, char nxt='A'){
//    cout<<idx<<" "<<tot<<" "<<nxt<<endl;
    if(idx == L)
    {
        return (tot==L);
    }
    if(tot>L)
        return false;
    if(idx == 0){
        str[0] = 'A';
        return getres(1, 1, 'B');
    }else{
        int f = -1;
        for(int i = 0;i<nxt-'A';i++)
            if(rem[i]){f=i;break;}
        if(f != -1){
            rem[f]--;
            str[idx] = f+'A';
            if(getres(idx+1, tot, nxt))
                return true;
            rem[f]++;
        }
        str[idx] = nxt;
        rem[nxt-'A'] = idx;
        return getres(idx+1, tot+idx+1, nxt+1);
    }
}
int main()
{
    in_T{
        in_I(L);
        for(int i = 0;i<26;i++)rem[i] = 0;
        if(getres(0, 0)){
            str[L] = 0;
            printf("%s\n", str);
        }else
            printf("\n");
    }
}
