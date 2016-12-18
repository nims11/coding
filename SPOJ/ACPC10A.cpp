#include <iostream>
#include<vector>
using namespace std;
int main()
{
  float x,y,z;
  cin>>x>>y>>z;
  vector<pair<int, pair<int, int> > >foo;
  foo.push_back(make_pair(1, make_pair(1, 1)));
  while(x || y || z)
  {
    float d=y-x;
    if(d==z-y)
      cout<<"AP "<<z+d<<endl;
    else if((d=y/x)==z/y)
      cout<<"GP "<<z*d<<endl;
    
    cin>>x>>y>>z;
  }
  return 0;
}
