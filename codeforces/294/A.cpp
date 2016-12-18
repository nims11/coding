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
    int b = 0, w = 0;
    int score[200] = {0};
    score['q'] = 9;
    score['r'] = 5;
    score['b'] = 3;
    score['n'] = 3;
    score['p'] = 1;
    while(cin>>str){
        for(int i = 0;i<str.size();i++){
            char c = str[i];
            if(isalpha(c) && score[tolower(c)]){
                if(isupper(c))
                    b += score[tolower(c)];
                else
                    w += score[c];
            }
        }
    }
    if(b > w)
        cout<<"White"<<endl;
    else if(b < w)
        cout<<"Black"<<endl;
    else
        cout<<"Draw"<<endl;
}
