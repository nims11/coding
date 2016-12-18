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
    int carry = 0;
    for(int i = s.size()-1;i>=0;i--){
        if(s[i] == 'z')
            carry = 1, s[i] = 'a';
        else
            carry = 0, s[i]++;
        if(!carry)break;
    }
    if(s == t)
        cout<<"No such string"<<endl;
    else cout<<s<<endl;
}
