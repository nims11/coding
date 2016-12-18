/*
    Nimesh Ghelani (nims11)
*/
#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
int main()
{
    int n;
    cin>>n;
    int res = 0;
    string str;
    cin>>str;
    int cur[26] = {0};
    for(int i = 0;i<str.length()-1;i+=2){
        cur[str[i]-'a']++;
        int c = str[i+1]-'A';
        if(cur[c])cur[c]--;
        else
            res++;
    }
    cout<<res<<endl;
}
