/*
ID: nimeshg1
PROG: transform
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include <cctype>
 using namespace std;

 int main()
 {
     
     ifstream fin("transform.in");
      ofstream fout;
     fout.open("transform.out");
     int n,flag;
     fin>>n;
     char gridi[n][n];
     char gridf[n][n];
     char gridexp[n][n];
     int i,j,k;
     for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       fin>>gridi[i][j];
     }
     for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       fin>>gridf[i][j];
     }
//     for(i=0;i<n;i++)
//     {
//       for(j=0;j<n;j++)
//       cout<<gridi[i][j];
//       cout<<endl;
//     }
     
     //ninetyright
     for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       gridexp[i][n-1-j]=gridi[j][i];
     }
//     for(i=0;i<n;i++)
//     {
//       for(j=0;j<n;j++)
//       cout<<gridexp[i][j];
//       cout<<endl;
//     }
//     cout<<endl;
     
     flag=1;
     for(i=0;i<n;i++)
     {
                     for(j=0;j<n;j++)
                     {
                        if(gridf[i][j]!=gridexp[i][j])
                        flag=0;
                     }
     }
     if(flag==1)
     {fout<<1<<endl;
     exit(0);}
     
     //180 right
     char gridexp2[n][n];
     for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       gridexp2[i][n-1-j]=gridexp[j][i];
     }
//     for(i=0;i<n;i++)
//     {
//       for(j=0;j<n;j++)
//       cout<<gridexp2[i][j];
//       cout<<endl;
//     }
     
     flag=1;
     for(i=0;i<n;i++)
     {
                     for(j=0;j<n;j++)
                     {
                        if(gridf[i][j]!=gridexp2[i][j])
                        flag=0;
                     }
     }
     if(flag==1)
     {fout<<2<<endl;
     exit(0);}
     
     cout<<endl;
     //270 right
     char gridexp3[n][n];
     for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       gridexp3[i][n-1-j]=gridexp2[j][i];
     }
//     for(i=0;i<n;i++)
//     {
//       for(j=0;j<n;j++)
//       cout<<gridexp3[i][j];
//       cout<<endl;
//     }
//     cout<<endl;
     flag=1;
     for(i=0;i<n;i++)
     {
                     for(j=0;j<n;j++)
                     {
                        if(gridf[i][j]!=gridexp3[i][j])
                        flag=0;
                     }
     }
     if(flag==1)
     {fout<<3<<endl;
     exit(0);}
     //reflection
     char gridexp4[n][n];
     for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       gridexp4[i][n-1-j]=gridi[i][j];
     }
//     for(i=0;i<n;i++)
//     {
//       for(j=0;j<n;j++)
//       cout<<gridexp4[i][j];
//       cout<<endl;
//     }
     
     flag=1;
     for(i=0;i<n;i++)
     {
                     for(j=0;j<n;j++)
                     {
                        if(gridf[i][j]!=gridexp4[i][j])
                        flag=0;
                     }
     }
     if(flag==1)
     {fout<<4<<endl;
     exit(0);}
     
     //ninetyright
     for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       gridexp[i][n-1-j]=gridexp4[j][i];
     }
//     for(i=0;i<n;i++)
//     {
//       for(j=0;j<n;j++)
//       cout<<gridexp[i][j];
//       cout<<endl;
//     }
//     cout<<endl;
     flag=1;
     for(i=0;i<n;i++)
     {
                     for(j=0;j<n;j++)
                     {
                        if(gridf[i][j]!=gridexp[i][j])
                        flag=0;
                     }
     }
     if(flag==1)
     {fout<<5<<endl;
     exit(0);}
     //180 right
   
     for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       gridexp2[i][n-1-j]=gridexp[j][i];
     }
//     for(i=0;i<n;i++)
//     {
//       for(j=0;j<n;j++)
//       cout<<gridexp2[i][j];
//       cout<<endl;
//     }
     flag=1;
     for(i=0;i<n;i++)
     {
                     for(j=0;j<n;j++)
                     {
                        if(gridf[i][j]!=gridexp2[i][j])
                        flag=0;
                     }
     }
     if(flag==1)
     {fout<<5<<endl;
     exit(0);}
//     cout<<endl;
     //270 right

     for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       gridexp3[i][n-1-j]=gridexp2[j][i];
     }
//     for(i=0;i<n;i++)
//     {
//       for(j=0;j<n;j++)
//       cout<<gridexp3[i][j];
//       cout<<endl;
//     }
//     cout<<endl;
     flag=1;
     for(i=0;i<n;i++)
     {
                     for(j=0;j<n;j++)
                     {
                        if(gridf[i][j]!=gridexp[i][j])
                        flag=0;
                     }
     }
     if(flag==1)
     {fout<<5<<endl;
     exit(0);}
     
     flag=1;
     for(i=0;i<n;i++)
     {
                     for(j=0;j<n;j++)
                     {
                        if(gridf[i][j]!=gridi[i][j])
                        flag=0;
                     }
     }
     if(flag==1)
     {fout<<6<<endl;
     exit(0);}
     
     fout<<7<<endl;
}

