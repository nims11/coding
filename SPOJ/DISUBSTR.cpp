//GQ
/*
    Nimesh Ghelani (nims11)
    the problem is to find number of distinct substrings of a given string.
    A naive approach will lead to TLE.
    Suffix array comes into play.
    Suffix array is an array of all the suffixes of the string arranged lexicographically.
    calculate the longest common prefix of each element of array with the previous element. lcp[0]=0
    A SUBSTRING OF THE STRING IS A PREFIX OF SOME SUFFIX OF THE STRING.
    P[i]=length of ith SUFFIX - lcp[i]
    sum of all P[i] is the required answer.
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",&a)

#define FOR(i,n) for(int i=0;i<n;i++)

#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;
int main()
{
    in_T
    {
        string str;
        cin>>str;
        vector <string> suffix;
        for(int i=1;i<=str.length();i++)
        {
            suffix.push_back(str.substr(i-1));
        }
        sort(suffix.begin(),suffix.end());
        vector <int> lcp(suffix.size());
        lcp[0]=0;
        long long unsigned ans=suffix[0].length();
        for(int i=1;i<suffix.size();i++)
        {
            int lt=MIN(suffix[i].length(),suffix[i-1].length());
            int j;
            for(j=0;j<lt;j++)
            {
                if(suffix[i][j]!=suffix[i-1][j])break;
            }
            lcp[i]=j;
            ans+=suffix[i].length()-lcp[i];
        }
        cout<<ans<<endl;
    }
}
