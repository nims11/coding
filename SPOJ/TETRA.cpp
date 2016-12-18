
/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cmath>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
	in_T
	{	
		double U,V,W,u,v,w;
		cin>>U>>V>>w>>W>>v>>u;
		double x,y,z,X,Y,Z;
		X=(w-U+v)*(U+v+w);
		x=(U-v+w)*(v-w+U);
		Y=(u-V+w)*(V+w+u);
		y=(V-w+u)*(w-u+V);
		Z=(v-W+u)*(W+u+v);
		z=(W-u+v)*(u-v+W);
		double a,b,c,d;
		a=sqrt(x*Y*Z);
		b=sqrt(y*Z*X);
		c=sqrt(z*X*Y);
		d=sqrt(x*y*z);
		double volume=sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d))/(192*u*v*w);
		double S1 = (U+V+W)/2.0, S2 = (U+v+w)/2.0, S3 = (V+w+u)/2.0, S4=(v+u+W)/2.0;
		double SA1 = sqrt(S1*(S1-U)*(S1-V)*(S1-W)), SA2 = sqrt(S2*(S2-U)*(S2-v)*(S2-w)), SA3=sqrt(S3*(S3-V)*(S3-w)*(S3-u)), SA4=sqrt(S4*(S4-v)*(S4-u)*(S4-W));
		printf("%.4lf\n", (volume*3)/(SA1+SA2+SA3+SA4));
	}
}
