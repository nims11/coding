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
#include <cstring>
using namespace std;

int adj[51][51];
int n, vis[51];
int fox[51];
vector<int> tmp[2];
int dfs(int idx, int par = -1, int left=-1){
    vis[idx] = 1;
    int ret = 0;
    for(int i = 1;i<=n;i++){
        if(!vis[i] && adj[idx][i]){
            if(fox[i] == 0 || left != -1)
                ret = max(ret, dfs(i, idx, 1));
            else
                ret = max(ret, dfs(i, idx));
        }
    }
    if(ret == -1){
        if(fox[idx])return ;
        else return -1;
    }else if(!fox[idx] && par != -1)return ret  + adj[idx][par];
    else return ret;
}
class FoxMeeting {
    public:
        int maxDistance(vector <int> A, vector <int> B, vector <int> L, vector <int> foxes) {
            memset(adj, 0, sizeof(adj));
            for(int i = 0;i<A.size();i++){
                adj[A[i]][B[i]] = adj[B[i]][A[i]] = L[i];
            }
            int res = 1e9;
            memset(fox, 0, sizeof(fox));
            for(int i = 0;i<foxes.size();i++)
                fox[foxes[i]]++;
            n = A.size()+1;
            for(int i = 1;i<=n;i++){
                memset(vis, 0, sizeof(vis));
                res = min(res, dfs(i)+(!fox[i]));
                cout<<i<<" "<<res<<endl;
            }
            return res;
        }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
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
    cout << "}" << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p2[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p3.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p3[i];
    }
    cout << "}";
    cout << "]" << endl;
    FoxMeeting *obj;
    int answer;
    obj = new FoxMeeting();
    clock_t startTime = clock();
    answer = obj->maxDistance(p0, p1, p2, p3);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p4 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p4;
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
    vector <int> p2;
    vector <int> p3;
    int p4;

    {
        // ----- test 0 -----
        int t0[] = {1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {2};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {5};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {1,2};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 0;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {1,2};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {2,3};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1,1};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {1,3};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 1;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {1,2};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {2,3};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1,1};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {1,2,3};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 0;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {10,8,3,7,2,6,9,1,4};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {5,5,8,10,5,5,6,10,3};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {71846,10951,42265,37832,29439,95676,83661,28186,21216};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {1,2,3,4,5,6,7,8,9,10};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 0;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {8,15,22,24,2,25,13,26,18,4,9,29,1,12,3,16,14,21,19,27,17,7,20,10,30,11,6,5,23};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {28,28,8,8,28,28,25,2,13,24,24,22,22,29,4,22,8,4,1,24,21,14,18,16,13,21,14,1,25};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {79374,40629,43195,73589,24200,63937,35339,7598,65109,51764,11142,84017,51078,58051,81387,22035,34883,92710,52283,57337,79309,3383,41904,35839,38242,43208,82062,24676,71838};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {3,5,7,9,10,14,17,19,20,21,24,25,28};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 107013;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        int t0[] = {34,14,22,9,24,19,11,37,33,21,5,30,1,43,7,31,45,27,6,12,13,35,23,47,49,50,26,40,16,10,48,25,29,15,28,46,4,20,44,17,39,32,38,2,42,8,36,3,41};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {18,18,18,14,9,34,9,24,34,11,18,14,21,21,43,1,22,7,1,30,14,33,13,18,9,5,1,1,26,19,50,33,50,40,29,48,50,37,16,40,48,14,30,22,47,37,7,50,6};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {22051,11109,85275,6691,43705,47374,27748,5411,62549,84079,89542,38006,82198,24083,16847,66335,3542,72495,37378,73973,85703,51682,68688,94295,31337,90071,99317,63484,43244,99079,55857,34503,79709,82140,91137,27033,91599,61168,52345,49569,58919,38133,43361,40718,2115,79278,88841,40966,42023};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        int t3[] = {5,12,13,18,23,27,28,29,32,33,34,35,36,37,40,42,43,47,48,49,50};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 89342;
        all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
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
