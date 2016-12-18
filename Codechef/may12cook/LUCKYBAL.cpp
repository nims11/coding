#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<string,bool> dp;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        vector<int> cnt7,cnt4;
        cnt7.push_back(0);cnt4.push_back(0);
        for(int i=0;i<str.length();i++)
        {
            int s=0,f=0;
            if(str[i]=='7')s++;
            else f++;
            cnt4.push_back(f+cnt4[cnt4.size()-1]);
            cnt7.push_back(s+cnt7[cnt7.size()-1]);
        }
        long long unsigned count=0;
        for(int i=0;i<str.length();i++)
        {
            for(int j=i;j<str.length();j++)
            {
                string sub;
                if(j-i+1<=10){
                sub=str.substr(i,j-i+1);
                map<string,bool>::iterator it=dp.find(sub);
                if(it!=dp.end())
                {
                    it->second?count++:count+=0;
                    continue;
                }
                dp[sub]=false;}
                for(int k=i;k<=j;k++)
                {
                    if(cnt4[k]-cnt4[i]==cnt7[j+1]-cnt7[k])
                    {
//                        cout<<sub<<endl;
                        if(j-i+1<=10)
                        dp[sub]=true;
                        count++;
                        break;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
}
