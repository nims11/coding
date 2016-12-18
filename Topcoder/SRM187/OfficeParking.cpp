#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<utility>
#include<map>
#include<set>
#include<algorithm>

#define CLASS OfficeParking
#define METHOD int spacesUsed(vector <string> events)

using namespace std;

class CLASS
{
    public:
    int foo(string &str)
    {
        int i=0;
        for(;str[i]!=' ';i++);
        if(str[i+1]=='a')return 1;
        else
        return -1;
    }
    METHOD
    {
        int bar = 0;
        int ans=0;
        for(int i=0;i<events.size();i++)
        {
            bar+=foo(events[i]);
            ans = max(ans,bar);
        }
        return ans;
    }
};

int main()
{
    CLASS test;
}
