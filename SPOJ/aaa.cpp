#include<string>
#include<iostream>
#include<cmath>
#define R return
#define L long long
using namespace std;
string C(L n)
{if(!n)R "0";if(n==1)R "2(0)";if(n==2)R "2";string str="";while(n){L x=(L)log2(n);n-=(L)pow(2,x);if(x==1)str+="2+";else 
str+="2("+C(x)+")+";}return str.substr(0,str.length()-1);}int main(){L n;while(cin>>n)cout<<n<<"="<<C(n)<<endl;}
