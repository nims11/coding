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
string str[4];
bool win(char ch)
{
    for(int i=0;i<4;i++)
    {
        int T = 0, C = 0;
        for(int j=0;j<4;j++)
            T += (str[i][j] == 'T'), C += (str[i][j] == ch);
        if(C == 4 || (C == 3 && T == 1))
        return true;
    }
    for(int i=0;i<4;i++)
    {
        int T = 0, C = 0;
        for(int j=0;j<4;j++)
            T += (str[j][i] == 'T'), C += (str[j][i] == ch);
        if(C == 4 || (C == 3 && T == 1))
        return true;
    }
    {
        int T = 0, C = 0;
        for(int j=0;j<4;j++)
            T += (str[j][j] == 'T'), C += (str[j][j] == ch);
        if(C == 4 || (C == 3 && T == 1))
        return true;
    }
    {
        int T = 0, C = 0;
        for(int j=0;j<4;j++)
            T += (str[j][3-j] == 'T'), C += (str[j][3-j] == ch);
        if(C == 4 || (C == 3 && T == 1))
        return true;
    }

    return false;
}
bool incop()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        if(str[i][j] == '.')return true;
    return false;
}
int main()
{
    int c = 0;
    in_T
    {
        c++;
        cout<<"Case #"<<c<<": ";
//        cout<<endl;
        for(int i=0;i<4;i++)
        {
            cin>>str[i];
//            cout<<str[i]<<endl;
        }
        if(win('X'))
            cout<<"X won"<<endl;
        else if(win('O'))
            cout<<"O won"<<endl;
        else if(incop())
            cout<<"Game has not completed"<<endl;
        else
            cout<<"Draw"<<endl;
    }
}
