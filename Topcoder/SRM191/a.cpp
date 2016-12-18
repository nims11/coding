#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<utility>
#include<map>
#include<set>
#include<algorithm>

#define CLASS VolumeGuess
#define METHOD int correctVolume(vector <string> queries, int numberOfBoxes, int ithBox)

using namespace std;

class CLASS
{
    public:

    METHOD
    {
        set<int> foo[10];
        set<int>::iterator it;
        for(int i=0;i<queries.size();i++)
        {
            int b1=0,b2=0,c=0;
            int j=0;
            while(queries[i][j]!=',')
            {
                b1=b1*10+queries[i][j]-'0';
                j++;
            }
            j++;
            while(queries[i][j]!=',')
            {
                b2=b2*10+queries[i][j]-'0';
                j++;
            }
            j++;
            while(j<queries[i].length())
            {
                c=c*10+queries[i][j]-'0';
                j++;
            }
            if(foo[b1].find(c)!=foo[b1].end())
            {
                if(b1==ithBox)return c;
                for(int k=1;k<=numberOfBoxes;k++)
                {
                    if(k!=b1)
                    {
                        it=foo[k].find(c);
                        if(it!=foo[k].end())
                        {
                            foo[k].erase(it);
                        }
                    }
                }
            }else if(foo[b2].find(c)!=foo[b2].end())
            {
                if(b2==ithBox)return c;
                for(int k=1;k<=numberOfBoxes;k++)
                {
                    if(k!=b2)
                    {
                        it=foo[k].find(c);
                        if(it!=foo[k].end())
                        {
                            foo[k].erase(it);
                        }
                    }
                }
            }else
            {
                foo[b1].insert(c);
                foo[b2].insert(c);
            }
        }
    }
};

int main()
{
    CLASS test;
}
