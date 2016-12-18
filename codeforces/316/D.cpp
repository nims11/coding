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
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)
int n, m;
vector<int> kids[500001];
char str[500001];
int depth[500001];
int inTime[500001], outTime[500001];
int tcnt = 0;
int res[500001];
vector<int> invDepth[500001];
bool cmp(int x, int y){
    return inTime[x] < inTime[y];
}
void dfs(int idx){
    inTime[idx] = ++tcnt;
    invDepth[depth[idx]].push_back(idx);
    for(int i = 0;i<kids[idx].size();i++){
        int v = kids[idx][i];
        depth[v] = depth[idx]+1;
        dfs(v);
    }
    outTime[idx] = ++tcnt;
}
vector<int> invDepthQuery[500001];

    vector<pair<int, int> > queries;
bool cmp1(int x, int y){
    return inTime[queries[x].first] < inTime[queries[y].first];
}
int main()
{
    in_I(n);
    in_I(m);
    in_S(str);
    for(int i = 0;i<n-1;i++){
        int x;
        in_I(x);
        kids[x].push_back(i+2);
    }
    depth[1] = 1;
    dfs(1);
    for(int i = 0;i<m;i++){
        int v, h;
        in_I(v);
        in_I(h);
        queries.push_back(make_pair(v, h));
        invDepthQuery[h].push_back(i);
    }
    for(int i = 0;i<500001;i++)
        sort(BE(invDepthQuery[i]), cmp1), sort(BE(invDepth[i]), cmp);
    for(int i = 0;i<500001;i++){
        int arr[invDepth[i].size()+1][26];
        for(int j = 0;j<=invDepth[i].size();j++)
            for(int k = 0;k<26;k++)
                arr[j][k] = 0;

        for(int j = 1;j<=invDepth[i].size();j++){
            arr[j][str[invDepth[i][j-1]-1]-'a']++;
        }

        for(int j = 0;j<invDepthQuery[i].size();j++){
            int st = 1, end = invDepth[i].size();
            int v = queries[invDepthQuery[i][j]].first;
            int val = inTime[v];
            while(st < end){
                int mid =  (st + end)/2;
                int u = invDepth[i][mid];
                if(inTime[u] < val){
                    st = mid+1;
                }else
                    end = mid;
            }
            int ll = end;
            st = 1, end = invDepth[i].size();
            while(st < end){
                int mid = (st + end)/2;
                int u = invDepth[i][mid];
                if(inTime[u] > val){
                    end = mid;
                }else
                    st = mid + 1;
            }
            int rr = st -1;
            int even = 0, odd = 0;
            for(int k = 0;k<26;k++){
                if((arr[rr][k] - arr[ll-1][k]) % 2 == 0)
                    even++;
                else
                    odd++;
            }
            cout<<even<<" "<<odd<<endl;
            res[invDepthQuery[i][j]] = (odd<=1);
        }
    }
    for(int i = 0;i<m;i++)
        printf(res[i]?"Yes\n":"No\n");
}
