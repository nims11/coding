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
// 0 -> ? 1 -> H, -1 = -> nonH
int statH[300];
string passes[300];
int cntH = 0, cntNH = 0;
int max_score = 0, cur_score;
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
struct node
{
    int times, rise, idx, times_dec, dec;
    int approx;
    friend bool operator<(const node &a, const node &b)
    {
        return (a.dec+a.rise)>(b.dec+b.rise);
//        if(a.times_dec*(b.times-b.times_dec) == b.times_dec*(a.times-a.times_dec))
//            return a.rise>b.rise;
//        return a.times_dec*(b.times-b.times_dec)>b.times_dec*(a.times-a.times_dec);
//        if(a.times_dec!=b.times_dec)
//            return a.times_dec>b.times_dec;
//        if(a.times!=b.times)
//            return a.times>b.times;
//        return a.rise>b.rise;
    }
}tmp_node[300];
priority_queue<node> bar;
void do_IO()
{
    T--;
    for(int i=0;i<N;i++)
        printf("%s\n", passes[i].c_str());
    fflush(stdout);
    in_I(cur_score);
    if(T == 0)
        exit(0);
}
int get_deg(double N, int H)
{
    double prob = 1;
    int ret = 1;
    for(int x=2;x<=H;x++)
    {
        prob = 1;
        for(int y=1;y<=x;y++)
            prob *= (H-x+y)/(N-x+y);
        if(prob>0.8)
            ret = x;
    }
    return ret;
}
void gen_NH_by_2()
{
    set<int> curr;
    int curr1, curr2;
    string tmp[300], tmp1, tmp2;
    while(cntH<H)
    {
        int deg = get_deg(N-cntH, H-cntH);
        if(deg < 3)
            return;
        curr.clear();
        for(int i=0;i<deg;i++)
        {
            do
            {
                curr1 = randxy(0, N-1);
            }while(statH[curr1] != 0 && curr.find(curr1) != curr.end());
            curr.insert(curr1);
            tmp[curr1] = passes[curr1];
            passes[curr1] = randStr();
        }
        do_IO();
        if(cur_score == max_score)
        {
            for(set<int>::iterator it = curr.begin(); it!=curr.end(); it++)
                statH[*it] = 1;
            cntH+=curr.size();
        }else
        {
            if(cur_score>max_score)
            {
                max_score = cur_score;
            }else
            {
                for(set<int>::iterator it = curr.begin(); it!=curr.end(); it++)
                    passes[*it] = tmp[*it];
            }
        }
    }
}
void gen_NH()
{
    int curr = 0;
    string tmp;
    while(curr<N)
    {
        if(statH[curr]!=0)
        {
            curr++;
            continue;
        }
        tmp = passes[curr];
        passes[curr] = randStr();
        do_IO();
        if(cur_score == max_score)
        {
            statH[curr] = 1;
            cntH++;
        }else
        {
            cntNH++;
            statH[curr] = -1;
            tmp_node[curr].times++;
            if(cur_score>max_score)
            {
                tmp_node[curr].rise += sqrt(cur_score-max_score);
                max_score = cur_score;
            }else
            {
                tmp_node[curr].times_dec++;
                int dec = sqrt(max_score-cur_score);
                if(dec>tmp_node[curr].rise)
                    tmp_node[curr].dec += dec-tmp_node[curr].rise;
                passes[curr] = tmp;
            }
        }
        curr++;
    }
//    if(cntNH == N-H)
//    for(int i=0;i<N;i++)
//        if(statH[i] == 0)
//        statH[i] = 1;
//
//    if(cntH == H)
//    for(int i=0;i<N;i++)
//        if(statH[i] == 0)
//        statH[i] = -1;
}

void do_residual_1()
{
    for(int i=0;i<N;i++)
        if(statH[i] == -1)
            bar.push(tmp_node[i]);
    while(1)
    {
        node currnode1 = bar.top();
        bar.pop();
        node currnode2 = bar.top();
        bar.pop();
        int curr1 = currnode1.idx;
        int curr2 = currnode2.idx;
        string tmp1 = passes[curr1];
        string tmp2 = passes[curr2];
        passes[curr1] = randStr();
        tmp_node[curr1].times++;
        passes[curr2] = randStr();
        tmp_node[curr2].times++;

        do_IO();

        if(cur_score>max_score)
        {
            tmp_node[curr2].rise += sqrt((cur_score-max_score)/2), tmp_node[curr1].rise += sqrt((cur_score-max_score)/2);
            max_score = cur_score;
        }
        else
            passes[curr2] = tmp2, passes[curr1] = tmp1, tmp_node[curr2].times_dec++, tmp_node[curr2].dec -= sqrt((cur_score-max_score)/2), tmp_node[curr1].times_dec++, tmp_node[curr1].dec -= sqrt((cur_score-max_score)/2);

        bar.push(tmp_node[curr2]);
        bar.push(tmp_node[curr1]);
    }
}

void do_residual_0()
{
    for(int i=0;i<N;i++)
    if(statH[i] == -1)
        bar.push(tmp_node[i]);

    int curr2 = N-1;
    while(T!=0)
    {
        node curr2node = bar.top();
        curr2 = curr2node.idx;
        bar.pop();

        string tmp = passes[curr2];
        passes[curr2] = randStr();
        tmp_node[curr2].times++;

        do_IO();

        if(cur_score>max_score)
        {
            tmp_node[curr2].rise += sqrt(cur_score-max_score);
            max_score = cur_score;
        }
        else
        {
            passes[curr2] = tmp, tmp_node[curr2].times_dec++;
            int dec = sqrt(max_score-cur_score);
            if(dec>tmp_node[curr2].rise)
                tmp_node[curr2].dec += dec-tmp_node[curr2].rise;
        }

        bar.push(tmp_node[curr2]);
    }
}
int main()
{
    cin>>T>>N>>H;

    for(int i=0;i<N;i++)
    {
        passes[i] = randStr();
        tmp_node[i].idx = i;
        tmp_node[i].rise = 0;
        tmp_node[i].times = 0;
        tmp_node[i].times_dec = 0;
        tmp_node[i].dec = 0;
    }
    for(int i=0;i<N;i++)
    {
        statH[i] = 0;
    }
    do_IO();
    srand(cur_score);
    max_score = cur_score;
//    gen_NH_by_2();
    gen_NH();
    do_residual_0();
//    do_residual(1);
}
