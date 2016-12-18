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
char str[100020];
long long arr[100010];
char openToClose[250];
int pairIdx[100010];
int n;
int visited[100010];
long long solve(int idx){
    long long cur = 0;
    int r = idx;
    vector<int> valid;
    // cout<<"++";
    while(1){
        if(r > n || !openToClose[str[r]] || pairIdx[r] == -1)break;
        valid.push_back(r);
        // cout<<r<<","<<pairIdx[r]<<" ";
        visited[r] = visited[pairIdx[r]] = 1;
        r = pairIdx[r]+1;
    }
    // cout<<endl;
    long long ret = 0;
    for(int r = 0;r<valid.size();r++){
        cur += arr[pairIdx[valid[r]]] - arr[valid[r]-1];
        ret = max(ret, cur);
        if(cur < 0){
            cur = 0;
        }
    }
    // cout<<ret<<endl;
    return ret;
}
int isBal(int x, int y){
    int cur = 0;
    while(x<=y){
        cur += (str[x] == ')'?-1:1);
        if(cur < 0)
            return false;
        x++;
    }
    return (cur == 0);
}
long long brute(){
    long long ret = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++)
            ret = max(ret, isBal(i, j)*(arr[j]-arr[i-1]));
    }
    return ret;
}
int main()
{
    openToClose['['] = ']';
    openToClose['{'] = '}';
    openToClose['('] = ')';
    openToClose['<'] = '>';
    in_T{
        in_I(n);
        for(int i = 1;i<=n;i++)
            pairIdx[i] = -1, visited[i] = 0;
        in_S(str+1);
        for(int i = 1;i<=n;i++)
            in_L(arr[i]);
        for(int i = 1;i<=n;i++)
            arr[i] += arr[i-1];
        stack<int> S;
        for(int i = 1;i<=n;i++){
            if(openToClose[str[i]]){
                S.push(i);
            }else if (S.empty()){
                continue;
            }if(str[i] == openToClose[str[S.top()]]){
                pairIdx[S.top()] = i;
                pairIdx[i] = S.top();
                S.pop();
            }
        }
        long long res = 0;
        for(int i = 1;i<=n;i++){
            if(visited[i])
                continue;
            if(openToClose[str[i]]){
                res = max(res, solve(i));
            }
        }
        if(brute() != res){
            cout<<(str+1)<<endl;
            for(int i = 1;i<=n;i++)
                cout<<arr[i]-arr[i-1]<<endl;
            return 3;
        }
        continue;
        printf("%lld\n", res);
    }
}
