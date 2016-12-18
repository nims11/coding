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
char Survey(int x, int y) {
    printf("S %d %d\n", x, y);
    fflush(stdout);
    char res;
    scanf(" %c", &res);
    return res;
}

void Neutralize(int x, int y) {
    printf("N %d %d\n", x, y);
}
int dd[3] = {0, 1, -1};
int n,m,k;
int extra;
int neut = 0;
char x;
int grid[51][51];
int getrem()
{
    int ret = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        ret += (grid[i][j] == -1);
}
void s1(int x, int y)
{
    if(neut>=m)
        return;
//    int rem = getrem();
//    if(extra+(m-neut)>=rem)
//    {
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                int xx = i;
//                int yy = j;
//                if(xx>=0 && yy>=0 && grid[xx][yy] == -1)
//                {
//                    Neutralize(xx, yy);
//                    grid[xx][yy] = 1;
//                }
//            }
//        }
//        neut = m;
//        return;
//    }
    char res = Survey(x, y);
    if(res == 'M')
    {
        Neutralize(x, y);
        neut++;
        grid[x][y] = 1;
    }else
        grid[x][y] = 0;
    res = Survey(x, y);
    int r = res-'0';
    int adj = 0;
    neut+=r;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int xx = x+dd[i];
            int yy = y+dd[j];
            if(xx>=0 && yy>=0 && xx<n && yy<n && grid[xx][yy] == -1)
            {
                adj++;
            }
        }
    }
    if(extra-(adj-r)>=0 && res>=adj/2)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int xx = x+dd[i];
                int yy = y+dd[j];
                if(xx>=0 && yy>=0 && xx<n && yy<n && grid[xx][yy] == -1)
                {
                    Neutralize(xx, yy);
                    grid[xx][yy] = 1;
                }
            }
        }
        extra -= adj-r;
        return;
    }
    int remm = adj;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int xx = x+dd[i];
            int yy = y+dd[j];
            if(xx>=0 && yy>=0 && xx<n && yy<n && grid[xx][yy] == -1)
            {
                if(r == remm)
                {
                    r--;
                    Neutralize(xx, yy);
                    grid[xx][yy] = 1;
                }
                else if(r == 0)
                {
                    grid[xx][yy] = 0;
                }else
                {
                    res = Survey(xx, yy);
                    if(res == 'M')
                    {
                        r--;
                        Neutralize(xx, yy);
                        grid[xx][yy] = 1;
                    }else
                    {
                        int r = res - '0';
                        grid[xx][yy] = 0;
                        int adj = 0;
                        if(r == 0)
                        for(int i1 = 0;i1<3;i1++)
                            for(int j1 = 0;j1<3;j1++)
                            {
                                int xxx = xx+dd[i];
                                int yyy = yy+dd[j];
                                if(xxx>=0 && yyy>=0 && xxx<n && yyy<n)
                                    grid[xxx][yyy] = 0;
                            }
                    }
                }
                remm--;
            }
        }
    }
}
int main()
{
    in_I(n);in_I(m);in_I(k);
    extra = k-m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            grid[i][j] = -1;
    for(int i = 1;i<n && neut<m;i+=3)
    {
        for(int j=1;j<n && neut<m;j+=3)
        {
            s1(i, j);
            if(j == n-3 && neut<m)
            {
                //do for j  = n-1
                s1(i, n-1);
            }
        }
        if(i == n-3 && neut<m)
        {
            for(int j=1;j<n && neut<m;j+=3)
            {
                s1(n-1, j);
                if(j == n-3 && neut<m)
                {
                    //do for j  = n-1
                    s1(n-1, n-1);
                }
            }
        }
    }
    printf("Done\n");
}
