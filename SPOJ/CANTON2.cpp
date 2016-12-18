/*
Easy to solve after some observation. 
*/
#include <iostream>
using namespace std;
void getAns(long r, long n,long val)
{
  long c=1;
  if(r%2==1)
  {
    r-=(n-val);
    c+=(n-val);
  }else
  {
    r-=(val-n);
    c+=(val-n);
  }
   cout<<"TERM "<<n<<" is "<<r<<"/"<<c<<endl;
}
int main()
{
  int t;
  cin>>t;
  long *n=new long[t];
  for(int i=0;i<t;i++)
  {cin>>n[i];}
  long val=0,i=1,diffr=2;
  for(int j=0;j<t;j++)
  {
    val=0,i=1,diffr=2;
    for(;;i++)
    { 
      if(i%2==1)
      {
	val++;
	if(n[j]>=val && n[j]<=val+i-1)
	{
	  getAns(i,n[j],val);i++;break;
	}
	continue;
      }
      else
      {
	val+=diffr;
	diffr+=4;
	if(n[j]<=val && n[j]>=val-(i-1))
	{
	  getAns(i,n[j],val);i++;break;
	}
	continue;
      }
    }
  }
  delete [] n;
  return 0;
}
