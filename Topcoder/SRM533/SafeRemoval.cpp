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
#define METHOD int removeThem(vector <int> seq1, int k)
const int INF = 1<<30;

using namespace std;

class CLASS
{
    public:
    vector<int> seq;
    int K;
    int visited[51];
    int avoid;
    int tmp;
    int getans(int sum, int k)
    {
//        cout<<sum<<" "<<k<<endl;
        if(k>0 && sum%4 == avoid)
            return -1;
        if(k == K)
            return 0;
        int ans = INF;
        for(int i=0 ; i<seq.size(); i++)
        {
            if(!visited[i])
            {
                visited[i] = 1;
                int tmp = getans(sum + seq[i], k+1);
                if(tmp != -1)
                    ans = min(ans, tmp+seq[i]);
                visited[i] = 0;
            }
        }
        if(ans != INF)
            return ans;
        return -1;
    }
    METHOD
    {
        K = k;
        for(int i =0 ;i<seq1.size(); i++)
            visited[i] = 0;
        seq = seq1;
        sort(seq.begin(), seq.end());
        int sum=0;
        for(int i=0; i<seq.size(); i++)
            sum += seq[i];
        avoid = sum%4;
        int ans = getans(0, 0);
        if(ans == -1)
            ans = sum+1;
        return sum - ans;
    }
};
static const int arr[] = {138, 575, 731, 253, 107, 108, 220, 337, 884, 804, 579, 615, 675, 263, 312, 929, 188, 81, 624, 115, 61, 412, 64, 971, 46, 730, 694, 32, 632, 678, 642, 903, 161, 258, 832, 762, 889, 134, 543, 914, 560, 282, 17, 789, 245, 901, 869, 913, 535};
int k = 32;
int main()
{
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    CLASS test;
    cout<<test.removeThem(vec, k);
}
