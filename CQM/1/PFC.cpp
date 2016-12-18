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

char ciph[5][5];
char key[12], msg[102];
pair<int, int> locs[26];
void gen_ciph()
{
    int r = 0, c = 0;
    int foo[26] = {0};
    foo['J'-'A'] = 1;
    for(int i = 0; key[i]; i++)
    {
        if(key[i] == 'J')key[i] = 'I';
        if(!foo[key[i]-'A'])
        {
            locs[key[i]-'A'] = make_pair(r, c);
            ciph[r][c++] = key[i];
            foo[key[i]-'A'] = 1;
        }
        if(c == 5)
            r++, c = 0;
    }
    for(int i = 0; i<26; i++)
    {
        if(!foo[i])
        {
            locs[i] = make_pair(r, c);
            ciph[r][c++] = 'A' + i;
            if(c == 5)
                r++, c = 0;
        }
    }
}
void encode(char X1, char X2)
{
    pair<int, int> L1 = locs[X1-'A'], L2 = locs[X2-'A'];
    if(L1.first == L2.first)
    {
        printf("%c%c", ciph[L1.first][(L1.second+1)%5], ciph[L1.first][(L2.second+1)%5]);
    }else if(L1.second == L2.second)
    {
        printf("%c%c", ciph[(L1.first+1)%5][L1.second], ciph[(L2.first+1)%5][L2.second]);
    }else
    {
//        cout<<X1<<" "<<X2<<endl;
        printf("%c%c", ciph[L1.first][L2.second], ciph[L2.first][L1.second]);
    }
}
int main()
{
    while(in_S(key) != EOF)
    {
        in_S(msg);
        gen_ciph();
//        for(int i = 0; i<5; i++)
//        {
//            for(int j = 0; j<5; j++)
//                cout<<ciph[i][j];
//            newline;
//        }
        for(int i = 0; msg[i]; i++)
        {
            if(msg[i] == 'J')msg[i] = 'I';
        }
        for(int i = 0; msg[i]; i++)
        {
            char X1 = msg[i];
            char X2 = msg[i+1];
            if(X1 == X2)
            {
                encode(X1, 'X');
            }else if(X2 == 0)
            {
                encode(X1, 'X');
            }else
            {
                i++;
                encode(X1, X2);
            }
        }
        newline;
    }
}
