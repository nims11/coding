#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
void getInput()
{
  long t=0;long count=0;
  int i,j;
  int limit,sum;
  long size=1399994;
    char stream[1399994];
    while(!cin.eof())
    {
        cin.read(stream,1399994);
        int size=strlen(stream);
        for(int i=0;i<size;i++)
        {
            if(stream[i]=='\n')
            {
		limit=sqrt(t);
    sum=1;
    int d=t%2;
    for(j=2+d;j<=limit;j+=d+1)
    {   if(t%j==0)
      {
	int d=t/j;
	if(d==j)
	  sum+=j;
	else
	  sum+=j+d;
      }}
      cout<<sum<<endl;
                t=0;
                continue;
            }else
            t=t*10+stream[i]-'0';
        }
    }
}
int main()
{
  long t,n;
  int i;
  int limit,sum;
  cin>>t;
  cin.ignore(1);
  getInput();
//   long *num=new long[t+1];
//   while(t--)
//   {
//     cin>>n;
//     limit=sqrt(n);
//     sum=1;
//     for(i=2;i<=limit;i++)
//       if(n%i==0)
//       {
// 	if(n==i*i)
// 	  sum+=i;
// 	else
// 	  sum+=i+n/i;
//       }
//       cout<<sum<<endl;
//   }
  return 0;
}
