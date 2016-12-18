#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<utility>
#include<map>
#include<set>
#include<algorithm>

#define CLASS SafeRemoval
#define METHOD int removeThem(vector <int> seq, int k)
const int INF = 1<<30;

using namespace std;

class CLASS
{
    public:
    METHOD
    {
        pair<int, long long> dp[51][51][4];
        /*
        dp[i][j][m].first holds the minimum sum whose mod is m considering j numbers with the ith number in the sequence being the jth selected number.
        the final answer will be sum - min(dp[i][k-1][m]), m!=sum%4

        dp[i][j][m].second holds the long integer whose bits specify the elements selected in order to get the result stored in dp[i][j][m].first
        */
        int size = seq.size();
        //init dp
        for(int i = 0; i<size ; i++)
            for(int j = 0; j<k ; j++)
                for(int m = 0; m<4; m++)
                    dp[i][j][m].first = INF;

        //init dp for k=0
        for(int i = 0; i<size ;i++)
            dp[i][0][seq[i]%4].first = seq[i], dp[i][0][seq[i]%4].second = ((long long)1<<i);

        int sum = 0;
        for(int i = 0; i<size; i++)
            sum += seq[i];

        int avoid = sum%4;  //might be the problem
        //the avoid variable holds the modulus of the sum of the excluded number that should never be reached in course of selecting those numbers

        for(int i = 1; i<k ; i++)   //selecting the ith element
            for(int j = 0 ; j<size; j++)    //which is the jth element of the original sequence
                for(int a = 0; a<size; a++) //in the case where the previously selected element was the ath element in the sequence
                    if(a != j)              //same number cannot be selected twice
                        for(int b = 0; b<4; b++)    //considering the four modulus cases
/*might be the problem*/    if(b != avoid && !(dp[a][i-1][b].second & ((long long)1<<j)))   //the modulus case considered is not the one to avoid && the jth element has not been already visited for that case
                            {
                                int tmp = dp[a][i-1][b].first + seq[j];
                                dp[j][i][tmp%4].first = min(tmp, dp[j][i][tmp%4].first);
                                if(tmp == dp[j][i][tmp%4].first)
                                    dp[j][i][tmp%4].second = dp[a][i-1][b].second | ((long long)1<<a);
                            }
        int ans = INF;
        //getting the minimum answer
        for(int i=0; i<size; i++)
            for(int j = 0; j<4; j++)
                if(j!=avoid)
                    ans = min(ans, dp[i][k-1][j].first);

        return (ans==INF)? -1: sum-ans;
    }
};
static const int arr[] = {138, 575, 731, 253, 107, 108, 220, 337, 884, 804, 579, 615,
675, 263, 312, 929, 188, 81, 624, 115, 61, 412, 64, 971, 46, 730, 694, 32, 632, 678, 642, 903, 161, 258, 832, 762, 889, 134, 543, 914, 560, 282, 17, 789, 245, 901, 869, 913, 535};
int k = 32;
int main()
{
    cout<<(1==1?" ":8);
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    CLASS test;
    cout<<test.removeThem(vec, k);
}
