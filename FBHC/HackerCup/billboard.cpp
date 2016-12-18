#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
bool possible(int w,int h, vector <string> words,int size)
{
    w+=size;
    int lines=1,max_lines=h/size,curr_len=0;
    int word_num=words.size();
    for(int i=0;i<word_num;i++)
    {
        int len=words[i].length();
        if((len+1)*size>w)
        return false;
        curr_len+=(len+1)*size;
        if(curr_len>w)
        {
            lines++;
            curr_len=(len+1)*size;
        }
//        if(size==8)
//        cout<<lines<<" "<<curr_len<<endl;
        if(lines>max_lines)
        return false;
    }
    return true;
}
int getMax(int w,int h,vector <string> words,int min, int max)
{
    int ans=0;
    while(min<=max)
    {
        int mid=(min+max)/2;
        if(possible(w,h,words,mid))
        {
            ans=mid;
            min=mid+1;
        }else
        {
            max=mid-1;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int w,h;string str;
        cin>>w>>h;
        getline(cin,str);
        //cout<<"*"<<str<<endl;
        stringstream ss(str,stringstream::in | stringstream::out);
        vector <string> words;
        while(ss>>str)
        {
            words.push_back(str);
        }
        cout<<"Case #"<<z<<": "<<getMax(w,h,words,1,h)<<endl;
    }
    return 0;
}
