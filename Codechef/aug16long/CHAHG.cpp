#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

struct Interval{
    int st, end;
    bool exists;
    bool ends;
    void fill(int _st, int _end, bool _exists, bool _ends){
        st = _st;
        end = _end;
        exists = _exists;
        ends = _ends;
    }
};
int n;
int h[10], m[10];
Interval intervals[2][10];
Interval getans(int idx, int mode, Interval &prev){
    if(!prev.exists || idx == n)
        return prev;
    Interval &cur = intervals[mode][idx];
    if(!cur.exists) return cur;

    Interval nxt;
    nxt.st = max(cur.st, prev.st);
    if(prev.ends && cur.ends){
        nxt.ends = true;
        nxt.end = min(cur.end, prev.end);
    }else{
        if(prev.ends || cur.ends){
            nxt.ends = true;
            nxt.end = (prev.ends?prev.end:cur.end);
        }else{
            nxt.ends = false;
        }
    }
    nxt.exists = true;
    if(nxt.ends && nxt.end < nxt.st)
        nxt.exists = false;

    return getans(idx+1, !mode, nxt);
}
int main(){
    Interval dummy;
    dummy.fill(0, 0, true, false);
    int iii=0;
    in_T{
        // printf("%d\n", iii);
        iii++;
        in_I(n);
        for(int i = 0;i<n;i++){
            in_I(h[i]);
            in_I(m[i]);
        }
        if(n == 1){
            printf("1\n0 Inf\n");
            continue;
        }
        bool proceed = true;
        for(int i = 1;i<n;i++){
            if(h[i] == h[i-1] && m[i] == m[i-1]){
                printf("0\n");
                proceed = false;
                break;
            }
        }
        // 0 -> increasing 1 -> decreasing
        if(!proceed)continue;
        for(int i = 1;i<n;i++){
            int num = h[i] - h[i-1];
            int den = m[i-1] - m[i];
            if(m[i] == m[i-1] || num*1LL*den < 0){
                if(h[i-1] < h[i]){
                    intervals[0][i].fill(0, 0, true, false);
                    intervals[1][i].fill(0, 0, false, false);
                }else{
                    intervals[1][i].fill(0, 0, true, false);
                    intervals[0][i].fill(0, 0, false, false);
                }
            }else{
                // same height at time 0
                if(h[i] == h[i-1]){
                    if(m[i-1] < m[i]){
                        intervals[0][i].fill(1, 0, true, false);
                        intervals[1][i].fill(0, 0, false, false);
                    }else{
                        intervals[1][i].fill(1, 0, true, false);
                        intervals[0][i].fill(0, 0, false, false);
                    }
                }else{
                    // same height at positive time
                    int t = num/den;
                    bool isInt = (num%den == 0);
                    if(h[i-1] < h[i]){
                        intervals[0][i].fill(0, t-isInt, true, true);
                        intervals[1][i].fill(t+1, 0, true, false);
                    }else{
                        intervals[1][i].fill(0, t-isInt, true, true);
                        intervals[0][i].fill(t+1, 0, true, false);
                    }
                }
            }
        }
        Interval int1 = getans(1, 0, dummy);
        Interval int2 = getans(1, 1, dummy);
        int tot = 0;
        if(int1.exists)
            tot++;
        if(int2.exists)
            tot++;
        if(int1.exists && int2.exists && int1.st > int2.st)
            swap(int1, int2);
        if(tot == 2 && (int1.end == int2.st || int1.end == int2.st-1)){
            int2.exists = false;
            tot--;
            int1.end = int2.end;
            int1.ends = int2.ends;
        }
        printf("%d\n", tot);
        if(int1.exists){
            printf("%d ", int1.st);
            if(int1.ends){
                printf("%d", int1.end);
            }else
                printf("Inf");
            printf("\n");
        }
        if(int2.exists){
            printf("%d ", int2.st);
            if(int2.ends){
                printf("%d", int2.end);
            }else
                printf("Inf");
            printf("\n");
        }
    }
}
