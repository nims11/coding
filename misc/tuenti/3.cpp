#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double res[1337][1337];
int main(){
	int t;
	cin>>t;
	while(t--){
		int x, y;
		cin>>x>>y;
		float res = sqrt(x*x+y*y);
		if(int(res)*int(res) == x*x+y*y)
			printf("%.0f\n", res);
		else
			printf("%.2f\n", res);
	}
}
