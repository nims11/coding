/*
    Nimesh Ghelani (nims11)
    Form a Decision Tree for possible initial cases
    Reduce the Decision trees into series.
    The calc() is a Decision Tree, though I have not used it anywhere due to inefficiency.
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
int r[5],s[5];
double raj, shel, draw;
double res;
#define MAX_DEPTH 400
void calc(double curr, int depth, int cnt_raj, int cnt_shel)
{
    if(depth>MAX_DEPTH)return;
//    cout<<cnt_raj<<" "<<cnt_shel<<" "<<depth<<" "<<curr<<endl;
    if(cnt_raj == 2)
    {
        res += curr;
        return;
    }
    if(cnt_shel == 2)
    {
        return;
    }
    //raj
    calc(curr*raj, depth+1, cnt_raj+1, cnt_shel);

    //shel
    calc(curr*shel, depth+1, cnt_raj, cnt_shel+1);

    //draw
    calc(curr*draw, depth+1, cnt_raj, cnt_shel);
}
int main()
{
    in_T
    {
        for(int i=0;i<5;i++)
            in_I(r[i]);
        for(int i=0;i<5;i++)
            in_I(s[i]);
        raj = r[0]*(s[1]+s[3]) + r[1]*(s[2]+s[3]) + r[2]*(s[0]+s[4]) + r[3]*(s[2]+s[4]) + r[4]*(s[0]+s[1]);
        shel = s[0]*(r[1]+r[3]) + s[1]*(r[2]+r[3]) + s[2]*(r[0]+r[4]) + s[3]*(r[2]+r[4]) + s[4]*(r[0]+r[1]);
        draw = 0;
        for(int i=0;i<5;i++)draw += s[i]*r[i];
        raj/=10000;
        shel/=10000;
        draw/=10000;
        if(raj == 0)
        {
            printf("0\n");
            continue;
        }
//        cout<<raj<<" "<<shel<<" "<<draw<<endl;
        res = 0;
        double X = raj*raj*(1+shel*(1+draw/(1-draw)))/(1-draw);
        double Y = raj*raj*shel/(1-draw)/(1-draw);
        res = (X+Y)/(1-draw);
//        calc(1,0,0,0);
//        cout<<res<<endl;
        printf("%.0lf\n", res*100);
    }
}
