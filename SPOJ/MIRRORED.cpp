#include<iostream>
#include<string>
using namespace std;
int main()
{
  cout<<"Ready"<<endl;
  string str;
  getline(cin,str);
  while(str!="  ")
  {
    if(str=="qp" ||str=="pq" ||str=="bd" ||str=="db")
      cout<<"Mirrored pair"<<endl;
    else
      cout<<"Ordinary pair"<<endl;
    getline(cin,str);
  }
  return 0;
}
