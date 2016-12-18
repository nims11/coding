//GQ
/*
Objective: Given a string of numbers, to calculate the number of ways to decode the string if [1-26] maps to [A-Z]

Solution: A good and simple DP problem.

let i be the ending point of the prefix of the string.
then to find the solution for that point you need to look up for the previous point and the pre-previous point and make decisions according to it.
*/
#include<iostream>
using namespace std;
int main()
{
  char ch;
  cin.get(ch);
  while(ch!='0')
  {
    long b[5003];
    char c[5003];
    int count=0;
    while(ch!='\n')
    {
      c[count++]=ch;
      cin.get(ch);
    }
    b[count]=b[count+1]=1;
    c[count]=c[count+1]=1;
    for(int i=count-1;i>=0;i--)
    {
      if(c[i]=='0')
      {
	b[i]=b[i+1];
	i--;b[i]=b[i+1];
	continue;
      }
      b[i]=b[i+1];
      if(((c[i]=='1' && c[i+1]<='9' && c[i+1]>='0') || (c[i]=='2' && c[i+1]<='6' && c[i+1]>='0')) && c[i+2]!='0')
	b[i]+=b[i+2];
    }
    cout<<b[0]<<endl;
    cin.get(ch);
  }
  return 0;
}
