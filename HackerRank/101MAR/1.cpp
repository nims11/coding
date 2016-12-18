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
    in_T{
        string str;
        cin>>str;
        int res = 0;
        int foo[26] = {0};
        int runCnt[26] = {0};
        int idx = 0;
        int cur = 0;
        while(idx < str.size()){
            cur = 1;
            idx++;
            while(idx < str.size() && str[idx] == str[idx-1])
                idx++, cur++;
            idx--;
            foo[str[idx]-'A'] = max(foo[str[idx]-'A'], cur);
            runCnt[str[idx]-'A']++;
            res++;
            idx++;
        }
        int ans = res;
        for(int i = 0;i<str.size();i++){
            int cur = res;
            if(runCnt[str[i] - 'A'] > 1 && ((i == 0 || str[i] != str[i-1]) && (i == str.size()-1 || str[i] != str[i+1])))
                cur--;
            if(i > 0 && i < str.size()-1 && str[i-1] == str[i+1] && str[i-1] != str[i])
                cur--;
            ans = min(ans, cur);
        }
        printf("%d\n", ans);
    }
}
