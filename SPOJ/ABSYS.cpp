/*
Objective: given an expression [a] [operator] [b] = [c], find the missing number
Solution: simply input in string various part of the expression and evaluate the missing part.
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
bool isIn(char x[])
{
  int len=strlen(x)-6;
  for(int i=0;i<len;i++)
    if(x[i]=='m')return true;
    return false;
}
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    char a[20],b[20],c[20];
    cin>>a;cin.ignore(2);
    cin>>b;cin.ignore(2);
    cin>>c;
    int a_int,b_int,c_int;
    if(isIn(a))
    {
      b_int=atoi(b);
      c_int=atoi(c);
      a_int=c_int-b_int;
    }else if(isIn(b))
    {
      a_int=atoi(a);
      c_int=atoi(c);
      b_int=c_int-a_int;
    }else if(isIn(c))
    {
      a_int=atoi(a);
      b_int=atoi(b);
      c_int=a_int+b_int;
    }else
    {
      a_int=atoi(a);
      c_int=atoi(c);
      b_int=atoi(b);
    }
    cout<<a_int<<" + "<<b_int<<" = "<<c_int<<endl;
  }
  return 0;
}
