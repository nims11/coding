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
bool visited[50][50];
int mod = 1000000007;
int R, C;
int POW(long long r, long long n)
{
    int ans = 1;
    while(n>0)
    {
        if(n&1)
            ans = (ans*r)%mod;
        n >>= 1;
        r = (r*r)%mod;
    }
    return ans;
}
long long fact[2501], inv[2501];
long long Combi(int n, int r)
{
    return (fact[n]*((inv[r]*inv[n-r])%mod))%mod;
}
int odd = 0, even = 0;
class GooseInZooDivOne {
public:
	void getans(int x, int y, int dist, vector<string> &field)
	{
		queue<pair<int, int> > BFS;
		visited[x][y] = 1;
		BFS.push(make_pair(x, y));
		int sz=  1;
		while(!BFS.empty())
		{
			pair<int, int> tmp = BFS.front();
			BFS.pop();
			int x = tmp.first, y = tmp.second;
			int l = y - dist, r = y + dist;
			for(int i=x;i>=0 && l<=r;i--,l++,r--)
			{
			    for(int j = max(0, l); j<= min(C-1, r); j++)
                {
                    if(field[i][j] == 'v' && !visited[i][j])
                    {
                        visited[i][j] = true;
                        sz++;
                        BFS.push(make_pair(i, j));
                    }
                }
			}
			l = 1 + y - dist, r = -1 + y + dist;
			for(int i=x+1;i<R && l<=r;i++,l++,r--)
			{
				for(int j = max(0, l); j<= min(C-1, r); j++)
                {
                    if(field[i][j] == 'v' && !visited[i][j])
                    {
                        visited[i][j] = true;
                        sz++;
                        BFS.push(make_pair(i, j));
                    }
                }
			}
		}
		if(sz%2)
            odd++;
        else
            even++;
	}
	int calc()
	{
	    if(!odd && !even)
            return 0;
	    if(odd)
            even += odd-1;
        return (POW(2, even)-1+mod)%mod;
	}
	int count(vector <string> field, int dist) {
	    fact[0] = 1;
	    for(int i=1;i<=2500;i++)
            fact[i] = (i*fact[i-1])%mod;
        for(int i=0;i<=2500;i++)
            inv[i] = POW(fact[i], mod-2);
        odd = even = 0;
		R = field.size();
		C = field[0].size();
		for(int i=0;i<field.size();i++)
            for(int j=0;j<field[i].size();j++)
                visited[i][j] = 0;
		for(int i=0;i<field.size();i++)
		{
			for(int j=0;j<field[i].size();j++)
			{
				if(field[i][j] == 'v' && !visited[i][j])
				{
					getans(i, j, dist, field);
				}
			}
		}
		return calc();
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	GooseInZooDivOne *obj;
	int answer;
	obj = new GooseInZooDivOne();
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

	vector <string> p0;
	int p1;
	int p2;

	{
	// ----- test 0 -----
	string t0[] = {"vvv"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"vvv"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"v.v..................v............................",".v......v..................v.....................v","..v.....v....v.........v...............v......v...",".........vvv...vv.v.........v.v..................v",".....v..........v......v..v...v.......v...........","...................vv...............v.v..v.v..v...",".v.vv.................v..............v............","..vv.......v...vv.v............vv.....v.....v.....","....v..........v....v........v.......v.v.v........",".v.......v.............v.v..........vv......v.....","....v.v.......v........v.....v.................v..","....v..v..v.v..............v.v.v....v..........v..","..........v...v...................v..............v","..v........v..........................v....v..v...","....................v..v.........vv........v......","..v......v...............................v.v......","..v.v..............v........v...............vv.vv.","...vv......v...............v.v..............v.....","............................v..v.............."
			"...v",".v.............v.......v..........................","......v...v........................v..............",".........v.....v..............vv..................","................v..v..v.........v....v.......v....","........v.....v.............v......v.v............","...........v....................v.v....v.v.v...v..","...........v......................v...v...........","..........vv...........v.v.....................v..",".....................v......v............v...v....",".....vv..........................vv.v.....v.v.....",".vv.......v...............v.......v..v.....v......","............v................v..........v....v....","................vv...v............................","................v...........v........v...v....v...","..v...v...v.............v...v........v....v..v....","......v..v.......v........v..v....vv..............","...........v..........v........v.v................","v.v......v................v....................v..",".v........v............................."
			"...v......","............................v...v.......v.........","........................vv.v..............v...vv..",".......................vv........v.............v..","...v.............v.........................v......","....v......vv...........................v.........","....vv....v................v...vv..............v..","..................................................","vv........v...v..v.....v..v..................v....",".........v..............v.vv.v.............v......",".......v.....v......v...............v.............","..v..................v................v....v......",".....v.....v.....................v.v......v......."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 898961330;
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
