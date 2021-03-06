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


class SpiralNumbers {
public:
	string getPosition(int N) {
	    if(N == 1)
            return "(0,0)";
		int st = 0, end = 100000000;
		while(st < end){
            int x = (st + end)/2;
            long long tot = 4LL*x*(x+1) + 1;
            if(tot >= N)
                end = x;
            else
                st = x+1;
		}
		int x = end; int idx = N-(4*x*(x-1)+1)-1;
//		cout<<x<<" "<<idx<<endl;
		int r = x-1-idx, c = x;
		int n = 2*x+1;
		if(r < x-n+1)
        {
            c = x-((x-n+1)-r);
            r = x-n+1;
            if(c < x-n+1)
            {
                r = x-n+1 + (x-n+1-c);
                c = x-n+1;
                if(r > x)
                {
                    c = x-n+1+(r-x);
                    r = x;
                }
            }
        }
        stringstream ss;
        ss<<'('<<-r<<','<<c<<')';
        string ret;
        ss>>ret;
        return ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	SpiralNumbers *obj;
	string answer;
	obj = new SpiralNumbers();
	clock_t startTime = clock();
	answer = obj->getPosition(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	string p1;

	{
	// ----- test 0 -----
	p0 = 2;
	p1 = "(0,1)";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 3;
	p1 = "(1,1)";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 7;
	p1 = "(-1,-1)";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 17;
	p1 = "(2,-2)";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 24;
	p1 = "(-2,1)";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	p0 = 830;
	p1 = "(-14,3)";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	p0 = 765409;
	p1 = "(-437,221)";
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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
