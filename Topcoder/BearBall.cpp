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
int GCD(int a,int b){
    while(b){
        swap(a, b);
        b %= a;
    }
    return a;
}
int getans(vector<int> &x, vector<int> &y, int idx){
    int ans = 0;
    vector<pair<int, int> > dist(x.size());
    for(int i = 0;i<x.size();i++){
        dist[i].first = abs(x[i]-x[idx]) + abs(y[i]-y[idx]);
        dist[i].second = i;
    }
    sort(dist.begin(), dist.end());
    int distinc = -1;
    pair<int, int> xx = make_pair(-1, -1);

    map<pair<int, int>, int> foo[4];
    for(int i = 1;i<dist.size();i++){
        int _i = dist[i].second;
        int _x = x[_i] - x[idx];
        int _y = y[_i] - y[idx];

        if(_x == 0){
            if(_y < 0)
                _y *= -1;
        }else if(_y == 0){
            if(_x < 0)
                _x *= -1;
        }else if(_x < 0)
            _x *= -1, _y *= -1;
        int _gcd = GCD(abs(_x), abs(_y));
        pair<int, int> _m = make_pair(_x/_gcd, _y/_gcd);
        if(distinc == -1)
            xx = _m, distinc = 0;
        else if(xx != _m)
            distinc = 10;
    }
    for(int i = 1;i<dist.size();i++){
        int _i = dist[i].second;
        int _dir;
        int _x = x[_i] - x[idx];
        int _y = y[_i] - y[idx];
        if(_x > 0 && _y >= 0)
            _dir = 0;
        else if(_x <= 0 && _y > 0)
            _dir = 1;
        else if(_x < 0 && _y <= 0)
            _dir = 2;
        else _dir = 3;

        _x = abs(_x);
        _y = abs(_y);
        int _gcd = GCD(_x, _y);
        pair<int, int> _m = make_pair(_x/_gcd, _y/_gcd);
        if(foo[_dir].find(_m) == foo[_dir].end()){
            foo[_dir][_m] = 1;
            ans++;
        } else if(distinc == 10){
            ans += 2;
            foo[_dir][_m]++;
        }else{
            foo[_dir][_m]++;
            ans += foo[_dir][_m];
        }
    }
    return ans;
}

class BearBall {
public:
	int countThrows(vector <int> x, vector <int> y) {
        int res = 0;
		for(int i = 0;i<x.size();i++){
            res += getans(x, y, i);
        }
        return res;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
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
	BearBall *obj;
	int answer;
	obj = new BearBall();
	clock_t startTime = clock();
	answer = obj->countThrows(p0, p1);
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {1,4,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,10,7};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,0,0,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,1,2,0,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 22;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {5,7,9,11};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,3,2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 20;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {10,10,50,50,90,90};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {5,17,5,17,5,17};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 34;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {-100,-90,-80,-70,-85,-90,0,20};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-5,-8,-13,-21,-13,-13,-13,-69};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 68;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {-1,0,1,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,0,0,1,-1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(5, p0, p1, false, p2) && all_right;
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
