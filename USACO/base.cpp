/*
ID: nimeshg1
PROG: namenum
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include <cctype>
#include <math.h>
using namespace std;
int noOfDigits(long n)
{
    for(int i=1;;i++)
    {
       long j=(long)pow(10,i);
       if(n/j==0)
       return i;
    }
}
int getDig(int n,int pos) // position order 43210
{
    n /= (int)pow(10,pos);
    return n%10;
}
int toBasen(int basen,long n)
{
       int nod=noOfDigits(n);
       long i=n;
       int foo[100];
       long j=0;
       while(i>0)
       {
                 foo[j]=i%basen;
             /*    if(foo[j]>9)
                 {
                             switch(foo[j])
                             {
                                case 10:
                                     
                                     
                             }
                 }*/
              //   cout<<"foo[j]="<<foo[j]<<endl;
                 j++;
                // cout<<"j="<<j<<endl;
                 long k=(long)ceil(pow(basen,j));
                // cout<<"k="<<k<<endl;
                 i=n/k;
              //   cout<<"i="<<i<<endl;
       }
    //   cout<<"j="<<j<<endl;
       int flag=1;
       for(i=0;i<j;i++)
       {
          if(foo[i]!=foo[j-1-i])
          {
                                flag=0;
          break;}
          
       }
       
       return flag;
}
int main()
{
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int n;
    fin>>n;
    for(int i=1;i<=300;i++)
    {
            if(toBasen(n,i*i))
            {
               fout<<i<<" "<<i*i<<endl;
            }
    }
    return 0;
}
