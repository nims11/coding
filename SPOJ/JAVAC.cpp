#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  char x[101];
  bool underScore;bool capital;
  int len,i;
  while(cin.getline(x,101,'\n'))
  {
    underScore=capital=false;
    len=strlen(x);
    for(i=0;i<len && (!underScore || !capital);i++)
    {
      if(x[i]=='_')
      {
	underScore=true;
	if(x[i+1]=='_')
	  capital=true;
      }
      else if(x[i]>='A' && x[i]<='Z')
	capital=true;
    }
    if((capital && underScore) || (x[0]<'a' || x[0]>'z') || ((x[len-1]<'a' || x[len-1]>'z') && (x[len-1]<'A' || x[len-1]>'Z')))
    {
      cout<<"Error!"<<endl;
      continue;
    }
    if(capital)
    {
      for(i=0;i<len;i++)
      {
	if(x[i]>='A' && x[i]<='Z')
	{
	  cout<<'_';x[i]+='a'-'A';
	}
	cout<<x[i];
      }
      cout<<endl;
      continue;
    }
    if(underScore)
    {
      for(i=0;i<len;i++)
      {
	if(x[i]=='_')
	{
	  if(x[i+1]>='a' && x[i+1]<='z')
	  {x[i+1]+='A'-'a';}
	  continue;
	}
	cout<<x[i];
      }
      cout<<endl;
      continue;
    }
    cout<<x<<endl;
  }
  
  
  return 0;
}