/*
ID: nimeshg1
PROG: palsquare
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include <cctype>
#include <math.h>
using namespace std;
    ofstream fout("palsquare.out");
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
       cout<<i<<endl;
       while(i>0)
       {
                 foo[j]=i%basen;
                 j++;
                 long k=(long)ceil(pow(basen,j));
                 i=n/k;
       }
       int flag=1;
       for(i=0;i<j;i++)
       {
          if(foo[i]!=foo[j-1-i])
          {
                                flag=0;
          break;}
          
       }
       if(flag)
       {
               fout<<n<<" ";
               for(i=j-1;i>=0;i--)
               {
                               if(foo[i]>9)
                 {
                             switch(foo[i])
                             {
                                case 10:
                                     fout<<'A';
                                     break;
                                case 11:
                                     fout<<'B';
                                     break;   
                                case 12:
                                     fout<<'C';
                                     break;
                                case 13:
                                     fout<<'D';
                                     break;
                                case 14:
                                     fout<<'E';
                                     break;
                                case 15:
                                     fout<<'F';
                                     break;
                                     case 16:
                                     fout<<'G';
                                     break;
                                case 17:
                                     fout<<'H';
                                     break;
                                case 18:
                                     fout<<'I';
                                     break;
                                case 19:
                                     fout<<'J';
                                     break;
                                case 20:
                                     fout<<'K';
                                     break;
                                case 21:
                                     fout<<'L';
                                     break;
                             }
                 }else
                 fout<<foo[i];
               }
               fout<<endl;
       }
       return flag;
}
int main()
{
    ifstream fin("palsquare.in");

    int n;
    fin>>n;
    n=2;
    for(int i=1;i<=300;i++)
    {
            toBasen(n,i*i);
            
    }
    return 0;
}
