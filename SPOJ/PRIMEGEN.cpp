#include<iostream>
#include<cmath>
using namespace std;
bool sieves[100000];
bool isPrime(int n)
{
    if(n==1)return false;
    int limit=sqrt(n);
    for(int i=2;i<=limit;i++)
    {
        if(sieves[i] && n%i==0)
        return false;
    }
    return true;
}
int main()
{
    int limit=sqrt(1000000000);
    for(int i=0;i<100000;i++)
    sieves[i]=true;
    sieves[0]=sieves[1]=false;
    for(int i=2;i<=limit;i++)
    {
        if(sieves[i])
        {
            for(int j=i*i;j<=limit;j+=i)
            sieves[j]=false;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        for(int i=m;i<=n;i++)
        {
            if(isPrime(i))
            {
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
}
