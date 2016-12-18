#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    double a;string s;
    cin>>a>>s;
    cout<<i<<" ";
    if(s=="kg")
      printf("%.4lf lb\n",a*2.2046);
    else if(s=="l")
      printf("%.4lf g\n",a*0.2642);
    else if(s=="lb")
      printf("%.4lf kg\n",a*0.4536);
    else
      printf("%.4lf l\n",a*3.7854);
  }
  return 0;
}
