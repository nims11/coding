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


class GooseTattarrattatDiv1 {
public:
	int getmin(string S) {
		int cnt[26] = {0};
//		S = "aaabbbcxyyopqrorrqoxyxcbaaddd";
		for(int i = 0; i<S.length(); i++)
            cnt[S[i]-'a']++;
        int id[26] = {0};
        int sum[27] = {0}, maxi[27] = {0};
        int idc = 0;
        for(int i = 0; i<S.length()/2; i++)
        {
            int x1 = S[i]-'a', x2 = S[S.length()-i-1]-'a';
            if(id[x1] == 0 && id[x2] == 0)
            {
                ++idc;
                id[x1] = idc;
                id[x2] = idc;

            }else if(id[x1] == 0)
            {
                id[x1] = id[x2];
            }else if(id[x2] == 0)
            {
                id[x2] = id[x1];
            }else if(id[x1] != id[x2])
            {
                int fin = min(id[x1], id[x2]), tar = max(id[x1], id[x2]);
                for(int j = 0; j<26; j++)
                    if(id[j] == tar)
                        id[j] = fin;
            }
        }
        for(int i = 0; i<26; i++)
            sum[id[i]] += cnt[i], maxi[id[i]] = max(maxi[id[i]], cnt[i]);
        int ret = 0;
        for(int i = 0; i<26; i++)
        {
            ret += sum[i]-maxi[i];
        }
        return ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	GooseTattarrattatDiv1 *obj;
	int answer;
	obj = new GooseTattarrattatDiv1();
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

	string p0;
	int p1;

	{
	// ----- test 0 -----
	p0 = "geese";
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "tattarrattat";
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "xyyzzzxxx";
	p1 = 2;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag";
	p1 = 11;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = "abaabb";
	p1 = 3;
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