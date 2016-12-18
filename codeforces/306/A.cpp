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
    string str;
    cin>>str;
    int f_l = -1, l_l, f_r=-1, l_r;
    for(int i = 1;i<str.length();i++){
        if(str[i] == 'B' && str[i-1] == 'A'){
            if(f_l == -1)
                f_l = i-1;
            l_l = i-1;
        }
        if(str[i] == 'A' && str[i-1] == 'B'){
            if(f_r == -1)
                f_r = i-1;
            l_r = i-1;
        }
    }
    if((abs(l_l-l_r) >= 2 || abs(l_l - f_r) >= 2 || abs(f_l - l_r) >= 2 || abs(f_l - f_r) >= 2) && f_l != -1 && f_r != -1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
