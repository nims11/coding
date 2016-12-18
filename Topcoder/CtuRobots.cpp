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


class CtuRobots {
public:
	double maxDist(int B, vector <int> cost, vector <int> cap) {
		map<int, pair<double, int> > dp[501];
		dp[0][0] = make_pair(0.0, 0);
		double ans = 0;
        vector<pair<int, int> > tmp;
        for(int i = 0;i<cost.size();i++)
            tmp.push_back(make_pair(cap[i], cost[i]));
        sort(tmp.begin(), tmp.end());
        for(int i = 0;i<tmp.size();i++)
            cost[i] = tmp[i].second, cap[i] = tmp[i].first;
		for(int i = 0;i<cost.size();i++){
			for(map<int, pair<double, int> >::iterator it = dp[i].begin(); it != dp[i].end(); it++){
				int prevCost = it->first;
				double prevDist = it->second.first;
				int prevCap = it->second.second;
				int curCost = prevCost + cost[i];
				if(curCost > B)continue;
				double curCap = cap[i] - prevDist;
				double donated = (prevCap - cap[i] + curCap - prevDist)/3.0;
				if(dp[i+1].count(curCost)){
					if(donated+prevDist+cap[i] > dp[i+1][curCost].first + dp[i+1][curCost].second)
						dp[i+1][curCost] = make_pair(donated+prevDist, cap[i]);
				}else
					dp[i+1][curCost] = make_pair(donated+prevDist, cap[i]),
				ans = max(ans, (cap[i]-(donated+prevDist))/2.0+donated+prevDist);
			}
		}
        return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, double p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
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
	cout << "}";
	cout << "]" << endl;
	CtuRobots *obj;
	double answer;
	obj = new CtuRobots();
	clock_t startTime = clock();
	answer = obj->maxDist(p0, p1, p2);
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
		res = fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
	vector <int> p1;
	vector <int> p2;
	double p3;
	
	{
	// ----- test 0 -----
	p0 = 100;
	int t1[] = {50,25};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0.6666666666666666;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 25;
	int t1[] = {23,5,8,20,15};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {108,30,42,100,94};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 55.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1382;
	int t1[] = {0,0,0,1000,1000,0,1000,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2039,4819,5923,1577,8749,9182,3652,4918};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 6503.238683127572;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 209;
	int t1[] = {185,130,109,1,45,117,127,13,2,37,6,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {93,5,278,4,20,54,93,213,103,5,225,32,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 190.48376771833563;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 9956;
	int t1[] = {3229,736,1325,2680,410,1227,1378,499,1525,1722,1262,2080,2581,1505,1019,480,3155,836,2697,616,136,2032,2345,3154,1953,1654,344,3079,1426,199,2857,1714,2952,996,1567,2674,2054,2110,949,2412,2148,1016,234,1932,1554,1943,1625,1266,258,2924,49,1693,3140,309,557,12,2760,227,2497,330,646,1935,3032,2671,2433,164,1472,3080,717,221,2483,1309,1174,12,917,2335,3086,148,64,189,2628,1660,2983,109,1920,2470};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {934850,214,15807606,2426,176520,1900009,1184867,40550,1774843,2953,77834310,7276,3139890,695,213862217,13,193864,189,557664,1206555,85133,381662,4887,115027,2186890,218075,1,2024,9,95244962,7,906,3485642,52962078,58645759,785706,303,18,189,819600,17528041,11616471,92719012,82351,12752,634,26122233,215485,58,5506810,101874,130429471,2,1,68966,76303,321766922,463,26,225,207,52,1739,246841,496,228,4749453,191,79,10560,1414194,7529,13,521935,1,2,11590618,4020,105,3,28,3,2855,189909573,1,295052};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2.1034261053998655E8;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 8852;
	int t1[] = {2547,912,2592,1085,296,523,2257,2347,1822,261,334,2159,528,2739,201,964,427,2038,26,2361,234,2063,2885,2178,2708,730,2902,326,306,2794,1725,13,137,2169,388,1124,1464,2120,2357,1544,2794,2260,185,650,2852,124,1767,453,1331,1397,1991,1166,413,1428,2862,1194,1139,571,1299,1232,267,2027,746,1971,2695,2586,185,1319,1088,2818,2604,1798,475,1252,1767,2277,545,601,2160,325,2749,1161,1172,1075,1925,2468,1596,1116,1558,2226,1302,796,775,1105,418,334,2872,1921,2830,2448,2914,2634,1386,2516,492,1029,1134,2934,2017,1741,1675,2593,2233,2401,68,683,2053,155,183,923,2276,1823,65,2290,2448,92,2468,819,837,303,1440,705,291,2348,2562,765,1926,14,2514,2403,2671,1143,1358,121,376,2874,2447,1769,1686,967,967,2492,2472,2014,1686,2291,1093,1801,818};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {263268,256181,476791,365614,265352,19307,243180,84909,98175,367524,241474,479623,277638,111229,155356,415525,234382,97870,451466,58375,268277,404582,484789,458230,529286,449840,103208,199505,319373,294746,78005,326456,14418,257144,135669,238651,411723,99122,20421,298154,278407,153564,24778,73065,110408,392693,510192,362399,333830,125893,130946,345134,261418,230632,306751,451242,175675,459988,150787,349338,134594,255227,263645,180770,436965,502871,242085,318340,220576,189202,395789,390659,101649,337117,440471,466547,513054,316694,30382,38826,472506,67698,223953,397305,325564,57949,194651,443500,443188,431386,220061,400640,286085,189461,324214,171813,420711,260549,426526,208052,83343,429483,366076,52443,224742,333286,544259,335276,93282,326772,82841,225256,270357,547610,397526,193336,182374,439866,255860,111363,509167,228847,218257,39438,212242,378338,88972,127544,59230,428847,155553,116333,255176,396356,223463,226360,38283,6238,173455,447707,332111,60485,398523,462205,55397,148417,529738,460063,177715,404809,336155,50750,24165,530386,394811,512481,230296,45797,370008};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 408339.73124862404;
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
