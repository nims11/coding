#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 52;
const int INF = (int) 1e5;

const int debug = false;


int n, K, weight[MAXN], totalWeightInside[MAXN][MAXN][MAXN], memo[MAXN][MAXN][MAXN];

struct point {
	int x, y;
	point(int x, int y) : x(x), y(y) {}
};

vector<point> a;

long long area(point a, point b, point c) {
	return a.x * (long long) (b.y - c.y) + b.x * (long long) (c.y - a.y) + c.x * (long long) (a.y - b.y);
}

int liesInside(point d, point a, point b, point c) {
	long long A = area(a, b, c);
	long long A1 = area(a, b, d);
	long long A2 = area(a, c, d);
	long long A3 = area(b, c, d);
	return (abs(A) == abs(A1) + abs(A2) + abs(A3));
}

int liesLeftSide(point c, point a, point b) {
	return area(a, b, c) > 0;
}

void sortIt(vector<int> &order, int idx) {
	for (int i = 0; i < order.size(); i++) {
		for (int j = i + 1; j < order.size(); j++) {
			int id1 = order[i];
			int id2 = order[j];
			if (liesLeftSide(a[id1], a[idx], a[id2])) {
				swap(order[i], order[j]);
			} 	
		}
	}
}

// dp
int p1;
vector<int> order;

// dp[p3][p2][k] is as defined in the editorial: 
int dp(int p3, int p2, int k) {
	int &res = memo[p3][p2][k];
	
	if (res == -1) {	
		if (k == 0) {
			res = 0;
		} else {
			res = (int) 1e9;
			
			// iterate over all counter clockwise points which lies to left of points indexed by p2, p3.
			for (int i = p3 + 1; i < order.size(); i++) {
				int id = order[i];
				int p2Id = order[p2];
				int p3Id = order[p3];
				
				if (liesLeftSide(a[id], a[p2Id], a[p3Id])) {
					int t = totalWeightInside[p1][id][p3Id] - weight[p1] - weight[p3Id];
					
					res = min(res, dp(i, p3, k - 1) + t);
				}
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	assert(n >= 3 && n <= 50);
	
	for (int i = 0; i < n; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		
		assert(x >= -INF && x <= INF);
		assert(y >= -INF && y <= INF);
		assert(wt >= 1 && wt <= INF);
		
		a.push_back(point(x, y));
		weight[i] = wt;
	}
	
	// check non collinearty condition
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i == j || i == k || j == k) {
					continue;
				}
				assert(area(a[i], a[j], a[k]) != 0);
			}
		}
	}
	
	// calculate total weight in the triangles
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					if (i == j || i == k || j == k) {
						continue;
					}
					if (liesInside(a[l], a[i], a[j], a[k])) {
						totalWeightInside[i][j][k] += weight[l];
					}
				}
			}
		}
	}
	
	vector<int> ans(n + 1, (int) 1e9);

	for (p1 = 0; p1 < n; p1++) {
		// select points lying above point p1 (i.e. having larger or equal y coordinates)
		order.clear();
		for (int j = 0; j < n; j++) {
			if (j != p1 && a[j].y >= a[p1].y) {
				order.push_back(j);
			}
		}
		sortIt(order, p1);
		
		memset(memo, -1, sizeof(memo));
		
		vector<int> cur_ans(n + 1, (int) 1e9);
		for (int p2 = 0; p2 < order.size(); p2++) {
			for (int p3 = p2 + 1; p3 < order.size(); p3++) {
				for (int k = 3; k <= n; k++) {
					int t = dp(p3, p2, k - 3);
					int p2Id = order[p2];
					int p3Id = order[p3];
					
					cur_ans[k] = min(cur_ans[k], dp(p3, p2, k - 3) + totalWeightInside[p1][p2Id][p3Id]);	
				}
			}
		}
		
		for (int k = 3; k <= n; k++) {
			ans[k] = min(ans[k], cur_ans[k]);
		}
	}
	
	for (int k = 3; k <= n; k++) {
		if (ans[k] >= (int) 1e9) {
			ans[k] = -1;
		}
		cout << ans[k];
		if (k != n) {
			cout << " ";
		}
	}
	cout << endl;

	return 0;
}

