
/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<vector>
#include<utility>
#include<map>
using namespace std;
int size;
vector<int> v;
template <typename T> T max(T &a,T &b)
{
    if(a>b)return a;
    return b;
}
map < pair<int,int> , int> dp;
int getans(int start,int end)
{
    pair <int,int> k(start,end);
    if(dp.find(k)!=dp.end())
    {
        return dp[k];
    }

    int day=size-(end-start);
    dp[k]=max(v[start]*day+getans(start+1,end),v[end]*day+getans(start,end-1));
    return dp[k];

}
int main()
{
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
        pair <int,int> k(v.size()-1,v.size()-1);
        dp[k]=x*size;
    }
    cout<<getans(0,size-1)<<endl;
    return 0;
}
