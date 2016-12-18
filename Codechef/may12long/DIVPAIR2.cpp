#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
long long n,m;
cin>>n>>m;
long long mi=m;
long long count=0,oddcount=0,evencount=0;
while(mi<=n+1)
{
    if((mi/m)%2==1)
oddcount+=(mi-1)/2;
else
evencount+=(mi-1)/2;
mi+=m;
}
count=oddcount+evencount;
oddcount=0;
long long x=(mi-1)/2;
long long y=mi-n-1;
while(x>y)
{
    oddcount+=y;
count+=x-y;
mi+=m;
x=(mi-1)/2;
y=mi-n-1;
}
cout<<count<<endl;
}
return 0;
}
