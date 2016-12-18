#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  float n;
  cin>>n;
  while(n!=0)
  {
    float count=1;
    float sum=1.0/2;
    while(1)
    {
      if(sum>=n)
	break;
      count++;
      sum+=(1/(count+1));
    }
    cout<<count<<" card(s)"<<endl;
    cin>>n;
  }
  return 0;
}
