#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

string reverse(string n)
{
  string x;
  int len=n.size();
  for(int i=len-1;i>=0;i--)
    x.push_back(n[i]);
  
  return x;
}
int main()
{
  int t;
  cin>>t;
  string k;
  cin.ignore(1);
  while(t--)
  {
    getline(cin,k);
    string left,right,leftRev;
    int len=k.size();
    int a1=0,b1=len/2-1,a2=(len+1)/2,b2=len-1;
    left=k.substr(a1,b1-a1+1);
    right=k.substr(a2,b2-a2+1);
    leftRev=reverse(left);
    int rightInt=atoi(right.c_str()),leftInt=atoi(left.c_str()),leftRevInt=atoi(leftRev.c_str());
    if(len%2==0)
    {
      if(rightInt<leftRevInt)
      {
	right=leftRev;
	cout<<left<<right<<endl;
      }
      else if(rightInt==leftRevInt && (rightInt+1)%10==0 && log10(rightInt+1)==len/2)
      {
	cout<<1;
	for(int i=0;i<len-1;i++)
	  cout<<0;
	cout<<1<<endl;
      }else
      {
	int left1=atoi(left.c_str())+1;
	cout<<left1;
	for(;left1>0;left1/=10)
	  cout<<left1%10;
	cout<<endl;
      }
    }
   else
    {
      if(rightInt<leftRevInt)
      {
	right=leftRev;
	cout<<left<<k[len/2]<<right<<endl;
      }
      else if(rightInt>leftRevInt)
      {
	
	int left1=atoi(left.c_str())+1;
	if(k[len/2]=='9')
	{
	  left1=atoi(left.c_str())+1;
	  k[len/2]='0';
	}else
	{
	  left1=atoi(left.c_str());
	  k[len/2]++;
	}
	
	cout<<left1<<k[len/2];
	for(;left1>0;left1/=10)
	  cout<<left1%10;
	cout<<endl;
      }
      else
      {
	if(k[len/2]=='9')
	{
	  if((rightInt+1)%10==0 && log10(rightInt+1)==len/2)
	  {
	    int left1=atoi(left.c_str())+1;
	  k[len/2]='0';
	  cout<<left1;
	for(;left1>0;left1/=10)
	  cout<<left1%10;
	cout<<endl;
	  }else
	  {
	    int left1=atoi(left.c_str())+1;
	  k[len/2]='0';
	  cout<<left1<<k[len/2];
	for(;left1>0;left1/=10)
	  cout<<left1%10;
	cout<<endl;
	  }
	  
	}
	else
	{
	  k[len/2]++;
	  cout<<left<<k[len/2]<<right<<endl;
	}
      }
    }
    
  }
  return 0;
}


