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

inline double dist(int x1, int y1, int x2, int y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
inline double point_dist(int x1, int y1, int xl1, int yl1, int xl2, int yl2){
	int A = yl2-yl1, B = xl1-xl2, C = xl2*yl1-xl1*yl2;
	return abs(A*x1+B*y1+C)/sqrt(A*A+B*B);
}
class PolyMove {
public:
	double addedArea(vector <int> x, vector <int> y) {
		int n = x.size();
		double b[n], h[n], inc[n], area[n];
		for(int i = 0;i<x.size(); i++){
			int pre = (i-1+n)%n, nxt = (i+1)%n;
			b[i] = dist(x[pre], y[pre], x[nxt], y[nxt]);
			h[i] = point_dist(x[i], y[i], x[pre], y[pre], x[nxt], y[nxt]);
			area[i] = b[i]*h[i]/2;
			inc[i] = b[i]*(h[i]+1)/2 - area[i];
		}
		double dp[n];
		dp[0] = inc[0];
		for(int i = 1;i<n-1;i++){
			dp[i] = dp[i-1];
			if(i != 1) dp[i] = max(dp[i], dp[i-2]+inc[i]);
			else dp[i] = max(dp[i], inc[i]);
		}
		cout<<endl;
		double res = dp[n-2];
		dp[0] = 0;
		for(int i = 1;i<n;i++){
			dp[i] = dp[i-1];
			if(i != 1) dp[i] = max(dp[i], dp[i-2]+inc[i]);
			else dp[i] = max(dp[i], inc[i]);
		}
		return max(res, dp[n-1]);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	PolyMove *obj;
	double answer;
	obj = new PolyMove();
	clock_t startTime = clock();
	answer = obj->addedArea(p0, p1);
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
		res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	
	vector <int> p0;
	vector <int> p1;
	double p2;
	
	{
	// ----- test 0 -----
	int t0[] = {0,1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,1,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,1,1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1.4142135623730951;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
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
