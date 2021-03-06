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

int dx[] = {-1, -1, 1, 1, 0, 0};
int dy[] = {0, 1, 0, -1, 1, -1};
class HexagonalBoard {
public:
    int dfs(vector<string> &board, int idx, int idy, vector< vector<int> > &colors)
    {
//        cout<<idx<<" "<<idy<<endl;
        int cur = 1;
        set<int> foo;
        for(int i = 0; i<6; i++)
        {
            int xx = idx + dx[i], yy = idy + dy[i];
            if(xx >=0 && xx < board.size() && yy >=0 && yy < board[idx].size())
            {
                if(colors[xx][yy] != -1)
                    foo.insert(colors[xx][yy]);
            }
        }
        while(foo.find(cur) != foo.end())
            cur++;
        colors[idx][idy] = cur;
        int ret = cur;
        for(int i = 0; i<6; i++)
        {
            int xx = idx + dx[i], yy = idy + dy[i];
            if(xx >=0 && xx < board.size() && yy >=0 && yy < board[idx].size())
            {
                if(colors[xx][yy] == -1 && board[xx][yy] == 'X')
                    ret = max(ret, dfs(board, xx, yy, colors));
            }
        }
        return ret;
    }
	int minColors(vector <string> board) {
		int max_deg = 0;
		vector< vector<int> > col;
		for(int i = 0; i<board.size(); i++)
            col.push_back(vector<int> (board[0].size(), -1));
        for(int i = 0; i<board.size(); i++)
            for(int j = 0; j<board[i].size(); j++)
        {
            if(board[i][j] == 'X' && col[i][j] == -1)
                {
                    max_deg = max(max_deg, dfs(board, i, j, col));
                }
        }
		return max_deg;
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
	HexagonalBoard *obj;
	int answer;
	obj = new HexagonalBoard();
	clock_t startTime = clock();
	answer = obj->minColors(p0);
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
	string t0[] = {"---","---","---"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"-X--","---X","----","-X--"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"XXXX","---X","---X","---X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"XX-XX--","-XX-XXX","X-XX--X","X--X-X-","XX-X-XX","-X-XX-X","-XX-XX-"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
