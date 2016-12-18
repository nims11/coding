/*
ID: nimeshg1
PROG: packrec
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
struct sol
{
    int p,q;
    int area;
    friend bool operator<(const sol &a, const sol &b)
    {
        if(a.area!=b.area)return a.area<b.area;
        return a.p<b.p;
    }
    friend bool operator==(const sol &a, const sol &b)
    {
        return a.p==b.p && a.q==b.q;
    }
}tmp;
#define length(a) rects[perm[a]][order[i][perm[a]]]
#define breadth(a) rects[perm[a]][!order[i][perm[a]]]
#define DOSTUFFS if(x>y){tmp.p = y, tmp.q = x;}else{tmp.p = x, tmp.q = y;}tmp.area = x*y;answers.push_back(tmp);
ifstream fin("packrec.in");
ofstream fout("packrec.out");
//#define fin cin
//#define fout cout
int main()
{
    int perm[4] = {0,1,2,3};
    vector<sol> answers;
    int rects[4][2];
    for(int i=0;i<4;i++)
        for(int j=0;j<2;j++)
            fin>>rects[i][j];
    int order[16][4];
    for(int i=0;i<16;i++)
        for(int j=0;j<4;j++)
            order[i][j] = (i&(1<<j))?1:0;
    do
    {
        for(int i=0;i<16;i++)
        {
            int x, y;

            //CASE 1
            x = y = 0;
            for(int j=0;j<4;j++)
            x = max(x, length(j)), y += breadth(j);
            DOSTUFFS

            //CASE 2
            x = y = 0;
            for(int j=0;j<3;j++)
            x = max(x, length(j)), y += breadth(j);
            x += length(3);
            y = max(y, breadth(3));
            DOSTUFFS


            //CASE 3
            x = max(length(2), max(length(0), length(1)) + length(3));
            y = breadth(2) + max(breadth(3), breadth(0) + breadth(1));


            DOSTUFFS
            //CASE 4
            x = max(length(0), max(length(3), length(1) + length(2)));
            y = breadth(0) + breadth(3) + max(breadth(1), breadth(2));
            DOSTUFFS

            //CASE 5
            x = max(length(3), max(length(2), length(1) + length(0)));
            y = breadth(2) + breadth(3) + max(breadth(1), breadth(0));
            DOSTUFFS

            //CASE 6
            x = max(length(0)+length(1), length(2) + length(3));
            y = breadth(1) + breadth(2);
            if(length(1)<length(2))
            {
                y = max(breadth(1), breadth(0)) + breadth(2);
            }
            if(length(1)+length(0)>length(2))
                y = max(y, breadth(0) + breadth(3));
            if(length(1)>length(2))
                y = max(y, breadth(1) + breadth(3));
            y = max(y, max(breadth(1), breadth(3)));

            DOSTUFFS
        }
    }while(next_permutation(perm,perm+4));
    sort(answers.begin(), answers.end());
    sol pre = answers[0];
    fout<<answers[0].area<<endl;
    int idx = 0;
    while(answers[idx].area == answers[0].area)
    {
        fout<<pre.p<<" "<<pre.q<<endl;
        while(answers[idx] == pre)
            idx++;
        pre = answers[idx];
    }
}
