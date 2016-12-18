#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
int dp[10][10];
int f(int s, int l)
{
    if(s<0 || s>9)
        return 0;
    if(dp[s][l] != -1)
        return dp[s][l];
    int &ans = dp[s][l];
    ans = 0;
    for(int i = 0;i<10;i++)
        if(abs(i-s)>=2)
            ans += f(i, l-1);
    return ans;
}
int getJumpy(int n)
{
    if(n <10)
        return n;
    vector<int> digs;
    int n2 = n;
    while(n2)
    {
        digs.push_back(n2%10);
        n2/=10;
    }
    reverse(digs.begin(), digs.end());
    int ret = 0;
    for(int i = 1;i<digs.size();i++)
    for(int j = 1;j<10;j++)
        ret += f(j, i);

    for(int i = 1;i<digs[0];i++)
        ret += f(i, digs.size());
    for(int i = 1;i<digs.size();i++)
    {
        for(int j = 0;j<10;j++)
        {
            if(j>=digs[i] || abs(j-digs[i-1]) < 2)
                continue;
            ret += f(j, digs.size()-i);
        }
        if(abs(digs[i]-digs[i-1]) < 2)
            break;
        if(i == digs.size()-1)
            ret++;
    }
//    cout<<n<<" "<<ret<<endl;
    return ret;
}
class JumpyNum {
public:
	int howMany(int low, int high) {
	    for(int i = 0;i<10;i++)
            for(int j = 0;j<10;j++)
                dp[i][j] = -1;
        for(int i = 0;i<10;i++)
            dp[i][1] = 1;
		return getJumpy(high) - getJumpy(low-1);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	JumpyNum *obj;
	int answer;
	obj = new JumpyNum();
	clock_t startTime = clock();
	answer = obj->howMany(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;
	int p2;

	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 10;
	p2 = 9;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 9;
	p1 = 23;
	p2 = 9;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 2000000000;
	p1 = 2000000000;
	p2 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 8000;
	p1 = 20934;
	p2 = 3766;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!