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


class DoubleOrOneEasy {
public:
	int minimalSteps(int a, int b, int newA, int newB) {
		if(a > newA/2 || b > newB/2 || (newA%2) != (newB%2)){
            int res1 = newA - a;
            int res2 = newB - b;
            if(res1 != res2 || res1 < 0) return -1;
            return res1;
        }
        if(newA%2 == 0){
            int res1 = newA - a;
            int res2 = newB - b;
            int res = res1;
            if(res1 != res2)
                res = -1;
            int res3 = minimalSteps(a, b, newA/2, newB/2);
            if(res == -1){
                if(res3 != -1)
                    res = res3+1;
            }
            else if(res3 != -1)
                res = min(res, res3+1);
            return res;
        }else{
            int res = minimalSteps(a, b, newA-1, newB-1);
            if(res != -1)
                res++;
            return res;
        }
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	DoubleOrOneEasy *obj;
	int answer;
	obj = new DoubleOrOneEasy();
	clock_t startTime = clock();
	answer = obj->minimalSteps(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	int p3;
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 100;
	p1 = 1000;
	p2 = 101;
	p3 = 1001;
	p4 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 100;
	p1 = 1000;
	p2 = 202;
	p3 = 2002;
	p4 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 2;
	p1 = 2;
	p2 = 1;
	p3 = 1;
	p4 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1;
	p1 = 111111111;
	p2 = 8;
	p3 = 888888888;
	p4 = 3;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1;
	p1 = 111111111;
	p2 = 9;
	p3 = 999999999;
	p4 = -1;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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
