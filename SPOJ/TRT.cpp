
/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int size;
vector<int> v;
template <typename T> T max(T &a,T &b)
{
    if(a>b)return a;
    return b;
}
int dp[2000][2000]={{0}};
int getans(int start,int end)
{
    if(dp[start][end]!=0)
    {
        return dp[start][end];
    }

    int day=size-(end-start);
    dp[start][end]=max(v[start]*day+getans(start+1,end),v[end]*day+getans(start,end-1));
    return dp[start][end];

}
int main()
{
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
        dp[v.size()-1][v.size()-1]=x*size;
    }
    cout<<getans(0,size-1)<<endl;
    return 0;
}
