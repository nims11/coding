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
    int base3[4]={0,0,0,0};
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
long toNum(string nstr)
{
     long n=0;
     
     for(int i=0;;i++)
     {
             switch(nstr[i])
             {
                            long j;
                            case '0':
                                 break;
                            case '1':
                                  j=(long)pow(10,i);
                                 n += j*1;
                                 break;
                            case '2':
                                  j=(long)pow(10,i);
                                 n += j*2;
                                 break;
                            case '3':
                                  j=(long)pow(10,i);
                                 n += j*3;
                                 break;
                            case '4':
                                  j=(long)pow(10,i);
                                 n += j*4;
                                 break;
                            case '5':
                                 cout<<"yo"<<i;
                                  j=(long)pow(10,i);
                                 n += j*5;
                                 break;
                            case '6':
                                  j=(long)pow(10,i);
                                 n += j*6;
                                 break;
                            case '7':
                                  j=(long)pow(10,i);
                                 n += j*7;
                                 break;
                            case '8':
                                  j=(long)pow(10,i);
                                 n += j*8;
                                 break;
                            case '9':
                                  j=(long)pow(10,i);
                                 n += j*9;
                                 break;
                               default:
                                       return n;
             }
     }
}

int main()
{
        ifstream fin("namenum.in");
      ofstream fout ;
     fout.open("namenum.out");
         long n=111;
    string nstr;
    fin>>nstr;
    
    
    cin>>nstr;
    ifstream fin2("dict.txt");
    string names[5000];
    int i2=0;
    while (!fin2.eof( ))      //if not at end of file, continue reading numbers
     {
    fin2>>names[i2];
    i2++;
}
    char chars[10][3];
    char ch='A';
    
    for (int i=2;i<=9;i++)
    {
        for (int j=0;j<=2;j++)
        {
        chars[i][j]=ch;
        ch++;
        if(ch=='Q')
        ch='R';
        }
    }

    int nod=noOfDigits(n);
    int digits[nod];
    for(int i=nod-1;i>=0;i--)
    digits[nod-1-i]=getDig(n,i);

    
        int totalPer=pow(3,nod);
    int all[totalPer];
    for(int i=0;i<totalPer;i++)
    all[i]=0;
    int count=0;
    int status=0;
    for(int i=0;i<nod;i++)
   {
            int effi=pow(3,(nod-i-1));
            int times=totalPer/(3*effi);
            for(int k=0;k<times;k++)
            {
                     int power=1;
                     for(int z=0;z<i;z++)
                     power *= 10;
         for(int j=0;j<effi;j++)
      {
                
              all[count]+=(power*0);
              count++;
      }
      for(int j=0;j<effi;j++)
      {
              all[count]+=(power*1);
              count++;
      }
      for(int j=0;j<effi;j++)
      {
              all[count]+=(power*2);
              count++;
      }
         

      }
     
      count=0;
      

    }
    string output[totalPer];
    for(int i=0;i<totalPer;i++)
    {
            int _digits[nod];
            for(int l=nod-1;l>=0;l--)
     _digits[nod-1-l]=getDig(all[i],l);
            for(int j=0;j<nod;j++)
            {
                    
                    output[i]+=(chars[output[i],digits[j]][_digits[j]]);
            }
            for(int z=0;z<i2;z++)
                    {
                            if(output[i]==names[z])
                            {fout<<names[z]<<endl;
                            status=1;}
                    }
                    
                    fout<<all[i]<<endl;
            
    }
    if(status==0)
    fout<<"NONE"<<endl;
    
    return 0;
}
