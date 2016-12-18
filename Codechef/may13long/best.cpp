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
int T,N,H;
int randxy(int x, int y)
{
    return x + (rand()%(y-x+1));
}
string randStr()
{
    string ret="";
    int len = randxy(8, 12);
    for(int j=0;j<len;j++)
    {
        ret.push_back('a'+randxy(0, 25));
    }
    return ret;
}
// 0 -> ? 1 -> H, -1 = -> nonH
int statH[300];
    string passes[300], tmp;
int cntH = 0, cntNH = 0;
    int curr = 0;
    int max_score = 0, cur_score;
int foo[300];
int cntfoo = 0;
string temp[300];
int rise[300];
//priority_queue<pair<int, int> > bar;
void gen_NH()
{
    int curr = 0;
    while(T!=0 && curr<N && cntNH<N-H)
    {
        T--;
        tmp = passes[curr];
        passes[curr] = randStr();
        for(int i=0;i<N;i++)
            printf("%s\n", passes[i].c_str());
        fflush(stdout);
        in_I(cur_score);
        if(cur_score == max_score)
        {
            statH[curr] = 1;
            cntH++;
        }else
        {
            cntNH++;
            statH[curr] = -1;
            if(cur_score>max_score)
            {
                rise[curr] += cur_score-max_score;
                max_score = cur_score;
            }else
            {
                passes[curr] = tmp;
            }
        }
        curr++;
    }
}
#define algo1
void do_residual(int deg)
{
    int curr2 = 0;
    int foo[deg];
    int cntfoo = 0;
    while(T!=0)
    {
        T--;
        #ifndef algo1
        cntfoo = 0;
        while(cntfoo<deg)
        {
            int i = randxy(0, N-1);
            if(statH[i] != -1)
            {
                foo[cntfoo] = i;
                temp[cntfoo] = passes[i];
                passes[i] = randStr();
                cntfoo++;
            }
        }
        #endif
        #ifdef algo1
        while(statH[curr2] != -1)
        {
            curr2 = (curr2+1)%N;
        }
        tmp = passes[curr2];
        passes[curr2] = randStr();
        #endif
        for(int i=0;i<N;i++)
            printf("%s\n", passes[i].c_str());
        fflush(stdout);
        in_I(cur_score);
        if(cur_score>max_score)
        {
            rise[curr2] += cur_score-max_score;
            max_score = cur_score;
            if(rise[curr2]>5000)
                statH[curr2] = -1;
        }else
        {
            #ifndef algo1
            for(int i=0;i<cntfoo;i++)
            {
                passes[foo[i]] = temp[i]
            }
            #endif
            #ifdef algo1
            passes[curr2] = tmp;
            #endif // algo1
        }
        #ifdef algo1
        curr2 = (curr2+1)%N;
        #endif
    }
}
int main()
{
    cin>>T>>N>>H;
    for(int i=0;i<N;i++)
    {
        passes[i] = "nimeshghel";
    }
    for(int i=0;i<N;i++)
    {
        statH[i] = 0;
    }

    T--;
    for(int i=0;i<N;i++)
            printf("%s\n", passes[i].c_str());
        fflush(stdout);
        in_I(cur_score);
    max_score = cur_score;
    gen_NH();
    do_residual(1);
}
