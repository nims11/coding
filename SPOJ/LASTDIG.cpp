#include <iostream>
using namespace std;
int rep[10];
int getAns(int a,long long b)
{
  int last_a=a%10;
  int x=1+((b-1)%rep[last_a]);
  int res=1;
  for(int i=0;i<x;i++)
    res*=last_a;
  return res%10;
}
void genRep()
{
  for(int i=0;i<10;i++)
  {
    int toOne=i,curr=i;int count=0;
    while(1)
    {
      curr=(curr*i)%10;
      count++;
      if(curr==toOne)
	break;
    }
    rep[i]=count;
  }
}
int main()
{
  genRep();
  int n;
  cin>>n;
  while(n--)
  {
    int a;long long b;
    cin>>a>>b;
    if(b==0)
      cout<<1<<endl;
    else
    cout<<getAns(a,b)<<endl;
  }
  return 0;
}
