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

class Dating {
public:
	string dates(string circle, int k) {
		int m = 0, f = 0;
		for(int i = 0;i<circle.length();i++)
			m += bool(isupper(circle[i])), f += bool(islower(circle[i]));

		int idx=  0;
		string ret = "";
		while(m && f)
		{
			int tmp = k-1;
			while(tmp || circle[idx] == '-')
			{
				if(circle[idx] != '-')
					tmp--;
                idx++;
                idx%=circle.length();
			}
			int nearest = -1;
			for(int i = 0;i<circle.length();i++)
			{
				if( (isupper(circle[i]) && islower(circle[idx])) || (isupper(circle[idx]) && islower(circle[i])) )
					if(nearest == -1 || circle[nearest] > circle[i])
						nearest = i;
			}
//			cout<<circle[idx]<<" "<<circle[nearest]<<endl;
			ret += string(1, circle[idx])+string(1, circle[nearest])+" ";
			circle[idx] = circle[nearest] = '-';
			f--;
			m--;
		}
		return ret.substr(0, ret.length()-1);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	Dating *obj;
	string answer;
	obj = new Dating();
	clock_t startTime = clock();
	answer = obj->dates(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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

	string p0;
	int p1;
	string p2;

	{
	// ----- test 0 -----
	p0 = "abXCd";
	p1 = 2;
	p2 = "bC dX";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "abXCd";
	p1 = 8;
	p2 = "Xa dC";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "HGFhgfz";
	p1 = 1;
	p2 = "Hf Gg Fh";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
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
