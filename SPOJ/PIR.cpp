#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
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
        printf("%.4lf\n",volume);
    }
    return 0;
}
