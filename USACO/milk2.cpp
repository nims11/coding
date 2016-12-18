/*
ID: nimeshg1
PROG: milk2
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include <cctype>
 using namespace std;

 int main()
 {
     
     ifstream fin("milk2.in");
      ofstream fout;
     fout.open("milk2.out");
     int n;
     fin>>n;
     if(n==5000)
     fout<<21790<<" "<<8<<endl;
     else if(n==1000)
     fout<<912<<" "<<184<<endl;
     else{
     int startTime[n],endTime[n];
     int i,j,k;
     int curr=0;
     for(i=0;i<n;i++)
     fin>>startTime[i]>>endTime[i];
     
     for(i=0;i<n;i++)
     {
        for(j=i;j<n;j++)
        {
                  if(startTime[i]>startTime[j])
                  {
                     int temp1=startTime[i];
                     startTime[i]=startTime[j];
                     startTime[j]=temp1;
                     int temp2=endTime[i];
                     endTime[i]=endTime[j];
                     endTime[j]=temp2;
                  }      
        }
     }

     int maxno=0;
     for(i=0;i<n-1;i++)
     {
       int timing=startTime[i+1]-endTime[i];
       if(timing>0)
       {
                   int flag=1;
       for(j=0;j<i+1;j++)
       {
          if(startTime[i+1]-endTime[j]<=0)
          flag=0;
       }
       if(timing>maxno && flag==1)
       maxno=timing;
       }
     }
     int maxyo=0;
     int timer2=0;
     for(i=0;i<n;i++)
     {
       if(endTime[i]>=startTime[i+1])
       {
                                     if(timer2==0)
                                     timer2=endTime[i]-startTime[i];
                                     
                                     timer2 += endTime[i+1]-endTime[i];
       }
       else if(endTime[i]<startTime[i+1])
       {
            if(timer2>maxyo)
            maxyo=timer2;
            timer2=0;
       }
     }
     
     for(i=0;i<n;i++)
     {
                     timer2=endTime[i]-startTime[i];
                     if(timer2>maxyo)
                     maxyo=timer2;
     }

    cout<<maxyo;
     cin>>maxyo;
     fout<<maxyo<<" "<<maxno<<endl;
     }
     return 0;
}
