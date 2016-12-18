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

struct Edge{
    int id;
    int u, v;
    Edge(int iid, int uu, int vv):id(iid),u(uu),v(vv){}
};
void print_set(long long x)
{
    for(int i=0;i<=51;i++)
        if(x&(1LL<<i))
        cout<<i<<" ";
    cout<<endl;
}
class TurnOnLamps {
vector<Edge> adj[52];
string state, imp;
public:
    long long get_path(int u, int v)
    {
        int visited[52] = {0};
        queue<pair<int, long long> > BFS;
        BFS.push(make_pair(u, 0));
        visited[u] = 1;
        while(!BFS.empty())
        {
            pair<int, long long> tmp = BFS.front();
            BFS.pop();
            if(tmp.first == v)
                return tmp.second;
            int x = tmp.first;
            long long mask = tmp.second;

            for(int i=0;i<adj[x].size();i++)
            {
                int y = (adj[x][i].u != x)?adj[x][i].u:adj[x][i].v;
                if(!visited[y] && !(imp[adj[x][i].id] == '1' && state[adj[x][i].id] == '1'))
                {
                    visited[y] = 1;
                    BFS.push(make_pair(y, (imp[adj[x][i].id] == '1')?(mask|(1LL<<adj[x][i].id)):mask));
                }
            }
        }
        return 0;
    }
	int minimize(vector <int> roads, string initState, string isImportant) {
	    state = initState;
	    imp = isImportant;
		int n = roads.size()+1;
		for(int i=0;i<roads.size();i++)
        {
            Edge tmp(i, i+1, roads[i]);
            adj[i+1].push_back(tmp);
            adj[roads[i]].push_back(tmp);
        }

        int tot = 0;
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<initState.size();i++)
            tot += (initState[i] == '0' && isImportant[i] == '1');
        while(cnt<tot)
        {
            int x = 0;
            long long mask;
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                {
                    long long mask2 = get_path(i, j);
                    if(__builtin_popcountll(mask2) > x)
                    {
//                        if(n == 50)
//                        cout<<i<<" "<<j<<" "<<__builtin_popcountll(mask2)<<endl;
                        x = __builtin_popcountll(mask2), mask = mask2;
                    }
                }
            ans++;
            cnt += x;
            for(int i=0;i<n;i++)
            {
                if(mask&(1LL<<i))
                    state[i] = '1';
            }
        }
        return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, string p1, string p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "\"" << p1 << "\"" << "," << "\"" << p2 << "\"";
	cout << "]" << endl;
	TurnOnLamps *obj;
	int answer;
	obj = new TurnOnLamps();
	clock_t startTime = clock();
	answer = obj->minimize(p0, p1, p2);
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

	vector <int> p0;
	string p1;
	string p2;
	int p3;

	{
	// ----- test 0 -----
	int t0[] = {0,0,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "0001";
	p2 = "0111";
	p3 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {0,0,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "0000";
	p2 = "0111";
	p3 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {0,0,1,1,4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "000100";
	p2 = "111111";
	p3 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {0,0,1,1,4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "100100";
	p2 = "011101";
	p3 = 2;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	int t0[] = {0,0,2,2,3,1,6,3,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "010001110";
	p2 = "000110100";
	p3 = 1;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	int t0[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "0000000000010000000000000010000010100000000000000";
	p2 = "1010111111111011011111000110111111111111111110111";
	p3 = 14;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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