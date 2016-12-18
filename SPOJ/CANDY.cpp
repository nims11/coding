/*
Aim is to find the average amount of candies in a packet. If an integral average exists, the sum of deviations of all packets having less than average is calculated.
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int n,result;
  float sum;
  cin>>n;
  while(n!=-1)
  {
    int *pkt=new int[n];
    sum=0;result=0;
    for(int i=0;i<n;i++)
    {
      cin>>pkt[i];
      sum+=pkt[i];
    }
    sum/=n;
    if(floor(sum)!=ceil(sum))
      cout<<-1<<endl;
    else
    {
      for(int i=0;i<n;i++)
      {
	if(pkt[i]<sum)
	  result+=(sum-pkt[i]);
      }
      cout<<result<<endl;
    }
    delete [] pkt;
    cin>>n;
  }
  return 0;
}
