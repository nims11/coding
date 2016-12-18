#include<iostream>
#include<string>
using namespace std;
string permu[]={"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int count[8]={0};
        for(int i=0;i<str.size()-2;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(str[i]==permu[j][0] && str[i+1]==permu[j][1] && str[i+2]==permu[j][2])
                {
                    count[j]++;
                    break;
                }
            }
        }
        cout<<n<<" ";
        for(int i=0;i<8;i++)
        cout<<count[i]<<" ";
        cout<<endl;
    }
}
