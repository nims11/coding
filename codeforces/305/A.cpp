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
int t1[1000010][2], t2[1000010][2];
long long GCD(long long a,long long b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
void fillin(int h1, int x1, int y1, int t[][2], int m){
    t[h1][0] = 0;
    int curh = (x1*1LL*h1 + y1)%m;
    int prevh = h1;
    while(t[curh][1] == -1){
        if(t[curh][0] == -1)
            t[curh][0] = t[prevh][0] + 1;
        else if(t[prevh][1] == -1)
            t[curh][1] = t[prevh][0] + 1;
        else
            t[curh][1] = t[prevh][1] + 1;
        prevh = curh;
        curh = (x1*1LL*prevh+y1)%m;
    }
}
int main()
{
    int m, h1, a1, x1, y1, h2, a2, x2, y2;
    cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
    memset(t1, -1, sizeof(t1));
    memset(t2, -1, sizeof(t2));
    fillin(h1, x1, y1, t1, m);
    fillin(h2, x2, y2, t2, m);
    if(t1[a1][0] == -1 || t2[a2][0] == -1)
        cout<<-1<<endl;
    else if(t1[a1][0] == t2[a2][0] || t1[a1][0] == t2[a2][1])
        cout<<t1[a1][0]<<endl;
    else if(t2[a2][0] == t1[a1][1])
        cout<<t1[a1][1]<<endl;
    else if(t2[a2][1] == t1[a1][1] && t2[a2][1] != -1)
        cout<<t2[a2][1]<<endl;
    else if(t2[a2][1] == -1 || t1[a1][1] == -1)
        cout<<-1<<endl;
    else{
        int d1 = t1[a1][1] - t1[a1][0];
        int d2 = t2[a2][1] - t2[a2][0];
        int c = t2[a2][0] - t1[a1][0];
        long long res = -1;
        for(int x = 0;x<=1000000;x++){
            long long d = c + x*1LL*d2;
            if(d >= 0 && d%d1 == 0){
                d += t1[a1][0];
                if(res == -1)
                    res = d;
                else
                    res = min(res, d);
            }
        }
        cout<<res<<endl;
    }
}
