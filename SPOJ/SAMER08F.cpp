#include <iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  while(n)
  {
    long result=0;
    while(n)
    {
      result+=n*n;
      n--;
    }
    cout<<result<<endl;
    cin>>n;
  }
  return 0;
}