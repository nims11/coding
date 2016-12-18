/*
 * Identify the repeating pattern for the last digit
 */
#include <iostream>
#include <string>
using namespace std;
int rep[10];
int getAns(int last_a,long long unsigned b)
{
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
    string str;int a;long long unsigned b;cin>>str>>b;a=str[str.length()-1]-'0';
    if(b==0) cout<<1<<endl;
    else cout<<getAns(a,b)<<endl;
  }
}
