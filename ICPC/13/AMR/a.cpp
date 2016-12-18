    #include <iostream>
    #include <cstdio>
    #include <math.h>
    #include <vector>
    #include <string>
    #include <algorithm>
    using namespace std;
     
    char a[12][12];
    int travel[11][11];
    int row,col,r,c;
     
     
     
     
    int compare(int x1,int y1,int x2,int y2)
    { int flag=0;
    for(int i=0;i<r;i++)
    {
    for(int j=0;j<c;j++)
    { flag=0;
    if(a[x1+i][y1+j]!=a[x2+i][y2+j])
    {
    flag=1; break;
    }
     
    } if(flag==1) break;
     
    } return (flag+1)%2;
    }
     
    int function()
    { int flag=0; int m=0;
    for(int i=0;i<=row-r;i++)
    { flag=0;
    for(int j=0;j<=col-c;j++)
    {
    for(int p=i;p<=row-r;p++)
    {
    for(int q=j;q<=col-c;q++)
    {
    if((p==i&&q==j)!=1)
    m=compare(i,j,p,q);
    if(m==1) { //printf("%d\n",r*c);
    return m;
    }
    }
     
    }
     
    }
    } return 0;
    }
     
     
     
    int main()
    {	
    int t;
    int i;
    scanf("%d",&t);
     
    while(t-->0)
    {
    scanf("%d%d",&row,&col);
    for(i=0;i<row;i++)
    {
    scanf("%s",a+i);
     
    }
    r=row; c=col;
     
     
     
     
     
     
     
    int flag=0;
    while(r!=0||c!=0)
    { //printf("%d %d\n",(r),(c));
    flag=0;
    if(r>c)
    {
    r--;
    flag=function();
    if(flag==1) break;
    }
    else if(r<c)
    {
    c=c-1;
    flag=function();
    if(flag==1) break;
    }
    else	if(r==c)
    { r=r-1;
    flag=function();
    if(flag==1) break;
    r=r+1; c-=1;
    flag=function();
    if(flag==1) break;
    r--;
    flag=function(); if(flag==1) break;
    }
     
    } printf("%d\n",(r)*(c));
    } return 0;
    } 
