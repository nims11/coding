/*
ID: nimeshg1
PROG: beads
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include <cctype>
 using namespace std;
 int main()
 {
     
     ifstream fin("beads.in");
      ofstream fout;
     fout.open("beads.out");
     int n;
     fin>>n;
     char beadfrm[n],temper[n];
     fin>>beadfrm;
     int brkpt=n-1,foo=0,foomax=0,i=0,j=0,k,k2,endpt=0;

        for(brkpt=0;brkpt<n;brkpt++)
        {
        for(i=brkpt,j=0;i>=0;i++,j++)
        {
          if(i==n)
          i=0;
          temper[j]=beadfrm[i];
          if(i==brkpt-1 && brkpt!=0)
          i=-2;
          else if(brkpt==0 && i==n-1)
          i=-2;
        }
        foo=0;
        char currclr='n';
        for(k=0;k<n;k++)
        {
           
           if(temper[k]!='w')
           {currclr=temper[k];
           break;}
        }
        for(k=0;(k<n && (temper[k]==currclr || temper[k]=='w'));k++)
        ;
        foo=k;
        for(k=n-1;k>foo;k--)
        {
           
           if(temper[k]!='w')
           {currclr=temper[k];
           break;}
        }
        k=foo;
        for(k2=n-1;(k2>=k && (temper[k2]==currclr || temper[k2]=='w'));k2--)
        ;
        foo+=n-k2-1;

       if(foo>foomax)
       foomax=foo;
      
        }
        cin>>foo;

     fout<<foomax<<endl;
     
}
