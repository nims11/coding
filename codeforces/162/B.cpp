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
#define SIZE 100000;
using namespace std;
void genPrimes(vector<int>&primes,int n){
	for(int i=2;i<=n;i++){
		int root=int(sqrt(i))+1;
		bool found=false;
		for(vector<int>::const_iterator it = primes.begin();it!=primes.end()&& *it<root;it++){
			if(i% *it==0){found=true;break;}
		}
		if(!found)primes.push_back(i);
	}
}
int main()
{
    vector<int> primes;
    genPrimes(primes, 100000);
    int n;
    in_I(n);
    int a[n];
    for(int i=0;i<n;i++)
        in_I(a[i]);
    vector<int> pfacs[n];
    int foo[100001];
    for(int i=0;i<=100000;i++)
        foo[i] = -1;
    for(int j=0;j<n;j++)
    {
        int q = a[j];
        int lt = sqrt(q);
        for(int i=0;i<primes.size() && primes[i]<=lt && primes[i]<=q;i++)
        {
            if(q%primes[i] == 0)
            {
                pfacs[j].push_back(primes[i]);
                while(q%primes[i] == 0)
                    q/=primes[i];
            }
        }
        if(q!=1)
        {
            pfacs[j].push_back(q);
        }
    }
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i] = 1;
    for(int i=0;i<pfacs[0].size();i++)
        foo[pfacs[0][i]] = 0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<pfacs[i].size();j++)
        {
//            cout<<pfacs[i][j]<<" "<<foo[pfacs[i][j]]<<endl;
            if(foo[pfacs[i][j]] != -1)
            {
                dp[i] = max(dp[i], 1+dp[foo[pfacs[i][j]]]);
            }
            foo[pfacs[i][j]] = i;
        }
//        cout<<endl;
    }
    cout<<dp[n-1]<<endl;
}
