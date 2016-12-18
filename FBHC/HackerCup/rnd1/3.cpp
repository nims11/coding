#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
void calcAns(string str,long buff[],int m,int m_len)
{
    int size=str.length();
    int count=size-1;
    buff[size]=1;
//    if(atoi(str.substr(count,1).c_str())<=m)
//    buff[count]=1;
//    else{buff[0]=0;return;}

    for(int i=count;i>=0;i--)
    {
        buff[i]=0;
        if(str[i]=='0')
        continue;
        for(int j=0;j<m_len && i+j<size;j++)
        {
            //cout<<atoi(str.substr(i,1+j).c_str())<<"*";
            if(atoi(str.substr(i,1+j).c_str())<=m)
            {
                buff[i]+=buff[i+j+1];
                buff[i]=buff[i]%4207849484;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int z=1;z<=n;z++)
    {
        string m;
        cin>>m;
        int m_len=m.length(),m_int=atoi(m.c_str());
        long buff[1003];
        string str;
        cin>>str;
        int count=str.length();
        calcAns(str,buff,m_int,m_len);
        cout<<"Case #"<<z<<": "<<buff[0]<<endl;
    }
    return 0;
}
//#include<iostream>
//using namespace std;
//int main()
//{
//  char ch;
//  cin.get(ch);
//  while(ch!='0')
//  {
//    long b[5003];
//    char c[5003];
//    int count=0;
//    while(ch!='\n')
//    {
//      c[count++]=ch;
//      cin.get(ch);
//    }
//    b[count]=b[count+1]=1;
//    c[count]=c[count+1]=1;
//    for(int i=count-1;i>=0;i--)
//    {
//      if(c[i]=='0')
//      {
//	b[i]=b[i+1];
//	i--;b[i]=b[i+1];
//	continue;
//      }
//      b[i]=b[i+1];
//      if(((c[i]=='1' && c[i+1]<='9' && c[i+1]>='0') || (c[i]=='2' && c[i+1]<='6' && c[i+1]>='0')) && c[i+2]!='0')
//	b[i]+=b[i+2];
//    }
//    cout<<b[0]<<endl;
//    cin.get(ch);
//  }
//  return 0;
//}
//
