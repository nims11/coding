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
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define BE(a) a.begin(), a.end()

using namespace std;
int trie[2000000][26];
int subSize[2000000][26];
int cnt;
int addTrie(string &str){
    int cur = 1;
    bool flag = false;
    int ret = 0;
    for(int i = 0;i<str.size();i++){
        int b = str[i]-'a';
        int tot = 0;
        if(trie[cur][b] == 0){
            subSize[cur][b] = 0;
            trie[cur][b] = ++cnt;
            if(cnt >= 2000000)
                cerr<<"ERROR!!"<<endl;
            if(!flag)
                ret++, flag = true;
        }else{
            ret++;
        }
        subSize[cur][b]++;
        cur = trie[cur][b];
    }
    return ret;
}
int main()
{
    int z = 0;
    in_T{
        z++;
        cnt = 1;
        for(int k = 0;k<2000000;k++)
        for(int i = 0;i<26;i++)
            trie[k][i] = subSize[k][i] = 0;
        cout<<"Case #"<<z<<": ";
        int n;
        cin>>n;
        long long ans = 0;
        string str;
        for(int i = 0 ;i<n;i++){
            cin>>str;
            int tm = addTrie(str);
            ans += tm;
        }
        cout<<ans<<endl;
    }
}
