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
#include <cstring>

using namespace std;
long long dp[1<<18][18];

class PolygonTraversal {
public:
    int n;
    int st;
    bool cuts(int mask, int x, int y)
    {
        int a, b;
        if(x<y)
            a = x, b = y;
        else
            a = y, b = x;
        bool n1 = false, n2 = false;
        for(int i=0;i<n;i++)
        {
            if(mask & (1<<i)){
                if(a<i && i<b)
                    n1 = true;
                if(!(a<=i && i<=b))
                    n2 = true;

                if(n1 && n2)
                    return true;
            }
        }
        return false;
    }
    long long getans(int mask, int x)
    {
        if(dp[mask][x] != -1)
            return dp[mask][x];
        long long &ret = dp[mask][x];

        if(mask == (1<<n)-1)
            return ret = cuts(mask, st, x);

        ret = 0;
        for(int i=0;i<n;i++)
        {
            if(!(mask & (1<<i)))
                if(cuts(mask, x, i))
                    ret += getans(mask | (1<<i), i);
        }
        return ret;
    }
	long long count(int N, vector <int> points) {
	    n = N;
	    st = points[0]-1;
		memset(dp, -1, sizeof(dp));
		int mask = 0;
		for(int i=0;i<points.size();i++)
            mask |= 1<<(points[i]-1);
        return getans(mask, points[points.size()-1]-1);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	PolygonTraversal *obj;
	long long answer;
	obj = new PolygonTraversal();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
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
	vector <int> p1;
	long long p2;

	{
	// ----- test 0 -----
	p0 = 5;
	int t1[] = {1,3,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 6;
	int t1[] = {1,4,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 7;
	int t1[] = {2,4,7};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 7;
	int t1[] = {1,2,3,4,6,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 18;
	int t1[] = {1,7,18};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4374612736ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
