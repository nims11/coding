#include <iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int x,y;
  while(n--){
    cin>>x>>y;
    if(x==y){
      if(x%2==0){
	cout<<x*2<<endl;
	continue;
      }else{
	cout<<x*2-1<<endl;
	continue;
      }
      
    }else{
      if(x%2==0 && y%2==0 && x-y==2){
	cout<<x*2-2<<endl;
	continue;
      }else if(x%2==1 && y%2==1 && x-y==2){
	cout<<y*2+1<<endl;
	continue;
      }
    }
    cout<<"No Number"<<endl;
  }
  return 0;
}
