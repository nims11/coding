#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  int n,m,len,i;
  cin>>n;
  string s;
  for(int i=0;i<n;i++)
  {
    cin>>m;cin.ignore(1);
    getline(cin,s);
    cout<<i+1<<" "<<s.substr(0,m-1)<<s.substr(m)<<endl;
    
  }
  return 0;
}
