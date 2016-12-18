/*
 * The pattern is easily observable. The objective is to recursively represent a number ONLY in power of two using only 2 and 0.
 * A simple recursive solution can be written for this problem
 */
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string convert(long long n)
{
	if(n==0)
		return "0";
	if(n==1)
		return "2(0)";
	if(n==2)
		return "2";
	string str="";
	while(n!=0)
	{
		int x=(int)log2(n);
		n-=(long long)pow(2,x);
		if(x==1)
			str+="2+";
		else
		str+="2("+convert(x)+")+";
	}
	return str.substr(0,str.length()-1);

}
int main()
{
	long long n;

	while(cin>>n)
	cout<<n<<"="<<convert(n)<<endl;
	return 0;
}
