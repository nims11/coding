#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int N,S,p,count=0;
        cin>>N>>S>>p;
        for(int j=0;j<N;j++)
        {
            int x;
            cin>>x;

            int i=x/3;
            int k=x%3;
            switch(k)
            {
                case 0: if(i<p){
                    if(i+1==p && S!=0)
                    {
                        if(i-1>0){
                        count++;S--;}
                    }
                }else count++;break;

                case 1: if(i+1>=p)count++;break;
                case 2: if(i+1<p){
                    if(i+2==p && S!=0)
                    {
                        count++;S--;
                    }
                }else count++;break;
            }
        }
        cout<<"Case #"<<z<<": "<<count<<endl;
    }
    return 0;
}
