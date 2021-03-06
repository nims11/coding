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


bool cycle(int idx, vector<vector<int>> &neigh, vector<int> &state){
    state[idx] = -1;
    bool flag = false;
    for(int v: neigh[idx]){
        if(state[v] == -1)
            return true;
        if(state[v] == 0){
            flag |= cycle(v, neigh, state);
            if(flag)
                return true;
        }
    }
    state[idx] = 1;
    return false;
}
class AlphabetOrderDiv1 {
    public:
        string isOrdered(vector <string> words) {
            vector<vector<int>> neigh(26);
            vector<int> state(26);
            for(int i = 0;i<26;i++)
                state[i] = 0;
            for(string word: words){
                for(int i = 1;i<word.size();i++){
                    if(word[i-1] != word[i])
                        neigh[word[i-1]-'a'].push_back(word[i]-'a');
                }
            }
            bool flag = false;
            for(int i = 0;i<26;i++){
                if(!state[i]){
                    if(cycle(i, neigh, state))
                        return "Impossible";
                }
            }
            return "Possible";
        }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    AlphabetOrderDiv1 *obj;
    string answer;
    obj = new AlphabetOrderDiv1();
    clock_t startTime = clock();
    answer = obj->isOrdered(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p1 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
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
    string p1;

    {
        // ----- test 0 -----
        string t0[] = {"single","round","match"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Possible";
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"topcoder","topcoder"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Impossible";
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"algorithm","contest"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Impossible";
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"pink","floyd"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Possible";
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"gimnasia","y","esgrima","la","plata"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Impossible";
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
