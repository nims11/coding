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
int poss[1000100];
int poss2[1000100];
int arr[1000];
int max_len = -1;
int getans2(int K, int idx){
    if(K == 0)
        return 0;
    int curc[3] = {0};
    int valToBuild = poss2[K];

    while(valToBuild % 4 == 0){
        curc[2]++;
        valToBuild/=4;
    }
    while(valToBuild % 2 == 0){
        curc[0]++;
        valToBuild/=2;
    }
    while(valToBuild % 3 == 0){
        curc[1]++;
        valToBuild/=3;
    }


    int sz = max(1, 2*curc[0]+3*curc[1]+4*curc[2]);
    int cur_max_len = max(1, curc[0]+curc[1]+curc[2]);
    if(max_len == -1)
        max_len = cur_max_len;
    int N = getans2(K-poss2[K], idx+sz+max_len-cur_max_len);
    int foo = idx;
    if(curc[0]+curc[1]+curc[2] == 0)
        arr[foo++] = N+1;

    int offset = N+1;
    for(int i = 0;i<curc[0];i++){
        for(int j = 1;j>=0;j--){
            arr[foo++] = j+offset;
        }
        offset += 2;
    }

    for(int i = 0;i<curc[1];i++){
        for(int j = 2;j>=0;j--){
            arr[foo++] = j+offset;
        }
        offset += 3;
    }

    for(int i = 0;i<curc[2];i++){
        for(int j = 3;j>=0;j--){
            arr[foo++] = j+offset;
        }
        offset += 4;
    }
    while(cur_max_len < max_len){
        sz++;
        cur_max_len++;
        arr[idx+sz-1] = N+sz;
    }
    return N+sz;
}
int getans(int K, int idx){
    if(K == 0)
        return 0;
    int curc[5] = {0};
    int valToBuild = poss[K];

    while(valToBuild % 6 == 0){
        curc[4]++;
        valToBuild/=6;
    }
    while(valToBuild % 5 == 0){
        curc[3]++;
        valToBuild/=5;
    }
    while(valToBuild % 4 == 0){
        curc[2]++;
        valToBuild/=4;
    }
    while(valToBuild % 2 == 0){
        curc[0]++;
        valToBuild/=2;
    }
    while(valToBuild % 3 == 0){
        curc[1]++;
        valToBuild/=3;
    }


    int sz = max(1, 2*curc[0]+3*curc[1]+4*curc[2]+5*curc[3]+6*curc[4]);
    int cur_max_len = max(1, curc[0]+curc[1]+curc[2]+curc[3]+curc[4]);
    if(max_len == -1)
        max_len = cur_max_len;
    int N = getans(K-poss[K], idx+sz+max_len-cur_max_len);
    int foo = idx;
    if(curc[0]+curc[1]+curc[2]+curc[3]+curc[4] == 0)
        arr[foo++] = N+1;

    int offset = N+1;
    for(int i = 0;i<curc[0];i++){
        for(int j = 1;j>=0;j--){
            arr[foo++] = j+offset;
        }
        offset += 2;
    }

    for(int i = 0;i<curc[1];i++){
        for(int j = 2;j>=0;j--){
            arr[foo++] = j+offset;
        }
        offset += 3;
    }

    for(int i = 0;i<curc[2];i++){
        for(int j = 3;j>=0;j--){
            arr[foo++] = j+offset;
        }
        offset += 4;
    }

    for(int i = 0;i<curc[3];i++){
        for(int j = 4;j>=0;j--){
            arr[foo++] = j+offset;
        }
        offset += 5;
    }

    for(int i = 0;i<curc[4];i++){
        for(int j = 5;j>=0;j--){
            arr[foo++] = j+offset;
        }
        offset += 6;
    }
    while(cur_max_len < max_len){
        sz++;
        cur_max_len++;
        arr[idx+sz-1] = N+sz;
    }
    return N+sz;
}
int main(){
    for(int i = 0;i<17;i++){
        int c = 1;
        while((1<<i)*c <= 1000000){
            int cc = 1;
            int cur = (1<<i)*c;
            poss2[cur] = 1;
            while(cur*cc <= 1000000){
                int ccc = 1;
                while(cur*cc*ccc <= 1000000){
                    poss[cur*cc*ccc] = 1;
                    ccc *= 6;
                }
                cc *= 5;
            }
            c*=3;
        }
    }
    int prev = -1;
    int prev2 = -1;
    for(int i = 1;i<=1000000;i++){
        if(poss[i])
            prev = i;
        poss[i] = prev;
        if(poss2[i])
            prev2 = i;
        poss2[i] = prev2;
    }
    in_T{
        int K;
        in_I(K);
        int N = getans(K, 0);
        if(N >  100){
            max_len = -1;
            N = getans2(K, 0);
        }
        printf("%d\n", N);
        max_len = -1;
        for(int i = 0;i<N;i++)
            printf("%d ", arr[i]);
        newline;
    }
}
