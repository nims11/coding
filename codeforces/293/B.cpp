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
    string s, t;
    cin>>s>>t;
    int smap[256]={0};
    for(int i = 0;i<t.size();i++)
        smap[t[i]]++;
    int x = 0, y = 0;
    string left = "";
    for(int j = 0;j<s.size();j++){
        char c = s[j];
        if(smap[c]){
            smap[c]--;
            x++;
        }else
            left.push_back(c);
    }
    for(int i = 0;i<left.size();i++){
        char c = left[i];
        if(isupper(c) && smap[tolower(c)]){
            y++;
            smap[tolower(c)]--;
        }else if(islower(c) && smap[toupper(c)]){
            y++;
            smap[toupper(c)]--;
        }
    }
    cout<<x<<" "<<y<<endl;
}
