/*
ID: nimeshg1
PROG: clocks
LANG: C++
*/
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
#include<utility>
#include<fstream>
#include<set>
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

ifstream fin("clocks.in");
ofstream fout("clocks.out");
//#define fin cin
//#define fout cout
int moves[9] = {
1|(1<<3)|(1<<9)|(1<<12),
1|(1<<3)|(1<<6),
(1<<3)|(1<<6)|(1<<12)|(1<<15),
1|(1<<9)|(1<<18),
(1<<3)|(1<<9)|(1<<12)|(1<<15)|(1<<21),
(1<<6)|(1<<15)|(1<<24),
(1<<9)|(1<<12)|(1<<18)|(1<<21),
(1<<18)|(1<<21)|(1<<24),
(1<<12)|(1<<15)|(1<<21)|(1<<24),
};
int foo = 0;
struct state
{
    int mask;
    vector<int> sol;
}tmp, tmp2;
int visited[1<<18] = {0};
int conv(int x)
{
    int ret = 0;
    bool bit;
    for(int i=0;i<9;i++)
    {
        bit = x & (1<<(i*3));
        ret |= (bit<<(i*2));
        bit = x & (1<<(i*3+1));
        ret |= (bit<<(i*2+1));
    }
    return ret;
}
int main()
{
    for(int i = 1;i<=9;i++)
        foo = foo|(1<<(i*3 - 1));
    foo = ~foo;
    int start = 0, x;
    for(int i=0;i<9;i++)
    {
        fin>>x;
        x = (1 + x/4)%4;
        start = start | (x<<(3*i));
    }
    queue<state> BFS;
    tmp.mask = start;
    BFS.push(tmp);
//    cout<<conv(start)<<endl;
    visited[conv(start)] = 1;
    while(!BFS.empty())
    {
        tmp = BFS.front();
        BFS.pop();
        if(tmp.mask==0)
        {
            for(int i=0;i<tmp.sol.size();i++)
                fout<<tmp.sol[i]+1<<((i==tmp.sol.size()-1)?"":" ");
            fout<<endl;
            break;
        }
        for(int i=0;i<9;i++)
        {
            tmp2.mask = (tmp.mask + moves[i])&foo;
            if(!visited[conv(tmp2.mask)])
            {
                visited[conv(tmp2.mask)] = 1;
                tmp2.sol = tmp.sol;
                tmp2.sol.push_back(i);
                BFS.push(tmp2);
            }
        }
    }
}
