#include<iostream>
using namespace std;
int main()
{
  int t,a,n,d;
  cin>>t;
  while(t--)
  {
    cin>>n>>a>>d;
    int result=0;
    for(int i=0;i<n;i++)
      result+=a+i*d;
    cout<<result<<endl;
  }
  
  return 0;
}