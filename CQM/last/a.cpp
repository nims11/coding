#include <vector>
#include <list>
#include <map>
#include<cstring>
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
int bits(int i){
int ret = 0;
while(i){
	ret += (i&1);
	i>>=1;
}
return ret;
}
int foo(int mask, vector<string> &field){
	for(int i = 0;i<field[0].size();i++){
		int W = 0, S = 0;
		for(int j = 0;j<field.size();j++){
			W += (field[j][i] == 'W');
			S += (field[j][i] == 'S');
			if(W && S)
			return -1;
			if(mask & (1<<j))
				W = S = 0;
		}
	}
	int res = bits(mask);
	vector<int> bounds;
	for(int i = 0 ;i<16;i++)
        if(mask&(1<<i))
            bounds.push_back(i);
    bounds.push_back(field.size()-1);
	int tmp[16][2] = {0};
	for(int i = 0;i<(int)field[0].size();i++){
        int cur = 0;
        for(int j = 0;j<bounds.size();j++){
            while(cur<=bounds[j]){
                tmp[j][0] += (field[cur][i] == 'W');
                tmp[j][1] += (field[cur][i] == 'S');
                if(tmp[j][0] && tmp[j][1])
                {
                    res++;
                    for(int x = 0;x<16;x++)tmp[x][0] = tmp[x][1] = 0;
                    i--;
                    j = 100;
                    break;
                }
                cur++;
            }
        }
	}
	return res;
}
int bar(int mask, vector<string> &field){
	for(int i = 0;i<field.size();i++){
		int W = 0, S = 0;
		for(int j = 0;j<field[0].size();j++){
			W += (field[i][j] == 'W');
			S += (field[i][j] == 'S');
			if(W && S)
			return -1;
			if(mask & (1<<j))
				W = S = 0;
		}
	}
	int res = bits(mask);
	vector<int> bounds;
	for(int i = 0 ;i<16;i++)
        if(mask&(1<<i))
            bounds.push_back(i);
    bounds.push_back(field[0].size()-1);
	int tmp[16][2] = {0};
	for(int i = 0;i<(int)field.size();i++){
        int cur = 0;
        for(int j = 0;j<bounds.size();j++){
            while(cur<=bounds[j]){
                tmp[j][0] += (field[i][cur] == 'W');
                tmp[j][1] += (field[i][cur] == 'S');
                if(tmp[j][0] && tmp[j][1])
                {
                    res++;
                    for(int x = 0;x<16;x++)tmp[x][0] = tmp[x][1] = 0;
                    i--;
                    j = 100;
                    break;
                }
                cur++;
            }
        }
	}
	return res;
}
class WolvesAndSheep {
public:
    int getBestV(vector<string f){
        vector<bool>hasW(f[0].size(), false);
        vector<bool>hasS(f[0].size(), false);
        for(int i = 0;i<f.size();i++)
            for(int j = 0;j<f[i].size();j++)
            if(f[i][j] == 'S') hasS[j] = 1;
        else if(f[i][j] == 'W')hasW[j] = 1;

        int state = 0;
        int ret = 0;
        for(int i = 0;i<hasW.size();i++){
            if(hasW[i] && hasW[i] == hasS[i])
                return -1;
        }
        return ret;
    }
    bool isGood(vector<string> f){
        bool hasS = 0;
        bool hasW = 0;
        for(int i = 0;i<f.size();i++)
            for(int j = 0;j<f[i].size();j++)
            if(f[i][j] == 'S')hasS = 1;
        else if(f[i][j] == 'W')hasW = 1;

    return !hasS || !hasW;
    }
    int getBestV(vector<string f, vector<bool> isD){
        int ret = 0;
        int prev = 0;
        for(int i = 0;i<f[0].size();i++)
        {
            vector<string> tmp;
            int j;
            for(j = 0;j<f.size();j++){
                tmp.push_back(f[j].substr(prev, i-prev+1));
                if(isD[j]){
                    if(!isGood(tmp))break;
                    tmp.clear();
                }
            }
            if(j!=f.size() || !isGood(tmp)){
                prev = i;
                ret++;
            }
        }
        for(int i = 0;i<isD.size();i++)if(isD[i])ret++;
        return ret;
    }
	int getmin(vector <string> field) {
		int ret = 100000;
		for(int i = 0;i<(1<<field.size()-1);i++){
                vector<string> tmpf;
        int j;
        vector<bool> isD(field.size(), false);

		}
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
	WolvesAndSheep *obj;
	int answer;
	obj = new WolvesAndSheep();
	clock_t startTime = clock();
	answer = obj->getmin(p0);
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
	string t0[] = {"W.....W","WW.S.",".SSS.","SSS.S",".SS.S"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {".....",".....","....."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {".SS","...","S..","W.W"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"WWWSWWSSWWW","WWSWW.SSWWW","WS.WSWWWWS."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	string t0[] = {".W.S.W.W","W.W.S.W.",".S.S.W.W","S.S.S.W.",".S.W.W.S","S.S.W.W.",".W.W.W.S","W.W.S.S."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	string t0[] = {"W.SSWWSSSW.SS",".SSSSW.SSWWWW",".WWWWS.WSSWWS","SS.WSS..W.WWS","WSSS.SSWS.W.S","WSS.WS...WWWS","S.WW.S.SWWWSW","WSSSS.SSW...S","S.WWSW.WWSWSW",".WSSS.WWSWWWS","..SSSS.WWWSSS","SSWSWWS.W.SSW","S.WSWS..WSSS.","WS....W..WSS."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 24;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	string t0[] = {"WW..SS","WW..SS","......","......","SS..WW","SS..WW"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
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
