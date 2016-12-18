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


class SwitchingGame {
public:
	int timeToWin(vector <string> states) {
		int n = states.size();
		int m = states[0].size();
		int lamps[m];
		for(int i = 0;i<m;i++)
			lamps[i] = 0;
		int last[n+1][m], next[n+1][m], final[n+1][m];
		for(int i = 0;i<m;i++)
			last[0][i] = next[0][i] = 0;
		for(int level = 1;level<=n;level++){
			string state = states[level-1];
			for(int lamp = 0;lamp<m;lamp++)
				if(state[lamp] == '-')last[level][lamp] = next[level][lamp] = 0;
				else if(state[lamp] == '+')last[level][lamp] = next[level][lamp] = 1;
				else if(state[lamp] == '?')last[level][lamp] = next[level][lamp] = -1;
		}
		
		for(int level = n;level>=1;level--){
			for(int lamp = 0;lamp<m;lamp++){
				if(last[level][lamp] == -1)
					last[level][lamp] = last[level+1][lamp];
			}
		}
		int res = 0;
		for(int level = 1; level<=n;level++){
			int toOn = 0, toOff = 0;
						
			for(int lamp = 0;lamp<m;lamp++)
	//			if(states[level-1][lamp] != '?')
				if(last[level-1][lamp] != last[level][lamp]){
					if(last[level][lamp] == 1)
						toOn = 1;
					else if(last[level][lamp] == 0)
						toOff = 1;
				}
/*			for(int lamp = 0;lamp<m;lamp++)
				if(states[level-1][lamp] == '?')
				if(last[level-1][lamp] != last[level][lamp]){
					if(last[level][lamp] == 1){
						if(!toOn)last[level][lamp] = 0;
					}
					else if(last[level][lamp] == 0){
						if(!toOff)last[level][lamp] = 1;
					}
				}*/
			res += toOn + toOff + 1;
			cout<<toOn+toOff<<endl;

		}
		return res;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	SwitchingGame *obj;
	int answer;
	obj = new SwitchingGame();
	clock_t startTime = clock();
	answer = obj->timeToWin(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"++--","--++"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"+-++","+-++"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"++","+?","?+","++"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"+","?","?","?","-"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"+?" "?+++","++?" "?+-","?++?" "?+","?-+-?" "?","?" "?+?++","++-?+?","?++?-+","?--+++","-?" "?-?+"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 20;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
