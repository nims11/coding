/*
 * DP
 * the code is self explanatory
 */
#include <iostream>
using namespace std;
const int size=1001;
long long buff[size];
long long getMax(long long n)
{
  if(n<size)
    if(buff[n]!=-1)
      return buff[n];
  long long n1=n/2,n2=n/3,n3=n/4;
  long long res=getMax(n1)+getMax(n2)+getMax(n3);
  if(res<n)
    res=n;
  if(n<size)
      buff[n]=res;
  return res;
}
int main()
{
  for(int i=0;i<size;i++)
    buff[i]=-1;
  buff[0]=0;buff[1]=1;
  long long n;
  while(cin>>n)
  {
     long long res=getMax(n);
    cout<<res<<endl;
  }
  
  return 0;
}
