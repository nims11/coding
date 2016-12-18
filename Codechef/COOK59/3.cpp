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
bool isRegular(string &str){
    int cur = 0;
    for(int i = 0;i<str.length();i++){
        if(str[i] == '(')
            cur++;
        else cur--;
        if(cur < 0)return false;
    }
    return (cur == 0);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int k;
        cin>>k;
        if(isRegular(str)){
            int curidx = -1;
            int streak = 0;
            int curK = 0;
            for(int i = 0;i<str.size();i++){
                if(str[i] == ')'){
                    if(streak == 0){
                        streak = 1;
                        curK++;
                        if(curK == k)
                            curidx = i;
                    }
                }else
                    streak = 0;
            }
            streak = 0;
            for(int i = str.size()-1;i>=0;i--){
                if(str[i] == '('){
                    if(streak == 0){
                        streak = 1;
                        curK++;
                        if(curK == k)
                            curidx = i;
                    }
                }else
                    streak = 0;
            }
            if(curidx == -1)
                cout<<-1<<endl;
            else{
                string newstr;
                for(int i = 0;i<str.length();i++){
                    if(i != curidx)
                        newstr.push_back(str[i]);
                }
                cout<<newstr<<endl;
            }
        }else{
            if(k == 1)
                cout<<str<<endl;
            else
                cout<<-1<<endl;
        }
    }
}
