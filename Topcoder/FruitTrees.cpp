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

int lastB[2001], lastC[2001];
map<int, int> foo[2001];
bool markB[2001], markC[2001];
class FruitTrees {
public:
	int maxDist(int apple, int kiwi, int grape) {
		int a, b, c;
		a = max(apple, max(kiwi, grape));
		c = min(apple, min(kiwi, grape));
		if(apple != a && apple != c)
			b = apple;
		else if(kiwi != a && kiwi != c)
			b = kiwi;
		else if(grape != a && grape != c)
			b = grape;

		int ans = 0;
		for(int i=0;i<a;i++)
        {
            if((a-i)%b == 0)
                lastB[i] = a;
            else
                lastB[i] = i + (a-i)/b;

            if((a-i)%c == 0)
                lastC[i] = a;
            else
                lastC[i] = i + (a-i)/c;
        }
		for(int i=0;i<a;i++)
        {
            if(markB[i])
                continue;
            for(int j=i;j<a;j+=i)
                markB[j] = true;
            int mini_i = min(i, a-i-1);
            for(int j=0;j<c;j++)
            {
                int mini = min(j, a-j-1);
                if(i<j)
                {
                    mini = min(mini, (j-i)%b);
                }else
                    mini = min(mini, (i-j));
                foo[i][j] = min(mini, mini_i);
            }
        }

	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	FruitTrees *obj;
	int answer;
	obj = new FruitTrees();
	clock_t startTime = clock();
	answer = obj->maxDist(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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

	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 5;
	p2 = 8;
	p3 = 0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 3;
	p2 = 6;
	p3 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 40;
	p1 = 30;
	p2 = 20;
	p3 = 5;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 899;
	p1 = 1073;
	p2 = 1147;
	p3 = 14;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 2000;
	p1 = 2000;
	p2 = 2000;
	p3 = 666;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
