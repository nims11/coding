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

pair<int, int> conv(string str)
{
	int r = str[0]-'A'+1;
	int c = 0;
	for(int i = 1;i<str.length();i++)
		c = c*10 + str[i]-'0';
	return make_pair(r, c);
}
struct node;
struct node *super_source, *super_dest;
struct node *grid[27][27];
struct node{
    map<node*, int> edges;
}nodes[1000000];
int cnt = 0;
node* nxtNode(){
    nodes[cnt].edges.clear();
    return &nodes[cnt++];
}
int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};
int find_path(node *src, node *dest)
{
    int ret = -1;
    map<node*, node*> backlink;
    queue<node*> BFS;
    BFS.push(src);
    backlink[src] = 0;
    while(!BFS.empty()){
        node *x = BFS.front();
        BFS.pop();
        if(x == dest){
            ret = 1000;
            while(backlink[x] != 0){
                node *pre = backlink[x];
                ret = min(ret, pre->edges[x]);
                x = pre;
            }
            x = dest;
            while(backlink[x] != 0){
                node *pre = backlink[x];
                pre->edges[x] -= ret;
                x->edges[pre] += ret;
                x = pre;
            }
            return ret;
        }
        for(map<node*, int>::iterator it = x->edges.begin(); it != x->edges.end(); it++)
            if(backlink.find(it->first) == backlink.end() && it->second)
                backlink[it->first] = x, BFS.push(it->first);
    }
    return ret;
}
int max_flow(node *src, node *sink)
{
    int ret = 0, path_capacity;
    while((path_capacity = find_path(src, sink)) != -1)
        ret += path_capacity;
    return ret;
}
class Knights {
public:
	int makeFriendly(int N, vector <string> pos) {
	    cnt = 0;
	    super_source = nxtNode();
	    super_dest = nxtNode();

		for(int i = 0; i<27;i++)
            for(int j = 0; j<27; j++)
                grid[i][j] = NULL;

		for(int i = 0;i<pos.size();i++){
			stringstream ss(pos[i]);
			string x;
			while(ss>>x){
                pair<int, int> y = conv(x);
                grid[y.first][y.second] = nxtNode();
			}
		}
		for(int i = 1;i<=N;i++)
            for(int j = 1;j<=N;j++)
                if(grid[i][j]){
                    if((i%2) ^ (j%2))
                        super_source->edges[grid[i][j]] = 1, grid[i][j]->edges[super_dest] = 0;
                    else
                        grid[i][j]->edges[super_dest] = 1, super_dest->edges[grid[i][j]] = 0;
                    for(int k = 0;k<8;k++){
                        int x = i+dx[k], y = j+dy[k];
                        if(x>=1 && x<=N && y>=1 && y<=N && grid[x][y])
                            grid[i][j]->edges[grid[x][y]] = ((i%2) ^ (j%2));
                    }
                }
        return max_flow(super_source, super_dest);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Knights *obj;
	int answer;
	obj = new Knights();
	clock_t startTime = clock();
	answer = obj->makeFriendly(p0, p1);
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

	int p0;
	vector <string> p1;
	int p2;

	{
	// ----- test 0 -----
	p0 = 5;
	string t1[] = {"A2 A4","B1 B5","D1 D5 E2 E4 C3"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 2;
	string t1[] = {"A1 A2 B1 B2"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 6;
	string t1[] = {"A1 A5 B3 C1 C5 D2 D4 E6 F5"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 8;
	string t1[] = {"A2 A4 A5 A6 B2 B5 B6 B7 B8","C3 C8 D1 D2 D3 D4 D5 D6 D8","E1 E3 E8 F1 F2 F8 G3 G5 H4 H7 H8"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 12;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 9;
	string t1[] = {"A3 A4 A5 A7 A8 B6 B8 C3 C6","C7 C9 D4 D5 D8 D9 E1 E3 E7","F2 G2 G6 G7 H2 H9 I2 I4 I5","I6 I7 I8 I9"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 10;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
