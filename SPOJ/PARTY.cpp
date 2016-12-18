#include<iostream>
using namespace std;
struct party{
long long cost,fun;
};
struct party knapsack[101][501];
long long cost[101];
long long fun[101];
void getAns(long long m,long long n)
{
    struct party k1,k2;
    k1=knapsack[m-1][n];
    if(k1.fun==-1)
    {
        getAns(m-1,n);
        k1=knapsack[m-1][n];
    }
    if(n-cost[m]>=0)
    {
        k2=knapsack[m-1][n-cost[m]];
        if(k2.fun==-1)
        getAns(m-1,n-cost[m]);
        k2=knapsack[m-1][n-cost[m]];
        k2.fun+=fun[m];
        k2.cost+=cost[m];
    }else k2.fun=-1;
    if(k1.fun==k2.fun)
    knapsack[m][n]=k1.cost>k2.cost?k2:k1;
    else
    knapsack[m][n]=k1.fun>k2.fun?k1:k2;
}
int main()
{
    long long budget,n;
    while(cin>>budget>>n)
    {
        if(budget==0 && n==0)
        return 0;
        for(long long i=0;i<=budget;i++)knapsack[0][i].cost=knapsack[0][i].fun=0;
        for(long long i=1;i<=n;i++)
        {
            cin>>cost[i]>>fun[i];
        }
        for(long long i=1;i<=n;i++)
        {
            for(long long j=0;j<=budget;j++)
            knapsack[i][j].fun=knapsack[i][j].cost=-1;
        }
        getAns(n,budget);
        cout<<knapsack[n][budget].cost<<" "<<knapsack[n][budget].fun<<endl;

    }
}
