#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  while(n!=0)
  {
    //index_value
    int *pos_num=new int[n+1];
    int *num_pos=new int[n+1];
    for(int i=1;i<=n;i++)
    {
      cin>>pos_num[i];
      num_pos[pos_num[i]]=i;
    }
    bool flag=true;
    for(int i=2;i<=n;i++)
    {
      if(num_pos[i]>num_pos[i-1])
	continue;
      for(int j=num_pos[i]+1;j<num_pos[i-1];j++)
      {
	if(pos_num[j]>i)
	{
	  flag=false;
	  break;
	}
      }
    }
    
    if(flag)
      cout<<"yes\n";
    else
      cout<<"no\n";
    
    
    delete [] pos_num;
    delete [] num_pos;
    cin>>n;
  }
  return 0;
}