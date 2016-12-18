/*
ID: nimeshg1
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include <cctype>
 using namespace std;
 int main()
 {
     
     ifstream fin("gift1.in");
      ofstream fout;
     fout.open("gift1.out");
    int np,i,x=0,flag=0;
    fin>>np;
    char names[np][14],giver[np][14];
    int credit[np],debit[np],initial[np],nptogive[np];

for(i=0;i<np;i++)
{
                 fin>>names[i];
                 
                 credit[i]=0;
                 debit[i]=0;
                 }
                 
                 for(i=0;i<np;i++)
                 {
                                  char y[14];
                                  fin>>y;
                                  fin>>initial[i]>>nptogive[i];
                                  if(nptogive[i]!=0)
                                  x=initial[i]/nptogive[i];
                                  else
                                  x=0;
                                  flag=0;
                                  
                                  for(int k=0;k<np;k++)
                                         {
                                                for(int l=0;l<strlen(y);l++)
                                                {
                                                if(names[k][l]==y[l])
                                                 {
                                                      flag=1;
                                                }else
                                                {
                                                     flag=0;
                                                     break;
                                                     }
                                                }
                                                if(flag==1)
                                               debit[k]=nptogive[i]*x;
                                          }
                                  flag=0;
                                  
                                  
                                  
                                  
                                  for(int j=0;j<nptogive[i];j++)
                                  {
                                          fin>>y;
                                          
                                        for(int k=0;k<np;k++)
                                         {
                                                for(int l=0;l<strlen(y);l++)
                                                {
                                                if(names[k][l]==y[l])
                                                 {
                                                      flag=1;
                                                }else
                                                {
                                                     flag=0;
                                                     break;
                                                     }
                                                }
                                                if(flag==1)
                                               credit[k]+=x;
                                          }
                                  }
                 }
                for(i=0;i<np;i++)
                 {
                                int net=credit[i]-debit[i];
              fout<<names[i]<<" "<<net<<endl;
                 }
                                  
     return 0;
 }

