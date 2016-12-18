#include <iostream>
#include <cstdlib>
using namespace std;

long r1[10000001],c1[10000001];
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
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
  r1[n]=r;c1[n]=c;
//   cout<<"TERM "<<n<<" is "<<r1[n]<<"/"<<c1[n]<<endl;
}
int main()
{
  int t;
  cin>>t;
  long *n=new long[t];
  long *n2=new long[t];

  for(int i=0;i<t;i++)
  {cin>>n[i];n2[i]=n[i];}
  
  qsort(n,t,sizeof(long),compare);
  long val=0;long i=1;long diffr=2;
  for(int j=0;j<t;j++)
  {
    for(;;i++)
    { 
      if(i%2==1)
      {
	val++;
	if(n[j]>=val && n[j]<=val+i-1)
	{
	  getAns(i,n[j],val);val--;break;
	}
	continue;
      }
      else
      {
	val+=diffr;
	diffr+=4;
	if(n[j]<=val && n[j]>=val-(i-1))
	{
	  getAns(i,n[j],val);diffr-=4;val-=diffr;break;
	}
	continue;
      }
    }
  }
  for(int i=0;i<t;i++)
    cout<<"TERM "<<n2[i]<<" IS "<<r1[n2[i]]<<"/"<<c1[n2[i]]<<endl;
  delete [] n;delete [] n2;
  return 0;
}