#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define eps (1e-9)
#define oo (1<<30)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define N 150
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}


int A[N], P[N], sz;

void criba() {
	f(i,2,N) {
		if (!A[i]) A[P[++sz] = i] = sz;
		for (int j = 1; j <= A[i] && P[j]*i < N; j++) A[P[j] * i] = j;
	}
}

int caso;
int tc;
int n,k;
int a[20], b[20], aux[20];
int mn;
ll barre[150];
int solu;
ll used;
void solve(int pos, int cota, int s = 0) {
	if (pos == -1) {
//		if (s == 541 && !solu) {
//			solu = 1;
//			adebug(aux,n);
//		}
		mini(mn, s);
		return;
	}
//	if(pos + ones(used) > 35) return;
	f(x,b[pos],cota+1) if ( (barre[x] & used)==0 ){
//		if (pos == n-1) debug(x);
//		vint indices;
//		f(i,0,36) if (barre[x]&(1LL<<i)) indices.pb(i);

//		f(i,0,indices.size()) forb[indices[i]]++;
		used |= barre[x];
//		int cnt = 0;
//		f(i,0,36) if (forb[i] == 0) cnt++;
//		if (cnt+1 < pos) goto aki;
		aux[pos] = x;
		solve(pos-1, x, s + x-b[pos]);
//aki:;
//		f(i,0,indices.size()) forb[indices[i]]--;
		used = used & (~barre[x]);
	}
}

int main(){
	criba();
	barre[0] = (1LL<<36)-1;
	barre[1] = 0;
	f(x,2,150) {
		ll &mm = barre[x] = 0;
		int z = x;
		while(z>1) {
			mm |= 1LL<<A[z];
			int p = P[A[z]];
			while(z%p == 0) z/=p;
		}
	}
//	f(i,1,5) cout << barre[i] << " "; cout << endl;
	cin >> tc;
	while(tc--) {
		cin >> n >> k;
		f(i,0,n) cin >> a[i];
		int sumar = 0;
		f(i,0,n) b[i] = (a[i]+k-1)/k;
		f(i,0,n) sumar += b[i]*k - a[i];

		sort(b, b + n);


		int bajo = 0;
		f(i,0,n) {
			bajo = *lower_bound(P,P+35,max(bajo+1,b[i]));
		}
//		debug(bajo);
		mn = oo;
		used = 0;
		solve(n-1, min(127,bajo));
		printf("Case #%d: %d\n", ++caso, mn*k + sumar);
//		debug(mn);
	}
}



