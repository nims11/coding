/*
ID: nimeshg1
PROG: ride
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
 using namespace std;
 int main()
 {
     for(int i=0;i<=1000;i++)
     int j=100;
     ifstream fin("ride.in");
      ofstream fout;
     fout.open("ride.out");
     
     char comets[7], groupers[7];
     fin>>comets>>groupers;
     long unsigned int cno=1,gno=1;
    int i;
     for(i=0;i<6;i++)
     {
             if(comets[i]=='\0')
     break;
     if(comets[i]>96)
     cno *= ((int)comets[i] - 96);
     else
     cno *= ((int)comets[i] - 64);
     
     }
     for(i=0;i<6;i++)
     {
             if(groupers[i]=='\0')
     break;
             if(groupers[i]>96)
     gno *= ((int)groupers[i] - 96);
     else
     gno *= ((int)groupers[i] - 64);
     
     }
    cout<<i;;
    cin>>groupers;
     if(cno%47 == gno%47)
     fout<<"GO"<<endl;
     else
     fout<<"STAY"<<endl;

     return 0;
 }
