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


int main()
{
        ifstream fin("namenum.in");
      ofstream fout ;
     fout.open("namenum.out");
         long n=111;
    string nstr;
    fin>>nstr;
    
    int nod=0;
    for(int i=0;;i++)
    {
            if(nstr[i]!='0' && nstr[i]!='1' && nstr[i]!='2' && nstr[i]!='3' && nstr[i]!='4' && nstr[i]!='5' && nstr[i]!='6' && nstr[i]!='7' && nstr[i]!='8' && nstr[i]!='9')
            {nod=i;
            break;}
    }
    int digits[nod];
    for(int i=0;i<nod;i++)
    {
            switch(nstr[i])
            {
                           case '0':
                                digits[i]=0;
                                break;
                           case '1':
                                digits[i]=1;
                                break;
                           case '2':
                                digits[i]=2;
                                break;
                           case '3':
                                digits[i]=3;
                                break;
                           case '4':
                                digits[i]=4;
                                break;
                           case '5':
                                digits[i]=5;
                                break;
                           case '6':
                                digits[i]=6;
                                break;
                           case '7':
                                digits[i]=7;
                                break;
                           case '8':
                                digits[i]=8;
                                break;
                           case '9':
                                digits[i]=9;
                                break;
            }
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
    
    
 int status=0;
 int flag=0;
    ifstream fin2("dict.txt");
    char names[12];
//    int i2=0;
    while (!fin2.eof( ))      //if not at end of file, continue reading numbers
     {
          
    fin2>>names;
    if(strlen(names)==nod)
    {
                          flag=0;
       for(int i=0;i<nod;i++)
       {
               if(names[i]==chars[digits[i]][0]||names[i]==chars[digits[i]][1]||names[i]==chars[digits[i]][2])
               flag=1;
               else{
                    flag=0;
                    break;
                    }
       }
       if(flag)
       {
       fout<<names<<endl;
       status=1;
       }
    }
  //  i2++;
}

    
 /*      int totalPer=pow(3,nod);
    long all[totalPer];
    for(int i=0;i<totalPer;i++)
    all[i]=0;
    int count=0;
    
    for(int i=0;i<nod;i++)
   {
            int effi=pow(3,(nod-i-1));
            int times=totalPer/(3*effi);
            for(int k=0;k<times;k++)
            {
                     long power=1;
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
                    
                    output[i]+=(chars[digits[j]][_digits[j]]);
            }
            for(int z=0;z<i2;z++)
                    {
                                 if(output[i][0]==names[z][0])
                            if(output[i]==names[z])
                            {fout<<names[z]<<endl;
                            status=1;}
                    }
                    
                   // fout<<all[i]<<endl;
            
    }*/
    if(status==0)
    fout<<"NONE"<<endl;
    
    return 0;
}
