/*
ID: nimeshg1
PROG: friday
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include <cctype>
 using namespace std;
 int leaper(int yr);
 int main()
 {
     
     ifstream fin("friday.in");
      ofstream fout;
     fout.open("friday.out");
     int n;
     fin>>n;
     int ndays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
     int currmon=0,currday=5,curryr=1900;
     int day13[7]={0,0,0,0,0,0,0};
     while(curryr<1900+n)
     {
        day13[currday]++;
        if(currmon==1)
        {
                      currday=(currday+leaper(curryr)+13)%7;
                      currmon=2;
        }else if(currmon==11)
        {
             curryr++;
             currmon=0;
             currday=(currday+18+13)%7;
        }else
        {
             currday=(currday+ndays[currmon])%7;
             currmon++;
        }
     }
     fout<<day13[5]<<" "<<day13[6]<<" "<<day13[0]<<" "<<day13[1]<<" "<<day13[2]<<" "<<day13[3]<<" "<<day13[4]<<endl;
     
}
int leaper(int yr)
{
 if ((yr%4==0 && yr%100!=0) || yr%400==0)
 return 16;
 else
 return 15;
}
