#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<utility>
#include<map>
#include<set>
#include<algorithm>

#define CLASS DNASingleMatcher
#define METHOD int longestMatch(string seq1, string seq2)

using namespace std;

class CLASS
{
    public:

    METHOD
    {
        int dp[seq1.size()+1][seq2.size()+1];
        for(int i=0;i<=seq1.size();i++)
            dp[i][0]=0;
        for(int i=0;i<=seq2.size();i++)
            dp[0][i]=0;
        int maax=0;
        for(int i=1;i<=seq1.size();i++)
        {
            for(int j=1;j<=seq2.size();j++)
            {
                if(seq1[i-1]==seq2[j-1])
                    {dp[i][j] = dp[i-1][j-1]+1;maax = max(maax, dp[i][j]);}
                else
                    dp[i][j] = 0;
            }
        }
    }
};

int main()
{
    CLASS test;
}
